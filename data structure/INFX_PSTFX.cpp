#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

//convert infix to postfix

// Function to check if the character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1; // for operands
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            // If the character is an alphanumeric operand, append to the postfix expression
            postfix += c;
        } else if (c == '(') {
            // If the character is an opening parenthesis, push it onto the stack
            s.push(c);
        } else if (c == ')') {
            // If the character is a closing parenthesis, pop and append operators from the stack
            // until an opening parenthesis is encountered
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the opening parenthesis
        } else if (isOperator(c)) {
            // If the character is an operator, pop and append operators from the stack
            // while they have equal or higher precedence than the current operator
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop and append remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    // Input infix expression from the user
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);

    // Output the postfix expression
    cout << "Postfix Expression: " << postfixExpression << endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstring>
using namespace std;

// evaluaton of postfix expression
double compute(char symbol, double op1, double op2) {
    switch (symbol) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        case '$':
        case '^':
            return pow(op1, op2);
        default:
            return 0;
    }
}

int main() {
    double s[20], res, op1, op2;
    int top = -1;
    char postfix[20], symbol;

    cout << "\nEnter the postfix expression:\n";
    cin.getline(postfix, sizeof(postfix));

    for (size_t i = 0; i < strlen(postfix); i++) {
        symbol = postfix[i];
        if (isdigit(symbol)) {
            s[++top] = symbol - '0';
        } else {
            op2 = s[top--];
            op1 = s[top--];
            res = compute(symbol, op1, op2);
            s[++top] = res;
        }
    }

    res = s[top--];
   cout << "\nThe result is: " << res <<endl;

    return 0;
}

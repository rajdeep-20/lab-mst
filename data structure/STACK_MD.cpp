#include <iostream>
using namespace std;

#define MAX 4

int stack[MAX], item;
int ch, top = -1, count = 0, status = 0;

void push(int stack[], int item)
{
    if (top == (MAX - 1))
        cout << "\n\nStack is Overflow";
    else
    {
        stack[++top] = item;
        status++;
    }
}

int pop(int stack[])
{
    int ret = 0;
    if (top == -1)
        cout << "\n\nStack is Underflow";
    else
    {
        ret = stack[top--];
        status--;
        cout << "\nPopped element is " << ret;
        // return ret;
    }
}

void palindrome(int stack[])
{
    int i, temp;
    temp = status;
    for (i = 0; i < temp; i++)
    {
        if (stack[i] == pop(stack))
            count++;
    }
    if (temp == count)
        cout << "\nStack contents are Palindrome";
    else
        cout << "\nStack contents are not Palindrome";
}

void display(int stack[])
{
    int i;
    cout << "\nThe stack contents are:";
    if (top == -1)
        cout << "\nStack is Empty";
    else
    {
        for (i = top; i >= 0; i--)
            cout << "\n ------\n| " << stack[i] << " |";
        cout << "\n";
    }
}

int main()
{
    do
    {
        cout << "\n\n----MAIN MENU--- \n";
        cout << "1. PUSH (Insert) in the Stack\n";
        cout << "2. POP (Delete) from the Stack\n";
        cout << "3. PALINDROME check using Stack\n";
        cout << "4. Exit (End the Execution)\n";
        cout << "Enter Your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter an element to be pushed: ";
            cin >> item;
            push(stack, item);
            display(stack);
            break;
        case 2:
            pop(stack);
            display(stack);
            break;
        case 3:
            palindrome(stack);
            break;
        case 4:
            cout << "\nExiting program.\n";
            break;
        default:
            cout << "\nInvalid choice. Please enter a valid option.\n";
        }
    } while (ch != 4);

    return 0;
}

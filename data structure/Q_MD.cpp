#include <iostream>
using namespace std;

//circular queue

#define MAX 4

int ch, front = 0, rear = -1, count = 0;
char q[MAX], item;

void insert() {
    if (count == MAX)
        cout << "\nQueue is Full";
    else {
        cout << "\nEnter the character/item to be inserted: ";
        cin >> item;
        rear = (rear + 1) % MAX;
        q[rear] = item;
        count++;
    }
}

void del() {
    if (count == 0)
        cout << "\nQueue is Empty";
    else {
        item = q[front];
        cout << "\nDeleted item is: " << item;
        front = (front + 1) % MAX;
        count--;
    }
}

void display() {
    int i, f = front, r = rear;
    if (count == 0)
        cout << "\nQueue is Empty";
    else {
        cout << "\nContents of Queue are:\n";
        for (i = 0; i < count; i++) {
            cout << q[f] << "\t";
            f = (f + 1) % MAX;
        }
    }
}

int main() {
    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit";
        cout << "\nEnter the choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                cout << "\nInvalid choice";
        }
    } while (ch != 4);

    return 0;
}

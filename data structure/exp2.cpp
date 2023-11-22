#include <iostream>

using namespace std;

int a[4], n, elem, i, pos;

/* Function Prototype and Definitions */
void create() // creating an array
{
    cout << "\nEnter the size of the array elements: ";
    cin >> n;

    cout << "\nEnter the elements for the array:\n";
    for (i = 0; i < n; i++)
        cin >> a[i];
} // end of create()

void display() // displaying array elements
{
    cout << "\nThe array elements are:\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
    }
    cout << endl;
} // end of display()

void insert() // inserting an element into an array
{
    cout << "\nEnter the position for the new element: ";
    cin >> pos;

    cout << "\nEnter the element to be inserted: ";
    cin >> elem;

    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos] = elem;

    n = n + 1;
} // end of insert()

void del() // deleting an array element
{
    cout << "\nEnter the position of the element to be deleted: ";
    cin >> pos;
    elem = a[pos];

    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
    cout << "\nThe deleted element is = " << elem << endl;
} // end of delete()

int main()
{
    int ch;

    do
    {
        cout << "\n\n--------Menu----------\n";
        cout << "1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\n   ";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert();
            break;
        case 4:
            del();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nInvalid choice:\n";
            break;
        }
    } while (ch != 5);

    return 0;
}

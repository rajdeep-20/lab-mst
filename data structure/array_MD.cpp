#include <stdio.h>
#include <conio.h>

/* Global variables declaration */
int a[50], n, elem, i, pos; // increased array size for flexibility

/* Function Prototypes */
void create();  // creating an array
void display(); // displaying array elements
void insert();  // inserting an element into an array
void del();     // deleting an array element

int main()
{
    int ch;

    do
    {
        printf("\n\n--------Menu---------- \n");
        printf("1. Create\n 2. Display\n 3. Insert\n 4. Delete\n 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

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
            printf("\nExiting program.\n");
            break;
        default:
            printf("\nInvalid choice. Please enter a valid option.\n");
        }
    } while (ch != 5);

    getch();
    return 0;
}

void create()
{
    printf("\nEnter the size of the array elements: ");
    scanf("%d", &n);
    printf("\nEnter the elements for the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void display()
{
    printf("\nThe array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
}

void insert()
{
    printf("\nEnter the position for the new element: ");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &elem);

    for (i = n - 1; i >= pos; i--)
    {
        a[i + 1] = a[i];
    }

    a[pos] = elem;
    n = n + 1;
}

void del()
{
    printf("\nEnter the position of the element to be deleted: ");
    scanf("%d", &pos);
    elem = a[pos];

    for (i = pos; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    n = n - 1;
    printf("\nThe deleted element is = %d", elem);
}

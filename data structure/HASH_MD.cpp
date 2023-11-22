#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

//hash function

#define MAX 10

struct employee
{
    int id;
    char name[15];
};

typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];

int create(int num)
{
    int key;
    key = num % 100;
    return key;
}

int getemp(EMP emp[], int key)
{
    cout << "\nEnter emp id: ";
    cin >> emp[key].id;
    cout << "\nEnter emp name: ";
    cin.ignore();
    cin.getline(emp[key].name, 15);
    return key;
}

void display()
{
    int i, ch;
    cout << "\n1.Display ALL\n2.Filtered Display";
    cout << "\nEnter the choice: ";
    cin >> ch;

    if (ch == 1)
    {
        cout << "\nThe hash table is:\n";
        cout << "\nHTKey\tEmpID\tEmpName";
        for (i = 0; i < MAX; i++)
            cout << "\n" << i << "\t" << emp[i].id << "\t" << emp[i].name;
    }
    else
    {
        cout << "\nThe hash table is:\n";
        cout << "\nHTKey\tEmpID\tEmpName";
        for (i = 0; i < MAX; i++)
        {
            if (a[i] != -1)
            {
                cout << "\n" << i << "\t" << emp[i].id << "\t" << emp[i].name;
                continue;
            }
        }
    }
}

void linear_prob(int key, int num)
{
    int flag, i, count = 0;
    flag = 0;

    if (a[key] == -1)
    {
        a[key] = getemp(emp, key);
    }
    else
    {
        cout << "\nCollision Detected...!!!\n";
        i = 0;

        while (i < MAX)
        {
            if (a[i] != -1)
                count++;
            i++;
        }

        i++;

        cout << "\nCollision avoided successfully using LINEAR PROBING\n";

        if (count == MAX)
        {
            cout << "\n Hash table is full";
            display();
            exit(1);
        }
        else
        {
            getemp(emp, key + 1);

            for (i = key; i < MAX; i++)
            {
                if (a[i] == -1)
                {
                    a[i] = num;
                    flag = 1;
                    break;
                }
            }

            i = 0;

            while ((i < key) && (flag == 0))
            {
                if (a[i] == -1)
                {
                    a[i] = num;
                    flag = 1;
                    break;
                }
                i++;
            } // end while
        }     // end else
    }         // end linear_prob()
}

int main()
{
    int num, key, i;
    int ans = 1;

    cout << "\nCollision handling by linear probing: ";
    for (i = 0; i < MAX; i++)
    {
        a[i] = -1;
    }

    do
    {
        cout << "\nEnter the data: ";
        cin >> num;
        key = create(num);
        linear_prob(key, num);
        cout << "\nDo you wish to continue? (1/0): ";
        cin >> ans;
    } while (ans);

    display();

    return 0;
}

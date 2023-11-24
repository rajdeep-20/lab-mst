// (Exp-10)

// AIM: Simulate the Bankers algorithm for deadlock avoidance and deadlock prevention.

// CODE:-

#include <iostream>
using namespace std;

const int MAX = 20;

class Bankers
{
private:
    int al[MAX][MAX], m[MAX][MAX], n[MAX][MAX], avail[MAX];
    int nop, nor, k, result[MAX], pnum, work[MAX], finish[MAX];

public:
    Bankers();
    void input();
    void method();
    int search(int);
    void display();
};

Bankers::Bankers()
{
    k = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            al[i][j] = 0;
            m[i][j] = 0;
            n[i][j] = 0;
        }
        avail[i] = 0;
        result[i] = 0;
        finish[i] = 0;
    }
}

void Bankers::input()
{
    int i, j;

    cout << "Enter the number of processes:";
    cin >> nop;
    cout << "Enter the number of resources:";
    cin >> nor;

    cout << "Enter the allocated resources for each process:" << endl;
    for (i = 0; i < nop; i++)
    {
        cout << "\nProcess " << i;
        for (j = 0; j < nor; j++)
        {
            cout << "\nResource " << j << ":";
            cin >> al[i][j];
        }
    }

    cout << "Enter the maximum resources that are needed for each process:" << endl;
    for (i = 0; i < nop; i++)
    {
        cout << "\nProcess " << i;
        for (j = 0; j < nor; j++)
        {
            cout << "\nResource " << j << ":";
            cin >> m[i][j];
            n[i][j] = m[i][j] - al[i][j];
        }
    }

    cout << "Enter the currently available resources in the system: ";
    for (j = 0; j < nor; j++)
    {
        cout << "Resource " << j << ":";
        cin >> avail[j];
        work[j] = -1;
    }

    for (i = 0; i < nop; i++)
        finish[i] = 0;
}

void Bankers::method()
{
    int i = 0, j, flag;

    while (1)
    {
        if (finish[i] == 0)
        {
            pnum = search(i);
            if (pnum != -1)
            {
                result[k++] = i;
                finish[i] = 1;
                for (j = 0; j < nor; j++)
                {
                    avail[j] = avail[j] + al[i][j];
                }
            }
        }
        i++;
        if (i == nop)
        {
            flag = 0;
            for (j = 0; j < nor; j++)
                if (avail[j] != work[j])
                    flag = 1;
            for (j = 0; j < nor; j++)
                work[j] = avail[j];
            if (flag == 0)
                break;
            else
                i = 0;
        }
    }
}

int Bankers::search(int i)
{
    int j;

    for (j = 0; j < nor; j++)
        if (n[i][j] > avail[j])
            return -1;
    return 0;
}

void Bankers::display()
{
    int i, j;

    cout << endl
         << "OUTPUT:";
    cout << endl
         << "========";
    cout << endl
         << "PROCESS\t     ALLOCATED\t     MAXIMUM\t     NEED";

    for (i = 0; i < nop; i++)
    {
        cout << "\nP" << i + 1 << "\t     ";
        for (j = 0; j < nor; j++)
        {
            cout << al[i][j] << "  ";
        }
        cout << "\t     ";
        for (j = 0; j < nor; j++)
        {
            cout << m[i][j] << "  ";
        }
        cout << "\t";
        for (j = 0; j < nor; j++)
        {
            cout << n[i][j] << "  ";
        }
    }

    cout << "\nThe sequence of the safe processes are: \n";
    for (i = 0; i < k; i++)
    {
        int temp = result[i] + 1;
        cout << "P" << temp << " ";
    }

    cout << "\nThe sequence of unsafe processes are: \n";
    int flg = 0;
    for (i = 0; i < nop; i++)
    {
        if (finish[i] == 0)
        {
            flg = 1;
        }
        cout << "P" << i << " ";
    }

    cout << endl
         << "RESULT:";
    cout << endl
         << "=======";

    if (flg == 1)
        cout << endl
             << "The system is not in a safe state, and deadlock may occur!!";
    else
        cout << endl
             << "The system is in a safe state, and deadlock will not occur!!";
}

int main()
{
    cout << " DEADLOCK BANKER’S ALGORITHM " << endl;
    Bankers B;
    B.input();
    B.method();
    B.display();

    return 0;
}
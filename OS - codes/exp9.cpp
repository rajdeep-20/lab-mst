// OS(Exp - 9)
//
// AIM : -Simulation of Round Robin CPU scheduling algorithm.Code : -

#include <iostream>
using namespace std;

struct process
{
    int no;
    int at, et, wt, tt;
    int tet;
    int t;
};

int main()
{
    process p[99];
    int i, j, k;

    cout << "\n Enter No of Processes:";
    int np;
    cin >> np;

    for (i = 0; i < np; i++)
    {
        cout << "\n Enter Execution time of process " << i + 1 << ":";
        cin >> p[i].et;
        p[i].tet = p[i].et;
        p[i].at = p[i].t = p[i].tt = p[i].wt = 0;
        p[i].no = i + 1;
    }

    cout << "\n Enter Time Quantum:";
    int q;
    cin >> q;

    cout << "\n Entered Data";
    cout << "\nProcess ExecutionTime";

    for (i = 0; i < np; i++)
    {
        cout << "\n " << p[i].no << "\t" << p[i].et;
    }

    int totaltime = 0;
    for (i = 0; i < np; i++)
    {
        totaltime += p[i].et;
    }

    i = 0;
    k = 0;
    int rrg[99];

    for (j = 0; j < totaltime; j++)
    {
        if ((k == 0) && (p[i].et != 0))
        {
            p[i].wt = j;
            if (p[i].t != 0)
            {
                p[i].wt -= q * p[i].t;
            }
        }
        if ((p[i].et != 0) && (k != q))
        {
            rrg[j] = p[i].no;
            p[i].et -= 1;
            k++;
        }
        else
        {
            if ((k == q) && (p[i].et != 0))
            {
                p[i].t += 1;
            }
            i = i + 1;
            if (i == np)
            {
                i = 0;
            }
            k = 0;
            j = j - 1;
        }
    }

    int twt = 0;
    int ttt = 0;

    cout << "\n \t\tResult Of Round Robin";
    cout << "\n Processes\tExecution Time\tWaiting Time\tTurnaround Time";

    for (i = 0; i < np; i++)
    {
        p[i].tt = p[i].wt + p[i].tet;
        ttt += p[i].tt;
        twt += p[i].wt;
        cout << "\n " << p[i].no << "\t" << p[i].tet << "\t" << p[i].wt << "\t" << p[i].tt;
    }

    cout << "\n Average Waiting Time: " << (float)twt / np;
    cout << "\n Average Turnaround Time: " << (float)ttt / np;

    return 0;
}

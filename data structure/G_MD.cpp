#include <iostream>
using namespace std;
// graph

int a[10][10], n, m, i, j, source, s[10], b[10];
int visited[10];

void create()
{
    cout << "\nEnter the number of vertices of the digraph: ";
    cin >> n;
    cout << "\nEnter the adjacency matrix of the graph:\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> a[i][j];
}

void bfs()
{
    int q[10], u, front = 0, rear = -1;
    cout << "\nEnter the source vertex to find other nodes reachable or not: ";
    cin >> source;
    q[++rear] = source;
    visited[source] = 1;
    cout << "\nThe reachable vertices are: ";
    while (front <= rear)
    {
        u = q[front++];
        for (i = 1; i <= n; i++)
        {
            if (a[u][i] == 1 && visited[i] == 0)
            {
                q[++rear] = i;
                visited[i] = 1;
                cout << "\n"
                     << i;
            }
        }
    }
}

void dfs(int source)
{
    int v, top = -1;
    s[++top] = 1;
    b[source] = 1;
    for (v = 1; v <= n; v++)
    {
        if (a[source][v] == 1 && b[v] == 0)
        {
            cout << "\n"
                 << source << " -> " << v;
            dfs(v);
        }
    }
}

int main()
{
    int ch;
    while (1)
    {
        cout << "\n1.Create Graph\n2.BFS\n3.Check graph connected or not(DFS)\n4.Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            bfs();
            for (i = 1; i <= n; i++)
                if (visited[i] == 0)
                    cout << "\nThe vertex that is not reachable " << i;
            break;
        case 3:
            cout << "\nEnter the source vertex to find the connectivity: ";
            cin >> source;
            m = 1;
            dfs(source);
            for (i = 1; i <= n; i++)
            {
                if (b[i] == 0)
                    m = 0;
            }
            if (m == 1)
                cout << "\nGraph is Connected";
            else
                cout << "\nGraph is not Connected";
            break;
        default:
            exit(0);
        }
    }
    return 0;
}

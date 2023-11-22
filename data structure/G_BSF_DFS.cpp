#include <iostream>
#include <queue>
#define MAX_NODES 100
struct Node
{
    int data;
    Node *next;
};

struct Graph
{
    int numNodes;
    Node *adjacencyList[MAX_NODES];
    int visited[MAX_NODES];
};

void initGraph(Graph *graph, int numNodes)
{
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++)
    {
        graph->adjacencyList[i] = nullptr;
        graph->visited[i] = 0;
    }
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = new Node;
    newNode->data = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void BFS(Graph *graph, int startNode)
{
    std::queue<int> q;

    // Enqueue the start node
    q.push(startNode);
    graph->visited[startNode] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        std::cout << current << " ";

        // Explore adjacent nodes
        Node *temp = graph->adjacencyList[current];
        while (temp != nullptr)
        {
            int neighbor = temp->data;
            if (!graph->visited[neighbor])
            {
                q.push(neighbor);
                graph->visited[neighbor] = 1;
            }
            temp = temp->next;
        }
    }
}

// Depth-First Search
void DFS(Graph *graph, int startNode)
{
    std::cout << startNode << " ";
    graph->visited[startNode] = 1;

    // Explore adjacent nodes
    Node *temp = graph->adjacencyList[startNode];
    while (temp != nullptr)
    {
        int neighbor = temp->data;
        if (!graph->visited[neighbor])
        {
            DFS(graph, neighbor);
        }
        temp = temp->next;
    }
}

int main()
{
    Graph graph;
    int numNodes = 6;

    initGraph(&graph, numNodes);

    // Adding edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);

    std::cout << "BFS starting from node 0: ";
    BFS(&graph, 0);

    // Reset visited array
    for (int i = 0; i < numNodes; i++)
    {
        graph.visited[i] = 0;
    }
    std::cout << "\nDFS starting from node 0: ";
    DFS(&graph, 0);

    return 0;
}
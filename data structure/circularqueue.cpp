#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue
{
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    CircularQueue() : front(-1), rear(-1)
    {
        for (int i = 0; i < MAX_SIZE; i++)
            arr[i] = 0;
    }

    bool isFull()
    {
        return (front == (rear + 1) % MAX_SIZE);
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        else if (isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        arr[rear] = val;
        cout << val << " enqueued to the queue." << endl;
    }

    void dequeue()
    {
        int data = 0;
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        else if (front == rear)
        {
            data = arr[front];
            front = rear = -1;
        }
        else
        {
            data = arr[front];
            front = (front + 1) % MAX_SIZE;
        }
        cout << data << " dequeued from the queue." << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << arr[rear] << endl;
    }
};

int main()
{
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);

    cq.display();

    return 0;
}

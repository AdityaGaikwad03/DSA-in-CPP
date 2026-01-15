
// Experiment No.4
// Title: Implement queue using arrays with enqueue, dequeue and display
// operations.
// Objective: The objective is to implement a simple FIFO data structure using a fixedsize array with enqueue, dequeue, and display operations while managing overflow
// and underflow conditions.
// Program:
#include <iostream>
using namespace std;
class Queue
{
    int front, rear, capacity;
    int *arr;

public:
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }
    ~Queue()
    {
        delete[] arr;
    }
    bool isFull()
    {
        return rear == capacity - 1;
    }
    bool isEmpty()
    {
        return front == -1 || front > rear;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue overflow. Cannot insert " << val << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        arr[++rear] = val;
        cout << val << " enqueued to queue." << endl;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow. No element to dequeue." << endl;
            return;
        }
        cout << arr[front++] << " dequeued from queue." << endl;
        if (front > rear)
        {
            front = rear = -1; // Reset when queue gets empty
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    int size;
    cout << "Enter queue capacity: ";
    cin >> size;
    Queue q(size);
    int choice, val;
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
        }
    } while (choice != 4);
    return 0;
}
// Output:
// Enter queue capacity: 10
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter choice: 1
// Enter value to enqueue: 89
// 89 enqueued to queue.
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter choice: 1
// Enter value to enqueue: 23
// 23 enqueued to queue.
// 1. Enqueue
// Data Structures and algorithm
// Department of Computer application
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter choice: 3
// Queue elements: 89 23

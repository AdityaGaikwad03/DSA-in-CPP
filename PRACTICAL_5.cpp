
// Experiment No.5
// Title: Implement circular queue using arrays.
// Objective: The objective of implementing a circular queue using arrays is to
// efficiently use fixed array space by allowing the front and rear pointers to wrap
// around. This enables continuous enqueue and dequeue operations without wasting
// space, ensuring constant time insertion and deletion while handling overflow and
// underflow conditions effectively.
// Program:
#include <iostream>
#include <vector>
using namespace std;
class CircularQueue
{
    int front, rear, capacity;
    int *arr;

public:
    CircularQueue(int size) : front(-1), rear(-1), capacity(size)
    {
        arr = new int[capacity];
    }
    CircularQueue() { delete[] arr; }
    bool isFull() { return front == (rear + 1) % capacity; }
    bool isEmpty() { return front == -1; }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Overflow: Cannot insert " << val << endl;
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % capacity;
        arr[rear] = val;
        cout << val << " enqueued." << endl;
        showCircle();
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow: No element to dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % capacity;
        showCircle();
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
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
    void showCircle()
    {
        cout << "\nQueue indices: ";
        for (int i = 0; i < capacity; i++)
            cout << i << " ";
        cout << "\nQueue view: ";
        vector<char> vis(capacity, '_');
        if (!isEmpty())
        {
            for (int i = front;; i = (i + 1) % capacity)
            {
                vis[i] = 'E';
                if (i == rear)
                    break;
            }
        }
        for (char c : vis)
            cout << c << " ";
        cout << "\nFront: " << front << ", Rear: " << rear << "\n\n";
    }
};
int main()
{
    int size, choice, val;
    cout << "Enter queue capacity: ";
    cin >> size;
    CircularQueue cq(size);
    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Value: ";
            cin >> val;
            cq.enqueue(val);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exit.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);
    return 0;
}
// Output:
// Enter queue capacity: 3
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Choice: 1
// Value: 89
// 89 enqueued.
// Queue indices: 0 1 2
// Queue view: E _ _
// Front: 0, Rear: 0
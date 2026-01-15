
// Experiment No.2
// Title: Implement stack using arrays with push, pop, peek and display
// operations.
// Objective: To demonstrate basic operations on a one-dimensional array such as
// adding, removing, finding, and displaying elements, enabling efficient data
// manipulation and understanding fundamental array handling concepts in C++
// programming.
// Program:
#include <iostream>
using namespace std;
#define MAX 100
class Stack
{
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x)
    {

        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack." << endl;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is: " << arr[top] << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements from top to bottom: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    Stack s;
    int choice, value;
    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.peek();
            break;
        case 4:
            s.display();
            break;
        case 5:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
    return 0;
}
// Output:
// Stack Operations Menu:
// 1. Push
// 2. Pop
// Data Structures and algorithm
// Department of Computer application
// 3. Peek
// 4. Display
// 5. Exit
// Enter choice: 1
// Enter value to push: 45
// 45 pushed to stack.
// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter choice: 3
// Top element is: 45
// Stack Operations Menu:
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 5. Exit
// Enter choice: 4
// Stack elements from top to bottom: 45

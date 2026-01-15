/* Write menu driven cpp code for Implement singly linked list with the following operations:- 1 Insert at beginning, 2 insert at end 3 insert at given position. 4 display */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position <= 1) {
        insertAtBeginning(head, value);
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
        temp = temp->next;
    if (temp == nullptr) {
        cout << "Position out of bounds. Inserting at end." << endl;
        insertAtEnd(head, value);
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int choice, value, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(head, value, pos);
                break;
            case 4:
                display(head);
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

/* OUTPUT :-


Menu:
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Display
5. Exit
Enter your choice: 1
Enter value to insert at beginning: 78

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Display
5. Exit
Enter your choice: 2
Enter value to insert at end: 65

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Display
5. Exit
Enter your choice: 1
Enter value to insert at beginning: 48

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Display
5. Exit
Enter your choice: 3
Enter value to insert: 2
Enter position: 62
Position out of bounds. Inserting at end.

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Display
5. Exit
Enter your choice: 4
48 -> 78 -> 65 -> 2 -> NULL

Menu:
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Display
5. Exit
Enter your choice: 48 -> 78 -> 65 -> 2 -> 

*/
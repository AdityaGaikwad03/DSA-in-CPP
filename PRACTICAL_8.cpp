#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node by value
void deleteNode(Node*& head, int key) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    Node* prev = nullptr;
    do {
        if (temp->data == key) {
            if (temp == head && temp->next == head) {
                delete head;
                head = nullptr;
            } else if (temp == head) {
                while (temp->next != head) temp = temp->next;
                temp->next = head->next;
                Node* toDelete = head;
                head = head->next;
                delete toDelete;
            } else {
                prev->next = temp->next;
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    cout << "Key not found." << endl;
}

// Function to display the list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Main function
int main() {
    Node* head = nullptr;

    // Insert elements
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    cout << "Circular Linked List: ";
    displayList(head);

    // Delete an element
    deleteNode(head, 20);
    cout << "After deleting 20: ";
    displayList(head);

    return 0;
}
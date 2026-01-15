/* implement doubly linked lidt with insertion, deletion, and transversal operation in both direction */

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

// Insert at end
void insertEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete by value
void deleteNode(int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) return; // Not found
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    delete temp;
}

// Traverse forward
void traverseForward() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Traverse backward
void traverseBackward() {
    Node* temp = head;
    if (!temp) return;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    cout << "Forward: ";
    traverseForward();
    cout << "Backward: ";
    traverseBackward();

    deleteNode(20);
    cout << "After deletion (forward): ";
    traverseForward();
    cout << "After deletion (backward): ";
    traverseBackward();

    return 0;
}

/* output :- 
    Forward: 10 20 30 
Backward: 30 20 10
After deletion (forward): 10 30
After deletion (backward): 30 10
*/
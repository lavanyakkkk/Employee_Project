#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// 1. Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// 2. Insert at the end
void insertAtEnd(int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// 3. Insert at beginning
void insertAtBeginning(int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// 4. Insert at a specific position
void insertAtPosition(int value, int position) {
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range\n";
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// 5. Delete from beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

// 6. Delete from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

// 7. Delete from specific position
void deleteFromPosition(int position) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    if (position == 1) {
        deleteFromBeginning();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of range\n";
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// 8. Search for an element
void searchElement(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Element found at position: " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Element not found\n";
}

// 9. Count nodes
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// 10. Display the list
void displayList() {
    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Main menu
int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtPosition(15, 3);

    displayList();

    cout << "Number of nodes: " << countNodes() << endl;

    searchElement(15);

    deleteFromBeginning();
    deleteFromEnd();
    deleteFromPosition(2);

    displayList();

    return 0;
}

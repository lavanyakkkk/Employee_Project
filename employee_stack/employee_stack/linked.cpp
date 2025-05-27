#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE* createNode();
NODE* addNodeBeg(NODE*, NODE*);
NODE* addNodeEnd(NODE*, NODE*);
int dispList(NODE*);
int dispMenu();
NODE* updateNode(NODE*, int, int);
NODE* deleteNode(NODE*, int);
void searchNode(NODE*, int);
void freeNodes(NODE*);

int main() {
    NODE* head = NULL;
    int ch = 1;
    while (ch) {
        switch (dispMenu()) {
        case 1:
            head = addNodeBeg(head, createNode());
            break;
        case 2:
            head = addNodeEnd(head, createNode());
            break;
        case 3:
            dispList(head);
            break;
        case 4: {
            int oldVal, newVal;
            cout << "Enter value to update: ";
            cin >> oldVal;
            cout << "Enter new value: ";
            cin >> newVal;
            head = updateNode(head, oldVal, newVal);
            break;
        }
        case 5: {
            int val;
            cout << "Enter value to search: ";
            cin >> val;
            searchNode(head, val);
            break;
        }
        case 6: {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            head = deleteNode(head, val);
            break;
        }
        case 7:
            ch = 0;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    freeNodes(head);
    cout << "Exiting program...." << endl;
    return 0;
}

int dispMenu() {
    int ch;
    cout << "\n--- Menu ---\n";
    cout << "1. Add Node at Beginning\n";
    cout << "2. Add Node at End\n";
    cout << "3. Display List\n";
    cout << "4. Update a Node\n";
    cout << "5. Search for a Node\n";
    cout << "6. Delete a Node\n";
    cout << "7. Exit\n";
    cout << "Choice: ";
    cin >> ch;
    return ch;
}

NODE* createNode() {
    NODE* nn = (NODE*)malloc(sizeof(NODE));
    cout << "Enter the value of node: ";
    cin >> nn->data;
    nn->next = NULL;
    return nn;
}

NODE* addNodeBeg(NODE* head, NODE* nn) {
    nn->next = head;
    head = nn;
    return head;
}

NODE* addNodeEnd(NODE* head, NODE* nn) {
    if (head == NULL)
        return nn;
    NODE* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = nn;
    return head;
}

int dispList(NODE* head) {
    cout << "List: ";
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
    return EXIT_SUCCESS;
}

NODE* updateNode(NODE* head, int oldVal, int newVal) {
    NODE* temp = head;
    bool found = false;
    while (temp != NULL) {
        if (temp->data == oldVal) {
            temp->data = newVal;
            found = true;
        }
        temp = temp->next;
    }
    if (found)
        cout << "Value updated successfully.\n";
    else
        cout << "Value not found.\n";
    return head;
}

void searchNode(NODE* head, int val) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == val) {
            cout << "Value " << val << " found at position " << pos << endl;
            return;
        }
        head = head->next;
        pos++;
    }
    cout << "Value " << val << " not found.\n";
}

NODE* deleteNode(NODE* head, int val) {
    NODE* temp = head;
    NODE* prev = NULL;

    while (temp != NULL) {
        if (temp->data == val) {
            if (prev == NULL) { // Deleting head
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            cout << "Node with value " << val << " deleted.\n";
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Value " << val << " not found. Cannot delete.\n";
    return head;
}

void freeNodes(NODE* head) {
    NODE* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

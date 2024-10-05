#include <iostream>
using namespace std;

const int SIZE = 7;

// the node structure
struct Node {
    float value;
    Node *next;
};

// the function prototypes
void output(Node *head);
Node* addToFront(Node *head, float value);
Node* addToTail(Node *head, float value);
Node* deleteNode(Node *head, int position);
Node* insertNode(Node *head, int position, float value);
Node* deleteEntireList(Node *head);

int main() {
    Node *head = nullptr;

    // creates the linked list
    for (int i = 0; i < SIZE; i++) {
        float tmp_val = rand() % 100;
        head = addToFront(head, tmp_val);
    }
    output(head);

    //function to ask the user for what note should be deleted
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);

    // function to ask the user for which node to insert 10000
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = insertNode(head, entry, 10000);
    output(head);

    //deletes the linkeed lsit
    head = deleteEntireList(head);
    output(head);

    return 0;
}

// function to add a node to the front of the linked list
Node* addToFront(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    return newNode;
}

// function to add a node to the end of the linked list
Node* addToTail(Node *head, float value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        return newNode;
    }

    Node *current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// function to delete a node at a specified position
Node* deleteNode(Node *head, int position) {
    if (!head || position <= 0) {
        return head; 
    }

    Node *current = head;
    if (position == 1) { 
        head = current->next;
        delete current;
        return head;
    }

    Node *prev = nullptr;
    for (int i = 1; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) {
        return head; 
    }

    prev->next = current->next;
    delete current;
    return head;
}

// function to insert a node after a specified position
Node* insertNode(Node *head, int position, float value) {
    Node *newNode = new Node;
    newNode->value = value;

    if (position == 0) { 
        newNode->next = head;
        return newNode;
    }

    Node *current = head;
    Node *prev = nullptr;
    for (int i = 0; current != nullptr && i < position; i++) {
        prev = current;
        current = current->next;
    }

    if (!prev) {
        delete newNode;
        return head; 
    }

    newNode->next = prev->next;
    prev->next = newNode;
    return head;
}

// function to delete the entire linked list
Node* deleteEntireList(Node *head) {
    Node *current = head;
    while (current) {
        Node *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    return nullptr;
}

// function to output the values in the linked list
void output(Node *head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

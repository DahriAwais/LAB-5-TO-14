#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position out of range!" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void display() {
        Node* current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int n, value, position;

    cout << "Enter the number of elements you want to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        cout << "Enter position: ";
        cin >> position;
        list.insertAtPosition(value, position);
        list.display();
    }

    return 0;
}

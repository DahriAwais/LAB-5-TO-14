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

    void insertSorted(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr || head->data >= data) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    int findLastNodePosition() {
        if (head == nullptr) {
            return -1;
        }

        Node* current = head;
        int position = 1;
        int lastPos = 1;

        while (current->next != nullptr) {
            current = current->next;
            lastPos++;
        }

        return lastPos;
    }

    void display() {
        Node* current = head;
        cout << "Sorted Linked List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int n, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        list.insertSorted(value);
    }

    list.display();
    int lastPos = list.findLastNodePosition();
    
    if (lastPos == -1) {
        cout << "The list is empty." << endl;
    } else {
        cout << "The location of the last node is: " << lastPos << endl;
    }

    return 0;
}

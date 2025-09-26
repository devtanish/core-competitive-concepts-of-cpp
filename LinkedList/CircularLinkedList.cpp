#include <iostream>
using namespace std;

struct Node {
    int Data;
    Node* Next;
    Node(int data) : Data(data), Next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* end;

public:
    List() : head(nullptr), end(nullptr) {}

    void push_front(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = end = newNode;
            end->Next = head; 
        } else {
            newNode->Next = head;
            head = newNode;
            end->Next = head;
        }
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = end = newNode;
            end->Next = head;
        } else {
            end->Next = newNode;
            end = newNode;
            end->Next = head;
        }
    }

    void pop_front() {
        if (!head) return;

        if (head == end) { 
            delete head;
            head = end = nullptr;
            return;
        }

        Node* temp = head;
        head = head->Next;
        end->Next = head;
        delete temp;
    }

    void pop_back() {
        if (!head) return;

        if (head == end) { 
            delete head;
            head = end = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->Next != end) {
            temp = temp->Next;
        }

        delete end;
        end = temp;
        end->Next = head;
    }

    bool search(int value) {
        if (!head) return false;
        Node* temp = head;
        do {
            if (temp->Data == value) return true;
            temp = temp->Next;
        } while (temp != head);
        return false;
    }

    int count() {
        if (!head) return 0;
        int cnt = 0;
        Node* temp = head;
        do {
            cnt++;
            temp = temp->Next;
        } while (temp != head);
        return cnt;
    }

    void insertAt(int pos, int data) {
        int n = count();
        if (pos <= 1) {
            push_front(data);
        } else if (pos > n) {
            push_back(data);
        } else {
            Node* newNode = new Node(data);
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->Next;
            }
            newNode->Next = temp->Next;
            temp->Next = newNode;
        }
    }

    void deleteValue(int value) {
        if (!head) return;

        if (head->Data == value) {
            pop_front();
            return;
        }

        Node* temp = head;
        while (temp->Next != head && temp->Next->Data != value) {
            temp = temp->Next;
        }

        if (temp->Next == head) return; 

        Node* toDelete = temp->Next;
        temp->Next = toDelete->Next;
        if (toDelete == end) end = temp;
        delete toDelete;
    }

    void printList() {
        if (!head) {
            cout << "Empty List" << endl;
            return;
        }
        Node* temp = head;
        cout << "[ ";
        do {
            cout << temp->Data << " ";
            temp = temp->Next;
        } while (temp != head);
        cout << "] (circular)" << endl;
    }

    ~List() {
        while (head) pop_front();
    }
};

int main() {
    List ll;

    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_front(1);
    ll.push_back(5);

    ll.printList();

    ll.pop_front();
    ll.pop_back();
    cout << "After popping front & back: ";
    ll.printList();

    ll.insertAt(2, 99);
    cout << "After insertAt(2,99): ";
    ll.printList();

    ll.deleteValue(3);
    cout << "After deleteValue(3): ";
    ll.printList();

    cout << "Search 99: " << (ll.search(99) ? "Found" : "Not Found") << endl;
    cout << "Count: " << ll.count() << endl;

    return 0;
}

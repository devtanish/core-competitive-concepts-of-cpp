#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* end;

public:
    List() : head(nullptr), end(nullptr) {}

    void push_Begin(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        if (!end) end = node; 
    }

    void push_end(int value) {
        Node* node = new Node(value);
        if (!head) {
            head = end = node;
            return;
        }
        end->next = node;
        end = node;
    }

    void pop_Begin() {
        if (!head) {
            cout << "Empty LinkedList..." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (!head) end = nullptr; 
        delete temp;
    }

    void pop_End() {
        if (!head) {
            cout << "Empty LinkedList..." << endl;
            return;
        }
        if (head == end) { 
            delete head;
            head = end = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next != end) {
            temp = temp->next;
        }
        delete end;
        end = temp;
        end->next = nullptr;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Print listk
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "Null" << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        end = head; 
        while (current) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    ~List() {
        while (head) {
            pop_Begin();
        }
    }
};

int main() {
    List ll;

    ll.push_end(1);
    ll.push_end(2);
    ll.push_end(3);
    ll.push_end(4);
    ll.push_end(5);
    ll.push_Begin(0);

    cout << "List after insertion: ";
    ll.print();

    ll.pop_Begin();
    ll.pop_End();

    cout << "After popping begin & end: ";
    ll.print();

    cout << "Count: " << ll.count() << endl;
    cout << "Search 3: " << (ll.search(3) ? "Found" : "Not Found") << endl;

    ll.reverse();
    cout << "After reverse: ";
    ll.print();

    return 0;
}

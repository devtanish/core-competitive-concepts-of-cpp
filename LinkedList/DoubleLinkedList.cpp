#include <iostream>
using namespace std;

struct Node {
    Node* prev;
    int data;
    Node* next;

    Node(int value) : prev(nullptr), data(value), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* end;

public:
    List() : head(nullptr), end(nullptr) {}

    void push_Begin(int value) {
        Node* node = new Node(value);
        if (!head) {
            head = end = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
    }

    void push_end(int value) {
        Node* node = new Node(value);
        if (!head) {
            head = end = node;
            return;
        }
        node->prev = end;
        end->next = node;
        end = node;
    }

    void insertAt(int pos, int value) {
        if (pos <= 1) {
            push_Begin(value);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            push_end(value);
            return;
        }

        Node* node = new Node(value);
        node->next = temp->next;
        node->prev = temp;
        temp->next->prev = node;
        temp->next = node;
    }

    void pop_Begin() {
        if (!head) {
            cout << "Empty LinkedList..." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else end = nullptr; // list became empty
        delete temp;
    }

    void pop_End() {
        if (!end) {
            cout << "Empty LinkedList..." << endl;
            return;
        }
        Node* temp = end;
        end = end->prev;
        if (end) end->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    
    void deleteValue(int value) {
        Node* temp = head;
        while (temp && temp->data != value) {
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value not found." << endl;
            return;
        }

        if (temp == head) {
            pop_Begin();
            return;
        }
        if (temp == end) {
            pop_End();
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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

    void update(int oldVal, int newVal) {
        Node* temp = head;
        while (temp) {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found." << endl;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;
        end = head;

        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp) {
            head = temp->prev;
        }
    }

    void printForward() {
        Node* temp = head;
        cout << "[ ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }

    void printBackward() {
        Node* temp = end;
        cout << "[ ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << "]" << endl;
    }

    ~List() {
        while (head) pop_Begin();
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

    cout << "Forward: ";
    ll.printForward();

    cout << "Backward: ";
    ll.printBackward();

    ll.insertAt(3, 99);
    cout << "After insertAt(3,99): ";
    ll.printForward();

    ll.pop_Begin();
    ll.pop_End();
    cout << "After pop_Begin & pop_End: ";
    ll.printForward();

    ll.deleteValue(3);
    cout << "After deleteValue(3): ";
    ll.printForward();

    cout << "Search 99: " << (ll.search(99) ? "Found" : "Not Found") << endl;
    cout << "Count: " << ll.count() << endl;

    ll.update(99, 42);
    cout << "After update(99→42): ";
    ll.printForward();

    ll.reverse();
    cout << "After reverse: ";
    ll.printForward();

    return 0;
}

#include <iostream>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    std::unique_ptr<Node> head;
    Node* tail;
    size_t length;

public:
    LinkedList() : head(nullptr), tail(nullptr), length(0) {}

    void push_front(int value) {
        auto new_node = std::make_unique<Node>(value);
        if (!head) {
            tail = new_node.get();
        }
        new_node->next = std::move(head);
        head = std::move(new_node);
        length++;
    }

    void push_back(int value) {
        auto new_node = std::make_unique<Node>(value);
        Node* new_tail = new_node.get();
        if (!head) {
            head = std::move(new_node);
            tail = new_tail;
        } else {
            tail->next = std::move(new_node);
            tail = new_tail;
        }
        length++;
    }

    void pop_front() {
        if (!head) return;
        head = std::move(head->next);
        if (!head) tail = nullptr;
        length--;
    }

    void pop_back() {
        if (!head) return;
        if (head.get() == tail) { 
            head.reset();
            tail = nullptr;
        } else {
            Node* current = head.get();
            while (current->next.get() != tail) {
                current = current->next.get();
            }
            current->next.reset();
            tail = current;
        }
        length--;
    }

    void insert_at(size_t pos, int value) {
        if (pos == 0) {
            push_front(value);
            return;
        }
        if (pos >= length) {
            push_back(value);
            return;
        }
        Node* current = head.get();
        for (size_t i = 0; i < pos - 1; i++) {
            current = current->next.get();
        }
        auto new_node = std::make_unique<Node>(value);
        new_node->next = std::move(current->next);
        current->next = std::move(new_node);
        length++;
    }

    void remove_at(size_t pos) {
        if (!head || pos >= length) return;
        if (pos == 0) {
            pop_front();
            return;
        }
        Node* current = head.get();
        for (size_t i = 0; i < pos - 1; i++) {
            current = current->next.get();
        }
        if (current->next.get() == tail) {
            tail = current;
        }
        current->next = std::move(current->next->next);
        length--;
    }

    int find(int value) const {
        Node* current = head.get();
        size_t index = 0;
        while (current) {
            if (current->data == value) return index;
            current = current->next.get();
            index++;
        }
        return -1;  
    }

    size_t size() const { return length; }

    void print() const {
        Node* current = head.get();
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "Null\n";
    }
};

int main() {
    LinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert_at(1, 15);

    list.print(); // 5 -> 15 -> 10 -> 20 -> Null

    list.pop_front();
    list.pop_back();

    list.print(); // 15 -> 10 -> Null

    std::cout << "Index of 10: " << list.find(10) << "\n"; // 1
    std::cout << "Size: " << list.size() << "\n"; // 2
}

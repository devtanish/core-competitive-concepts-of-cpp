#include <iostream>
#include <memory>

struct Node {
    int data;
    std::unique_ptr<Node> next;

    Node(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    std::unique_ptr<Node> head;

    auto push_front(int value) -> void {
        auto new_node = std::make_unique<Node>(value);
        new_node->next = std::move(head); // move ownership
        head = std::move(new_node);
    }

    auto push_back(int value) -> void {
        auto new_node = std::make_unique<Node>(value);
        if (!head) {
            head = std::move(new_node);
            return;
        }
        Node* current = head.get();
        while (current->next) {
            current = current->next.get();
        }
        current->next = std::move(new_node);
    }

    auto print() -> void const {
        Node* current = head.get();
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next.get();
        }
        std::cout << "Null \n";
    }
};

int main() {
    LinkedList list;
    list.push_front(10);
    list.push_front(20);
    list.push_back(30);

    list.print();  // Output: 20 10 30
}

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int value){
        data = value;
    }
};

class List{
    private:
        Node* head;
        Node* end;

    public:
        List() {
            head = nullptr;
        }

        void push_Begin(int value){
            Node* node = new Node(value);
            node->next = head;
            head = node;
        }

        void print(){
            Node* temp = head;
            while(temp){
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"Null"<<endl;
        }

        void push_end(int value){
            Node* newNode = new Node(value);
            newNode->next = nullptr;
            if(!head){
                head = newNode;

                return;
            }
            Node* temp = head;
            while(temp){
                end = temp;
                temp = temp->next;
            }

            end->next = newNode;
        }

        void pop_End(){
            if(head == nullptr){
                cout<<"Empty LinkedList ..."<<endl;
                return;
            } else if(head->next == nullptr){
                cout<<"Empty LinkedList ..."<<endl;
                return;
            }

            delete end->next;
            end->next = nullptr;
        }

        void pop_Begin() {
            if(!head){
                cout<<"Empty LinkedList"<<endl;
            }

            Node* prevHead = head;

            head = head->next;

            delete prevHead;
        }
};

int main(){
    List ll;

    ll.push_end(1);
    ll.push_end(2);
    ll.push_end(3);
    ll.push_end(4);
    ll.push_end(5);
    ll.push_Begin(0);
    ll.pop_Begin();
    ll.pop_End();

    ll.print();
}
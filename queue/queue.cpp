#include<iostream>
using std::cout, std::cin, std::endl;

struct Node{
    int Data;
    Node* next;

    Node(int data) : Data(data), next(nullptr){};
};

class Queue{
    private:
        Node* front;
        Node* rear;

    public:

        Queue(){
            front = nullptr;
            rear = nullptr;
        }

        void Enqueue(const int data){
            Node* newNode = new Node(data);

            if(front == nullptr && rear == nullptr){
                front = newNode;
                rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void Dequeue() {
            if(front == nullptr && rear == nullptr){
                cout<<"!!! Can not Dequeue element because queue is EMPTY !!!"<<endl;
                return;
            } else if(front == rear) {
                delete front;
                front = nullptr;
                rear = nullptr;
            } else {
                Node* temp = front->next;
                delete front;
                front = temp;
            }
        }

        int Peek() {
            return front->Data;
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void const printQueue() const { 
            Node* tempNode = front;
            while(tempNode){
                cout<<tempNode->Data<<endl;
                tempNode = tempNode->next;
            }
        }

        ~Queue(){
            while(!isEmpty()){
                Dequeue();
            }
        }
};

int main() {

    Queue queue;
    queue.Dequeue();
    queue.isEmpty() == 0 ? cout<<"!!! Queue have some elements !!!"<<endl : cout<<"!!! Queue is Empty !!!"<<endl;
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    cout<<"The peak element in a queue is: "<<queue.Peek()<<endl;

    queue.Dequeue();
    
    queue.printQueue();
    queue.isEmpty() == 0 ? cout<<"!!! Queue have some elements !!!"<<endl : cout<<"!!! Queue is Empty !!!"<<endl;
    cout<<"The peak element in a queue is: "<<queue.Peek()<<endl;

}
#include<iostream>
#include<memory>
using std::cout, std::cin, std::endl;

struct Node{
	int Data;
	Node* Next;

	Node(int data) : Data(data) , Next(nullptr){};
};

void main() {

	int value = 20;
    // syntax is :- unique_ptr<dataType> variableName = make_unique<dataType>(value_that_holds);
	std::unique_ptr<Node> p = std::make_unique<Node>(value);

	cout<<"before transfer owership value is "<<p->Data<<endl;

	std::unique_ptr<Node> q = std::move(p); // moved ownership

	std::unique_ptr<Node> x(new Node(value));  //bad syntax to init a unique_pointer having many downsides of this approch throws exceptions 

	// cout<<"After transfer owership value is "<<p->Data<<endl;
	cout<<"After transfer owership value is "<<q->Data<<endl;

}
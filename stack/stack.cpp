#include<iostream>
#include<vector>
#include <optional>
using std::cout, std::cin, std::endl, std::vector;

class Stack{
    private:
        vector<int> stack;

    public:
        void push(int x) {
            stack.push_back(x);
        }

        void pop() {
            if(!(stack.empty())){
                stack.pop_back();
            } else {
                return;
            }
        }

        std::optional<int> getTop() const {
        if (!stack.empty()) {
            return stack.back();   // clean way instead of stack[stack.size()-1]
        } else {
            return std::nullopt;   // no exception, caller must check
        }
    }


        bool isEmpty() const {
            return stack.empty();
        }

        const vector<int>& getStack(){
            return stack;
        }
};

int main(){
    Stack stack;

    stack.pop();
    stack.getTop();
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.pop();

    cout<<stack.isEmpty()<<endl;
    auto top = stack.getTop();

    top.has_value() ? cout<<*top<<endl : cout<<"stack is empty"<<endl; 

    for(int x : stack.getStack()){
        cout<<x<<"  ";
    }
    cout<<endl;
}
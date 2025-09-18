#include <memory>
#include <iostream>
using namespace std;

int main() {

    shared_ptr<int> p1 = make_shared<int>(20);

    //we can not do this step in unique_ptr because unique_ptr only can give the ownership to new variable you can not give reference in that, so this is the use of shared_ptr we can give a reference to next ponter
    shared_ptr<int> p2 = p1; // both share same int

    cout << *p1 << " " << *p2 << endl;

    cout << "Count: " << p1.use_count() << endl; // 2

}

#include <iostream>
using namespace std;

template<typename... Args>
void printAll(Args... args) {
    (cout << ... << args) << endl;
}

template<typename... Args>
auto sum(Args... args) {
    return (args + ...);  // fold from left
}

int main() {
    printAll(1, 2, 3);
    printAll("Tanish", " ", "is learning ", "C++ templates!");
    printAll(42, ' ', 3.14, ' ', true);

    cout << sum(1, 2, 3, 4, 5) << endl;
}

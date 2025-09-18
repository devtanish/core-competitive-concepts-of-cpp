#include "functions.hpp"
#include "hello.cpp"


auto main() -> int {
    User user = User {
        name: "Tanish",
        password: "Hello",
        id: 43,
    };
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

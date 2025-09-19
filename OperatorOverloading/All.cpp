#include<iostream>
#include<functional>

class Complex{
    private:
        size_t a, b;

    public:
        Complex(size_t A , size_t B) : a(A), b(B){};

        Complex operator+(const Complex& other){
            return Complex(other.a + a , other.b + b);
        }

        std::pair<size_t, size_t> operator*(const Complex& other){
            return {this->a*other.a , this->b*other.b};
        }

        void display(){
            std::cout<<a<<"  +  "<<b<<std::endl;
        }
};

auto main() -> int {

    Complex com1(1, 2);
    Complex com2(3, 4);

    Complex add = com1 + com2;
    std::pair<size_t, size_t> mult = com1 * com2; 

    add.display();
    std::cout<<mult.first<<"  *  "<<mult.second<<std::endl;
    std::cout<<main<<std::endl;
}
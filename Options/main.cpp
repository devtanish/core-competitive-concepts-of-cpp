#include<iostream>
#include<optional>
#include<fstream>

auto main() -> int {

    std::optional<std::string> str = "tanish";

    if(str.has_value()){
        std::cout<<"The value of str is: "<<*str<<std::endl;
    } else {
        std::cout<<"str is Empty"<<std::endl;
    }

    return 0;
}
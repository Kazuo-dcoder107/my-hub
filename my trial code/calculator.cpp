#include <iostream>

int main(){
    double num1, num2;
    char operation;

    std::cout<< "Enter First Number."<< std:: endl;
    std::cin>> num1;
    std::cout<< "Enter Operation. (+, -, *, /):";
    std::cin>> operation;
    std::cout<< "Enter Second Number."<< std:: endl;
    std::cin>> num2;

    switch(operation){
        case '+':
        std::cout<< "Result: " << num1 + num2 <<std::endl;
        break;
        
        case '-':
        std::cout<< "Result: "<< num1 - num2<< std:: endl;

        case '*':
        std::cout<< "Result: "<< num1 * num2 << std:: endl;
        break;

        case '/':
        if(num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std:: endl;
            } else {
                std:: cout << "Error: Division by zero!" <<std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operator!" << std:: endl;
    }

        return 0;

    }

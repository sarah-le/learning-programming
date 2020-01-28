#include <iostream>
#include <string>

int main(void)
{
    std::string first_name;
    std::string phone_number;
    int age;

    std::cout << "What is your first name: ";
    std::getline(std::cin, first_name);
    std::cout <<"\nHello, " + first_name + ", what is your age? ";
    std::cin >> age;
    std::cout <<"\nOkay so you are " + std::to_string(age) + " years old," << std::endl;

    std::cout << "You just turned " + std::to_string(age++) + " years old!" <<std::endl;
    
    std::cout << "You just turned " + std::to_string(age--) + " years old!" <<std::endl;
    
    std::cout << "You just turned " + std::to_string(++age) + " years old!" <<std::endl;

    std::cout << "You just turned " + std::to_string(--age) + " years old!" <<std::endl;

    return 0;
}
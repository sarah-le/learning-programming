#include <iostream>
#include <string>

int main (void)
{
    //Arithmetic

    std::cout << 3 + 3 <<std::endl;
    std::cout << 3 - 3 <<std::endl;
    std::cout << 3 * 3 <<std::endl;
    std::cout << 15 / 3 <<std::endl;
    std::cout << 99 % 66 <<std::endl;

    int a = 30;

    std::cout << a <<std::endl;
    a %= 9;
    std::cout << a <<std::endl;

    //String Concatenation
    std::string first_name = "Sarah";
    std::string last_name = "Edie";
    std::string first_and_last_name = first_name + " " + last_name;

    std::cout << first_and_last_name << std::endl;

}
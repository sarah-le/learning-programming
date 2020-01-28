#include <iostream>

int main(void)
{

    int age;
    bool prior_visit;
    char c;

    std::cout << "What is your age? ";
    std::cin >> age;

    std::cout << "Have you been here before? (Y/N): ";
    std:: cin >> c;

    if(c == 'Y')
    {
        prior_visit = true;
    }
    else if(c == 'N')
    {
        prior_visit = false;
    }

    if(age >= 60)
    {
        std::cout << "You are eligble for the senior ticket" << std::endl;
    }
    else if(age > 16)
    {
        std::cout << "You are eligible for the adult ticket" <<std::endl;
    }
    else
    {
        std::cout << "You are eligible for the child ticket" << std::endl;
    }

    if(prior_visit) //prior_visit == true
    {
        std::cout << "YOu are eligible for a discount on your ticket price!" << std::endl;
    }
    else if(!prior_visit) //priot_visit == false or prior_visit != true
    {
        std::cout << "You are not eligible for a discount on your ticket price!" << std::endl;
    }


    return 0;
}
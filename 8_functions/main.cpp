#include <iostream>
#include <string>

// Function declarations
bool visited_before(char ans);
std::string eligible_ticket(int age);
void discount(bool prior_visit);

int main(void)
{
    int age;
    char c;
    bool prior_visit;
    std::string ticket;

    std::cout << "What is your age? ";
    std::cin >> age;

    ticket = eligible_ticket(age);
    std::cout << "You are eligible for the " + ticket + " ticket." << std::endl;

    std::cout << "Have you been here before? (Y/N): ";
    std:: cin >> c;

    prior_visit = visited_before(c);
    discount(prior_visit);

    return 0;

}

bool visited_before(char ans)
{
    if(ans == 'Y')
    {
        return true;
    }
    else if(ans == 'N')
    {
         return false;
    }
}

std::string eligible_ticket(int age)
{
    if(age >= 60)
    {
        return "senior ticket";
    }
    else if(age > 16)
    {
        return "adult ticket";
    }
    else
    {
        return "child ticket";
    }
}

void discount(bool prior_visit)
{
    if(prior_visit) //prior_visit == true
    {
        std::cout << "You are eligible for a discount on your ticket price!" << std::endl;
    }
    else if(!prior_visit) //priot_visit == false or prior_visit != true
    {
        std::cout << "You are not eligible for a discount on your ticket price!" << std::endl;
    }
}

// Step 1: Declare a few variables (some with no values and some with values)
// Step 2: Set the value of the empty variables on new lines
// Step 3: Create a function that accepts any type as a parameter and does something with the parameter
// Step 4: Create a few break points (either clicking to left of line number or F9)
// Step 5: Run your code in debug mode and explore all the new features we learnt about the debugger



#include <iostream>
#include <string>

std::string ur_mum_gei(std::string str);

int main(void)
{
    int ur_poopy;
    std::string ur_mum_gey;

    ur_poopy = 2;
    ur_mum_gey = "Ur Mum Gey~";

    ur_mum_gei(ur_mum_gey);

    for( ur_poopy; ur_poopy < 10; ur_poopy++)
    {
        std::cout << std::to_string(ur_poopy) << std::endl;
    }

    return 0;
}

std::string ur_mum_gei(std::string str)
{
    std::cout << str << std::endl;
}
#include <iostream>

int main(void)
{
    int i = 1;

    if(i == 1)
        std::cout << i << std::endl;
    else
        std::cout << "Hello" << std::endl;
    
    if(i == 1) std::cout << i << std::endl;

    
    if(i == 1) 
    {
        std::cout << i << std::endl;
        std::cout << i + 1 << std::endl;
    }

    for(int i = 10; i > 1; i--);
    {
        std::cout << "Hello!" << std::endl;
        int i = 0;
        std::cout << i << std::endl;
    }

    std::cout << i << std::endl;

    return 0;
}
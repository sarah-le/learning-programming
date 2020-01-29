#include <iostream>

int main(void)
{
    for(int i = 0; i < 10; i++ )
    {
        std::cout << i << std::endl;
    }

    int index = 0;
    while(index < 10)
    {
        std::cout << index << std::endl;
        index++;
    }

    index = 1;
    do
    {
        std::cout << index << std::endl;
    } while (index < 1);

    return 0;
}
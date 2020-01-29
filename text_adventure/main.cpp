#include <iostream>
#include <string>

int main(void)
{
    // This is where all the character variables are held
    std::string name;
    std::string town;
    std::string race;
    std::string base_class;
    std::string advanced_class;
    std::string gender;

    //Opening introduction
    std::cout << "Welcome to the world of Gilt. For many years it has been at peace, with all its residents living seperately and harmoniously. But, like all things... this peace has come to an end..." << std::endl;

    //Getting the variables
    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    std::cout << "What town do you hail from? ";
    std::getline(std::cin, town);
    
    std::cout << "What race are you? ";
    std::getline(std::cin, race);

    std::cout << "What is your gender? (Male/Female/Other) ";
    std::getline(std::cin, gender);

    std::cout << "What class are you? Warrior, Mage, or Priest? ";
    std::cin >> base_class;

    //Checking which base_class they chose and giving them only relevent options for advanced_class
    if(base_class == "Warrior")
    {
        std::cout << "What is your advanced class? Berserker or Defensive? ";
        std::cin >> advanced_class;
    }
    else if(base_class == "Mage")
    {
        std::cout << "What is your advanced class? Light or Dark? ";
        std::cin >> advanced_class;
    }
    else
    {
        std::cout << "What is your advanced class? Holy or Shadow? ";
        std::cin >> advanced_class;
    }
    
    std::cout << "So, your name is " + name + " and you are a " + race + " from the town of " + town + ". You are a " + base_class + " and you specialise in the " + advanced_class + " class... excellent." <<std::endl;
    std::cout << "Gilt has been victim of an uprising brought on by Fract the Burdened. For many years, unbeknownst to the world, he has been building an army of undead. Whilst his reasoning is not yet known, his destruction is clear and you, " + name + ", only have two options: fight, or die." << std::endl;

}
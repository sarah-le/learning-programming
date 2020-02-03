#include <iostream>
#include <string>

std::string choosing_variables(std::string, std::string, std::string, std::string, std::string);

int main(void)
{
    // This is where all the character variables are held
    std::string name;
    std::string town;
    std::string race;
    std::string base_class;
    std::string find_advanced_class;
    std::string advanced_class;
    std::string gender;

    bool warrior = false;
    bool mage = false;
    bool priest = false;

    std::string berseker = "Berserker";
    std::string defensive = "Defensive";
    std::string dark = "Dark";
    std::string light = "light";
    std::string holy = "Holy";
    std::string shadow = "Shadow";

    int HP;
    int MP;
    int level;

    // Opening introduction
    std::cout << "Welcome to the world of Gilt. For many years it has been at peace, with all its residents living seperately and harmoniously. But, like all things... this peace has come to an end..." << std::endl;

    // Getting the variables
    std::cout << "What is your name? ";
    std::getline(std::cin, name);
    std::cout << name << std::endl;

    std::cout << "What town do you hail from? ";
    std::getline(std::cin, town);
    std::cout << town << std::endl;

    // Checking for race
    race = choosing_variables(race, "What race are you? (Human/Elf/Gnome) ", "Human", "Elf", "Gnome");
    std::cout << race << std::endl;

    // Checking for gender
    gender = choosing_variables(gender, "What is your gender? (Male/Female/Other) ", "Male", "Female", "Other");
    std::cout << gender << std::endl;

    // Checking for base class
    base_class = choosing_variables(base_class, "What class are you? Warrior, Mage, or Priest? ", "Warrior", "Mage", "Priest");
    std::cout << base_class << std::endl;

    // Checking for advanced class

    if (base_class == "Warrior")
    {
        while (warrior == false)
        {
            std::cout << "What do you aspire to master within your class? Berserker or Defensive? ";
            std::cin >> advanced_class;

            if (advanced_class == "Defensive")
            {
                warrior == true;
            }
            if (advanced_class == "Berseker")
            {
                warrior == true;
            }
        }
        return warrior;
    }
    else if (base_class == "Mage")
    {
        while (mage == false)
        {
            std::cout << "What do you aspire to master within your class? Light or Dark? ";
            std::cin >> advanced_class;
            std::cout << advanced_class << std::endl;

            if (advanced_class == "Dark")
            {
                mage == true;
            }
            else if (advanced_class == "Light")
            {
                mage = true;
            }
        }
        return 1;
    }
    else
    {
        while (priest == false)
        {
            std::cout << "What do you aspire to master within your class? Holy or Shadow? ";
            std::cin >> advanced_class;

            if (advanced_class == "Holy")
            {
                priest == true;
            }
            if (advanced_class == "Shadow")
            {
                priest == true;
            }
        }
        return priest;
    }

    std::cout << advanced_class << std::endl;

    // printing final statement and moving story along
    std::cout << "So, your name is " + name + " and you are a " + race + " from the town of " + town + ". You are a " + base_class + " and you wish to specialise in " + advanced_class + "... excellent." << std::endl;
    std::cout << "Gilt has been victim of an uprising brought on by Fract the Burdened. For many years, unbeknownst to the world, he has been building an army of undead. Whilst his reasoning is not yet known, his destruction is clear and you, " + name + ", only have two options: fight, or die." << std::endl;
}

std::string choosing_variables(std::string character_detail, std::string question, std::string choice_1, std::string choice_2, std::string choice_3)
{
    bool character_choice = false;

    while (character_choice == false)
    {
        std::cout << question;
        std::getline(std::cin, character_detail);

        if (character_detail == choice_1)
        {
            character_choice = true;
        }
        else if (character_detail == choice_2)
        {
            character_choice = true;
        }
        else if (character_detail == choice_3)
        {
            character_choice = true;
        }
    }

    return character_detail;
}
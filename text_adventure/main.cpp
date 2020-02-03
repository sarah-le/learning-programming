#include <iostream>
#include <string>

std::string choosing_variables(std::string, std::string, std::string, std::string, std::string);
std::string choosing_advanced_class(std::string, std::string, std::string);
int losing_hp(int hp, bool taking_damage);

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

    // Race names
    std::string race_1 = "Human";
    std::string race_2 = "Elf";
    std::string race_3 = "Gnome";

    //Class names
    std::string class_1 = "Warrior";
    std::string class_2 = "Mage";
    std::string class_3 = "Priest";

    // Advanced class names
    std::string berserker = "Berserker";
    std::string defensive = "Defensive";
    std::string dark = "Dark";
    std::string light = "light";
    std::string holy = "Holy";
    std::string shadow = "Shadow";

    // Fighting related variables
    int HP = 100;
    int MP = 100;
    int level = 1;

    bool taking_damage = false;

    // Opening introduction
    std::cout << "Welcome to the world of Gilt. For many years it has been at peace, with all its residents living seperately and harmoniously. But, like all";
    std::cout << "things... this peace has come to an end..." << std::endl;

    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    std::cout << "What town do you hail from? ";
    std::getline(std::cin, town);

    // Checking for race
    race = choosing_variables(race, "What race are you? (" + race_1 + "/" + race_2 + "/" + race_3 + "): ", race_1, race_2, race_3);

    // Checking for gender
    gender = choosing_variables(gender, "What is your gender? (Male/Female/Other): ", "Male", "Female", "Other");

    // Checking for base class
    base_class = choosing_variables(base_class, "What class are you? " + class_1 + ", " + class_2 + ", " + class_3 + "? ", class_1, class_2, class_3);

    // Checking for advanced class
    if(base_class == "Warrior")
    {
        advanced_class = choosing_advanced_class("What advanced class do you aspire to master? Berserker or Defensive? ", base_class, advanced_class);
    }
    else if(base_class == "Mage")
    {
        advanced_class = choosing_advanced_class("What advanced class do you aspire to master? Light or Dark? ", base_class, advanced_class);
    }
    else if (base_class == "Priest")
    {
        advanced_class = choosing_advanced_class("What advanced class do you aspire to master? Holy or Shadow? ", base_class, advanced_class);
    }

    // printing final statement and moving story along
    std::cout << "So, your name is " + name + " and you are a " + race + " from the town of " + town + ".";
    std::cout << " You are a " + base_class + " and you wish to specialise in " + advanced_class + "... excellent." << std::endl;
    
    std::cout << "Gilt has been victim of an uprising brought on by Fract the Burdened. For many years, unbeknownst to the world, he has been building an army";
    std::cout << "of undead. Whilst his reasoning is not yet known, his destruction is clear and you, " + name + ", only have two options: fight, or die." << std::endl;

    HP = losing_hp(HP, taking_damage);
    std::cout << HP << std::endl;
}

// a function that means users can only answer 3 options and makes them repeat answer if incorrect
std::string choosing_variables(std::string character_detail, std::string question,
                               std::string choice_1, std::string choice_2, std::string choice_3)
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

// a function that checks the user is only entering correct options
std::string choosing_advanced_class(std::string question, std::string base_class, std::string advanced_class)
{
    bool mage = false;
    bool warrior = false;
    bool priest = false;

    if (base_class == "Warrior")
    {
        while (warrior == false)
        {
            std::cout << question;
            std::cin >> advanced_class;

            if (advanced_class == "Defensive")
            {
                warrior = true;
            }
            if (advanced_class == "Berserker")
            {
                warrior = true;
            }
        }
    }
    else if (base_class == "Mage")
    {
        while (mage == false)
        {
            std::cout << question;
            std::cin >> advanced_class;

            if (advanced_class == "Dark")
            {
                mage = true;
            }
            else if (advanced_class == "Light")
            {
                mage = true;
            }
        }
    }
    else
    {
        while (priest == false)
        {
            std::cout << question;
            std::cin >> advanced_class;

            if (advanced_class == "Holy")
            {
                priest = true;
            }
            if (advanced_class == "Shadow")
            {
                priest = true;
            }
        }
    }
    return advanced_class;
}

int losing_hp(int hp, bool taking_damage)
{
    if(taking_damage = true)
    {
        hp -= 1;
        std::cout << "Your HP is now: " + std::to_string(hp) << std::endl;
    }
    return hp;
}
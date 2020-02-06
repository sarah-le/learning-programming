#include <iostream>
#include <string>

std::string choosing_variables(std::string, std::string, std::string, std::string, std::string);
std::string choosing_advanced_class(std::string, std::string, std::string);
int current_hp(int hp, int attack_damage, bool taking_damage);
int current_mp(int mp, int flash, bool using_mana);
int menu(int menu_choice);

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

    // Gender 
    std::string male = "Male";
    std::string female = "Female";
    std::string other = "Other";

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
    int attack_damage = 2;
    int mana_usuage = 5;

    bool taking_damage = false;
    bool being_healed = false;
    bool using_mana = false;

    //Using moves
    int flash = 5;

    // menu options
    int menu_choice;
    bool viable_choice = false;

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
    gender = choosing_variables(gender, "What is your gender? (Male/Female/Other): ", male, female, other);

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

    // Printing final statement and moving story along
    std::cout << "So, your name is " + name + " and you are a " + race + " from the town of " + town + ".";
    std::cout << " You are a " + base_class + " and you wish to specialise in " + advanced_class + "... excellent." << std::endl;
    
    std::cout << "Gilt has been victim of an uprising brought on by Fract the Burdened. For many years, unbeknownst to the world, he has been building an army ";
    std::cout << "of undead. Whilst his reasoning is not known, his destruction is clear. You, " + name + ", only have two options: fight or die." << std::endl;

    // Printing the menu which either reduces HP, MP, or quits game
    menu_choice = menu(menu_choice);

    // A while loop which checks the users answer
    while(viable_choice == false)
    {
        if(menu_choice == 1)
        {
            viable_choice = true;
            taking_damage = true;
            HP = current_hp(HP, attack_damage, taking_damage);
            menu_choice = menu(menu_choice);
        }
        if(menu_choice == 2)
        {
            viable_choice = true;
            using_mana = true;
            MP = current_mp(MP, flash, using_mana);
            menu_choice = menu(menu_choice);
        }
        if(menu_choice == 3)
        {
            viable_choice = true;
            std::cout << "Your current level is: " + std::to_string(level) << std::endl;
            menu_choice = menu(menu_choice);
        }
        if(menu_choice == 4)
        {
            viable_choice = true;
            return 0;
        }
        else
        {
            viable_choice = false;
            std::cout<< "You have entered an invalid number. Please choose again:" << std::endl;
            menu_choice = menu(menu_choice);
        }
    }   

    return 0;
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

// a function that lowers the HP if attacked
int current_hp(int hp, int attack_damage, bool taking_damage)
{
    if(taking_damage == true)
    {
        hp -= attack_damage;
        std::cout << "Your HP is now: " + std::to_string(hp) << std::endl;
    }
    else if(taking_damage == false)
    {
        std::cout << "Your HP is: " + std::to_string(hp) << std::endl;
    }
}

// a function that lowers the MP if used
int current_mp(int mp, int mana_usage, bool using_mana)
{
    if(using_mana == true)
    {
        mp -= mana_usage;
        std::cout << "Your mana is now: " + std::to_string(mp) << std::endl;
    }
}

// printing the menu and recording the users input
int menu(int menu_choice)
{
    std::cout<< "MENU:" << std::endl;
    std::cout<< "Damage HP (1) " << std::endl; 
    std::cout<< "Reduce MP (2) " << std::endl;
    std::cout<< "Show Level (3) " << std::endl;
    std::cout<< "Quit (4)" << std::endl;
    std::cin>> menu_choice;

    return menu_choice;
}
// Total marks: 85/100

#include <iostream>
#include <string>

std::string choosing_variables(std::string, std::string, std::string, std::string, std::string);
std::string choosing_advanced_class(std::string, std::string, std::string);
int current_hp(int hp, int attack_damage);
int current_mp(int mp, int flash);
int menu(int menu_choice);

int main(void)
{
    // This is where all the character variables are held
    std::string name;
    std::string town;
    std::string race;
    std::string base_class;
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
    std::string advanced_class_1 = "Berserker";
    std::string advanced_class_2 = "Defensive";
    std::string advanced_class_3 = "Dark";
    std::string advanced_class_4 = "light";
    std::string advanced_class_5 = "Holy";
    std::string advanced_class_6 = "Shadow";

    // Fighting related variables
    int hp = 100;
    int mp = 100;
    int level = 1;
    int attack_damage = 2;
    int mana_usuage = 5;

    // Menu options
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
    if (base_class == "Warrior")
    {
        advanced_class = choosing_advanced_class("Which advnaced class do you aspire to be? " + advanced_class_1 + " or " + advanced_class_2 + "? ",
                                                 advanced_class_1, advanced_class_2);
    }
    else if (base_class == "Mage")
    {
        advanced_class = choosing_advanced_class("Which advnaced class do you aspire to be? " + advanced_class_3 + " or " + advanced_class_4 + "? ",
                                                 advanced_class_3, advanced_class_4);
    }
    else if (base_class == "Priest")
    {
        advanced_class = choosing_advanced_class("Which advnaced class do you aspire to be? " + advanced_class_5 + " or " + advanced_class_6 + "? ",
                                                 advanced_class_5, advanced_class_6);
    }

    // Printing final statement and moving story along
    std::cout << "So, your name is " + name + " and you are a " + race + " from the town of " + town + ".";
    std::cout << " You are a " + base_class + " and you wish to specialise in " + advanced_class + "... excellent." << std::endl;

    std::cout << "Gilt has been victim of an uprising brought on by Fract the Burdened. For many years, unbeknownst to the world, he has been building an army ";
    std::cout << "of undead. Whilst his reasoning is not known, his destruction is clear. You, " + name + ", only have two options: fight or die." << std::endl;

    // Printing the menu which either reduces HP, MP, or quits game
    menu_choice = menu(menu_choice);

    // A while loop which checks the users input from the menu
    while (!viable_choice)
    {
        menu_choice = menu(menu_choice);

        if (menu_choice == 1)
        {
            hp = current_hp(hp, attack_damage);
            std::cout << "You took " + std::to_string(attack_damage) + ", and now your HP is: " << hp << std::endl;
        }
        else if (menu_choice == 2)
        {
            std::cout << mp << std::endl;
        }
        else if (menu_choice == 3)
        {
            std::cout << "Your current level is: " + std::to_string(level) << std::endl;
        }
        else if (menu_choice == 4)
        {
            viable_choice = true;
        }
        else
        {
            std::cout << "You have entered an invalid number. Please choose again:" << std::endl;
        }
    }
}

// A function that means users can only answer 3 options and makes them repeat answer if incorrect
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

// A function that means users can only choose relevant advanced class options
std::string choosing_advanced_class(std::string class_options, std::string choice_1, std::string choice_2)
{
    bool valid_choice = false;
    std::string choice;

    while (!valid_choice)
    {
        std::cout << class_options;
        std::cin >> choice;

        if (choice == choice_1)
            valid_choice = true;
        else if (choice == choice_2)
            valid_choice = true;
    }

    return choice;
}

// A function that prints the users hp
int current_hp(int hp, int attack_damage)
{
    return hp -= attack_damage;
}

// A function that prints the users mp
int current_mp(int mp, int mana_usage)
{
    mp -= mana_usage;
}

// Printing the menu and recording the users input
int menu(int menu_choice)
{
    std::cout << "MENU:" << std::endl;
    std::cout << "Damage HP (1) " << std::endl;
    std::cout << "Reduce MP (2) " << std::endl;
    std::cout << "Show Level (3) " << std::endl;
    std::cout << "Quit (4)" << std::endl;
    std::cin >> menu_choice;

    return menu_choice;
}
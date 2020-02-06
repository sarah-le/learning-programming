/* FEEDBACK */
// General feedback on your comments is that they need to be a bit more consistent
//some are like this
//Some are like this
// Some are like this
// Consistency is great
// Once again only a warning, no mark deduction this time

/* FEEDBACK */
// Mark deduction for comments: 2% (comments are very important)

/* FEEDBACK */
// Remember to keep code formatted as it is very important
// It doesn't hurt to use vscode's format options either
// Which can be accessed via CTRL + SHIFT + P
// Then typing "format document" and pressing enter
// Or just pressing SHIFT + ALT + F

// Please use CTRL + F to search for "FEEDBACK" to view all my feedback

// Total marks: 85/100

#include <iostream>
#include <string>

std::string choosing_variables(std::string, std::string, std::string, std::string, std::string);
std::string choosing_advanced_class(std::string, std::string, std::string);

/* FEEDBACK */
// A function should ideally only have one purpose to avoid confusion
// In this case you could have 2 functions, 1 for retrieiving the HP (not that you need that right now because it's a global variable)
// And one for damaging. Usually if you begin to merge 2 purposes into 1 function, you have to add needless parameters
// In this case "taking_damage" everytime you just want to check the current HP
// One function = one purpose (if possible)
// My version would be something like this (repeat for MP)
// int damage_hp(int attack_damage)
// {
//     return hp -= attack_damage;
// }
// Mark deduction: 2%

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

    /* FEEDBACK */
    // Unused variable
    // Mark deduction: 1%
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

    /* FEEDBACK */
    // You had some good prefixes going on above such as "class_" and "race_"
    // Calling a variable berserker is fine, however it can be a bit ambiguous
    // What is this "berserker"
    // Calling it advanced_class_berserker or ac_berserker
    // While maybe the last one isn't as obvious, it implies something more is there than just "berserker" = "berserker"
    // Mark deduction: 1%
    std::string berserker = "Berserker";
    std::string defensive = "Defensive";
    std::string dark = "Dark";
    std::string light = "light";
    std::string holy = "Holy";
    std::string shadow = "Shadow";

    // Fighting related variables

    
    /* FEEDBACK */
    // It's generally a good idea to keep variable naming schemes, in this case you've used snake_case
    // snake_case doesn't have capitals, and so HP and MP should be hp and mp
    // Programming naming practices are extremely important when working with others
    // Not worthy of a mark deduction, but definitely keep in mind for next time
    int HP = 100;
    int MP = 100;
    int level = 1;
    int attack_damage = 2;
    int mana_usuage = 5;

    bool taking_damage = false;
    bool being_healed = false;
    bool using_mana = false;

    /* FEEDBACK */
    // Ambiguous commment here, I don't really have any idea what "Using moves" and flash means or what their relation is 

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

    /* FEEDBACK */
    // Really should be using if, else-if here, it's not possible to ever enter all 4 combinations of numbers
    // If you enter 1, then it's one, else it's 2, else 3, etc.
    // It can never be 1,2,3,4
    // This wastes time, although minimal, is a good idea to get your mind into the thought of writing efficient code
    // Here once a match has been found, it will keep checking all cases due to it being if, if, if, if
    // Even when it's already found the match
    // Need to use if, else-if
    // You used else properly, however due to the lack of else-ifs, the else is only tied to the last if
    // Not tied to the whole block like it logically should
    // It reads as: if 1, if 2, if 3, if 4 else this
    // Instead it should say
    // If 1, else if 2, else if 3, else if 4, else this
    // If you could enter all 1, 2, 3 and 4 at the same time, then this would be okay, but you can't
    // Mark deduction: 2.5%

    /* FEEDBACK */
    // The while loop doesn't actually work properly
    // You print the menu before entering the while loop, when it isn't really needed
    // It should be printed at the top of the while loop, and then once the user makes a decision
    // It fall down into each of the if statements to check their menu_choice
    // The menu should not be re-printed at the end of every if statement, as the point of a while loop is that it LOOPS
    // You should use the characteristics of things like while loops to your advantage
    // Mark deduction: 2.5%

    /* FEEDBACK */
    // Your while loop is fundamentally broken and is only saved by the menu_choice being at the bottom of each if
    // Without it, once a choice is found viable_choice would be false and the loop would end
    // The only reason it keeps looping, is because the menu is printed after each if block
    // And inevitably it will end up in the else block, because you can't pick the same choice twice in a row
    // (due to menu_choice being at the bottom of each if)
    // Or it will fall into choice 4 and quit the program
    // Mark deduction: 2.5%

    /* FEEDBACK */
    // Here is how I would personally re-structure this while loop
    // while(!viable_choice)
    // {
    //     menu_choice = menu(menu_choice);

    //     if(menu_choice == 1)
    //     {
    //         taking_damage = true;
    //         HP = current_hp(HP, attack_damage, taking_damage);
    //     }
    //     else if(menu_choice == 2)
    //     {
    //         using_mana = true;
    //         MP = current_mp(MP, flash, using_mana);
    //     }
    //     else if(menu_choice == 3)
    //     {
    //         std::cout << "Your current level is: " + std::to_string(level) << std::endl;
    //     }
    //     else if(menu_choice == 4)
    //     {
    //          viable_choice = true;
    //     }
    //     else
    //     {
    //         std::cout<< "You have entered an invalid number. Please choose again:" << std::endl;
    //     }
    // }
    // Here the loop begins with printing the menu and asking for user input
    // It then proceeds to funnel down each check for their input
    // Either printing an error and then looping back to the top (which will re-print the menu)
    // Or doing an action then looping back to the top
    // If quit, the variable is set to true and the loop will end

    while(viable_choice == false)
    {
        if(menu_choice == 1)
        {
            viable_choice = true;
            taking_damage = true;
            HP = current_hp(HP, attack_damage, taking_damage);

            /* FEEDBACK */
            // This is the cause of "Invalid number error"
            // Say you enter 1, then at the bottom it will re-print the menu and take input
            // So you re-enter 1
            // Then it checks the next 2 ifs, but it's already moved past checking for 1
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
            
            /* FEEDBACK */
            // Smart thinking of exiting the main function
            // However it is nicer to quit the loop and allow the program to naturally quit
            // Via the last line of the main function "return 0"
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

/* FEEDBACK */
// General lack of commenting in each function
// While may be possible to determine the function's purpose
// Comments would help this a lot
// Mark deduction: 1%

// a function that means users can only answer 3 options and makes them repeat answer if incorrect

/* FEEDBACK */
// Smart thinking of how to create a general purpose function for a repeated use case
// Good variable names as well
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
/* FEEDBACK */
// This function seems a bit redundant with how it works
// To make my point in the best way I will just type out how I would do it
// And should be able to see quickly

// std::string choosing_advanced_class(std::string class_options, std::string choice_1, std::string choice_2)
// {
//     bool valid_choice = false;

//     // Here I've placed the advanced class choice variable within the function
//     // As passing in an empty variable doesn't really make sense
//     // First you would declare this empty variable in main
//     // Then pass the empty variable to this function
//     // Which would then make a copy of that empty variable
//     // Then you would store the choice in it
//     // And then return it from the function thus assigning a copy of the variable back to the
//     // First advanced_class variable

//     // Here you just create it in the function, then return it
//     std::string choice;

//     while(!valid_choice)
//     {
//         std::cout << class_options;
//         std::cin >> choice;

//         if (choice == choice_1)
//             valid_choice = true;
//         else if (choice == choice_2)
//             valid_choice = true;
//     }

//     return choice;
// }

// Remember that functions are meant to get rid of repetition, not create more
// Think about what the core of your function is really trying to achieve

// if (base_class == "Warrior")
// {
//     advanced_class = choosing_advanced_class(defensive + " or " + berserker, defensive, berserker);
// }

/* FEEDBACK */
// Above is how I would call the function
// Mark deduction: 2.5%

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

    /* FEEDBACK */
    // Nice syntax to separate the return statement from other statements with a space
}

// a function that lowers the HP if attacked
int current_hp(int hp, int attack_damage, bool taking_damage)
{
    /* FEEDBACK */
    // All these statements can be written as:
    // if(taking_damage)

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
    /* FEEDBACK */
    // Should format the spacing between cout and <<
    std::cout<< "MENU:" << std::endl;
    std::cout<< "Damage HP (1) " << std::endl; 
    std::cout<< "Reduce MP (2) " << std::endl;
    std::cout<< "Show Level (3) " << std::endl;
    std::cout<< "Quit (4)" << std::endl;
    std::cin>> menu_choice;

    return menu_choice;
}
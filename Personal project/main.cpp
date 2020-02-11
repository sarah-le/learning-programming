#include <iostream>
#include <string>

int main_menu(int main_menu_choice);
std::string give_answer(int input_choice, std::string option_1, std::string option_2, std::string option_3, std::string option_4, std::string phrase);

int main(void)
{
    int main_menu_choice;
    bool making_main_menu_choice = false;

    // Name Variables
    int name_choice;
    std::string name_1 = "Jackdawstrike";
    std::string name_2 = "Rabbitspring";
    std::string name_3 = "Sorrelspots";
    std::string name_4 = "Brindletail";
    std::string name;

    // Eye colour variables
    int eye_colour_choice;
    std::string eye_colour_1 = "Green";
    std::string eye_colour_2 = "Blue";
    std::string eye_colour_3 = "Yellow";
    std::string eye_colour_4 = "Amber";
    std::string eye_colour;

    std::cout << "Welcome To Create A Cat! Please choose an option: " << std::endl;

    // Checking what the value of main_menu_choice is and applying the correct function.
    while (making_main_menu_choice == false)
    {
        main_menu_choice = main_menu(main_menu_choice);

        if (main_menu_choice == 1)
        {
            name = give_answer(name_choice, name_1, name_2, name_3, name_4, "Your name is: ");
            std::cout << name << std::endl;
        }
        else if (main_menu_choice == 2)
        {
            eye_colour = give_answer(eye_colour_choice, eye_colour_1, eye_colour_2, eye_colour_3, eye_colour_4, "Your eye colour is: ");
            std::cout << eye_colour << std::endl;
        }
        else if (main_menu_choice == 3)
        {
            std::cout << "yo 3" << std::endl;
        }
        else if (main_menu_choice == 4)
        {
            std::cout << "yo 4" << std::endl;
        }
        else if (main_menu_choice == 5)
        {
            return 0;
        }
        else
        {
            std::cout << "You have chosen an invalid number. Please choose again." << std::endl;
        }
    }
}

// This is a function which prints out the main menu, it takes user input to decide what they would like to do first.
int main_menu(int main_menu_choice)
{
    std::cout << "(1) Name " << std::endl;
    std::cout << "(2) Eye Colour  " << std::endl;
    std::cout << "(3) Coat Colour " << std::endl;
    std::cout << "(4) Rank " << std::endl;
    std::cout << "(5) Exit " << std::endl;
    std::cin >> main_menu_choice;

    return main_menu_choice;
}

std::string give_answer(int input_choice, std::string option_1, std::string option_2, std::string option_3, std::string option_4, std::string phrase)
{
    std::cout << "Choose a number between 1 and 4: ";
    std::cin >> input_choice;

    if (input_choice == 1)
    {
        bool name_choice_in_range = true;
        std::cout << phrase + option_1 << std::endl;
    }
    else if (input_choice == 2)
    {
        bool name_choice_in_range = true;
        std::cout << phrase + option_2 << std::endl;
    }
    else if (input_choice == 3)
    {
        bool name_choice_in_range = true;
        std::cout << phrase + option_3 << std::endl;
    }
    else if (input_choice == 4)
    {
        bool name_choice_in_range = true;
        std::cout << phrase + option_4 << std::endl;
    }
    else
    {
        std::cout << "You have entered an invalid number!" << std::endl;
    }
}
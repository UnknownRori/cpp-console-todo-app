#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <thread>
#include "include/TodoApp.h"

void clearScreen();
void pause(int miliseconds);
void lowerCase(std::string *value);

int main()
{
    TodoApp *app = new TodoApp();
    std::string buffer = "";

    while (true)
    {
        std::cout << "Command : ";
        std::getline(std::cin, buffer);
        std::cout << "\n";

        lowerCase(&buffer);

        if (buffer == "exit")
            break;

        if (buffer == "create" || buffer == "0")
        {
            std::cout << "Enter Task : ";
            std::getline(std::cin, buffer);
            app->create(buffer);
        }
        else if (buffer == "edit" || buffer == "1")
        {
            int index = 0;

            std::cout << "Which index : ";
            std::cin >> index;
            std::cout << "What the new value is : ";
            std::cin.ignore();
            std::getline(std::cin, buffer);
            app->update(index, buffer);
        }
        else if (buffer == "toggle" || buffer == "2")
        {
            int index = 0;
            std::cout << "Which index : ";
            std::cin >> index;
            std::cout << "\n";
            app->toggleFinish(index);
            std::cin.ignore();
        }
        else if (buffer == "delete" || buffer == "3")
        {
            int index = 0;
            std::cout << "Which index : ";
            std::cin >> index;
            std::cout << "\n";
            app->destroy(index);
            std::cin.ignore();
        }
        else if (buffer == "print" || buffer == "4")
        {
            clearScreen();
            app->printLists();
            std::cout << "\n";
        }
        else if (buffer == "clear" || buffer == "5")
        {
            clearScreen();
        }
        else if (buffer == "help" || buffer == "6")
        {
            clearScreen();
            std::cout << "0 : create"
                      << "\n";
            std::cout << "1 : edit"
                      << "\n";
            std::cout << "2 : toggle"
                      << "\n";
            std::cout << "3 : delete"
                      << "\n";
            std::cout << "4 : print"
                      << "\n";
            std::cout << "5 : clear"
                      << "\n";
            std::cout << "6 : help"
                      << "\n";
        }
        else
        {
            std::cout << "There is no such a command \n";
        }
    }

    free(app);
    return 0;
}

void clearScreen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}

void pause(int miliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

void lowerCase(std::string *value)
{
    std::transform(value->begin(), value->end(), value->begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
}
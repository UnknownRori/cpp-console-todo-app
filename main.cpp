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

        if (buffer == "create")
        {
            std::cout << "Enter Task : ";
            std::getline(std::cin, buffer);
            app->create(buffer);
        }
        else if (buffer == "edit")
        {
            int index = 0;

            std::cout << "Which index : ";
            std::cin >> index;
            std::cout << "What the new value is : ";
            std::cin.ignore();
            std::getline(std::cin, buffer);
            app->update(index, buffer);
        }
        else if (buffer == "toggle")
        {
            int index = 0;
            std::cout << "Which index : ";
            std::cin >> index;
            std::cout << "\n";
            app->toggleFinish(index);
            std::cin.ignore();
        }
        else if (buffer == "delete")
        {
            int index = 0;
            std::cout << "Which index : ";
            std::cin >> index;
            std::cout << "\n";
            app->destroy(index);
            std::cin.ignore();
        }
        else if (buffer == "print")
        {
            app->printLists();
        }
        else if (buffer == "clear")
        {
            clearScreen();
        }

        if (buffer == "exit")
            break;
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
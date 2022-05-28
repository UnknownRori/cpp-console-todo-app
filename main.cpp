#include <iostream>
#include <chrono>
#include <thread>
#include "include/TodoApp.h"

void clearScreen();
void pause();

int main()
{
    TodoApp *App = new TodoApp();
    App->create("Cook something");
    App->create("Do some coding");
    App->create("Do some Bicycle");
    App->printLists();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    clearScreen();
    App->destroy(1);
    App->update(0, "Wash Something");
    App->printLists();

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
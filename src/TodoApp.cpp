#include <iostream>
#include <algorithm>
#include "../include/TodoApp.h"
#include "../include/TodoItem.h"

void TodoApp::create(std::string value)
{
    TodoLists.push_back(new TodoItem(value));
}

void TodoApp::update(int index, std::string newValue)
{
    TodoItem *todo = TodoLists.at(index);
    todo->data = newValue;
}

void TodoApp::toggleFinish(int index)
{
    TodoItem *todo = TodoLists.at(index);
    todo->finished = !todo->finished;
}

void TodoApp::destroy(int index)
{
    free(TodoLists.at(index));
    TodoLists.erase(TodoLists.begin() + index);
}

void TodoApp::printLists()
{
    int index = 0;
    for (const auto &todo : TodoLists)
    {
        std::cout << "No : " << index << " " << todo->data << " " << todo->finished << "\n";
        index++;
    }
}

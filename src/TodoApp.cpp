#include <iostream>
#include <algorithm>
#include <iomanip>
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
    const int indexWidth = 7;
    const int dataWidth = 64;
    const int completeWidth = 11;

    int index = 0;

    using std::setw;
    std::cout << std::left;
    std::cout << setw(indexWidth) << "[Index]" << setw(dataWidth) << "[Task]" << setw(completeWidth) << "[Complete]"
              << "\n";
    for (const auto &todo : TodoLists)
    {
        std::string finishStatus;

        if (todo->finished)
        {
            finishStatus = "V";
        }
        else
        {
            finishStatus = "X";
        }
        std::cout << setw(indexWidth) << index << setw(dataWidth) << todo->data << setw(completeWidth) << finishStatus
                  << "\n";

        // std::cout
        //     << index << " | " << todo->data << " | " << finishStatus << "\n";
        index++;
    }
}

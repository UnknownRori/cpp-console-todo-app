#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../include/TodoApp.h"
#include "../include/TodoItem.h"

bool TodoApp::checkIndex(int index)
{
    if (0 < index || index > size(TodoLists))
        return true;
    return false;
}

void TodoApp::create(std::string value)
{
    TodoLists.push_back(new TodoItem(value));
}

void TodoApp::update(int index, std::string newValue)
{
    if (checkIndex(index))
        std::cout << "Input Index should match with the data! \n";
    else
    {
        TodoItem *todo = TodoLists.at(index);
        todo->data = newValue;
    }
}

void TodoApp::toggleFinish(int index)
{
    if (checkIndex(index))
        std::cout << "Input Index should match with the data! \n";
    else
    {
        TodoItem *todo = TodoLists.at(index);
        todo->finished = !todo->finished;
    }
}

void TodoApp::destroy(int index)
{
    if (checkIndex(index))
        std::cout << "Input Index should match with the data! \n";
    else
    {
        free(TodoLists.at(index));
        TodoLists.erase(TodoLists.begin() + index);
    }
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
        index++;
    }
}

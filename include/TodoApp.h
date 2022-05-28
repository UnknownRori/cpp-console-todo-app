#ifndef TODO_APP_H
#define TODO_APP_H

#include <vector>
#include "TodoItem.h"

class TodoApp
{
    std::vector<TodoItem> TodoLists;

public:
    TodoApp();
    bool create(std::string);
    bool update(int, std::string);
    bool finish(int);
    bool unfinish(int);
    bool destroy(int);
    void printLists();
};

#endif
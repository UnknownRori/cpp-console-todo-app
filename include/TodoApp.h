#ifndef TODO_APP_H
#define TODO_APP_H

#include <vector>
#include "TodoItem.h"

class TodoApp
{
    std::vector<TodoItem> TodoLists;

public:
    TodoApp();
    void create(std::string);
    void update(int, std::string);
    void finish(int);
    void unfinish(int);
    void destroy(int);
    void printLists();
};

#endif
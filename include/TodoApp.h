#ifndef TODO_APP_H
#define TODO_APP_H

#include <vector>
#include "TodoItem.h"

class TodoApp
{
    std::vector<TodoItem *> TodoLists;

public:
    void create(std::string);
    void update(int, std::string);
    void toggleFinish(int);
    void destroy(int);
    void printLists();
};

#endif
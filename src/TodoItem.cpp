#include <string>
#include "../include/TodoItem.h"

TodoItem::TodoItem(std::string value)
{
    data = value;
    finished = false;
}
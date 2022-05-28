TARGET = main.cpp

BUILD_TARGET = main

LIBS = src/TodoApp.cpp src/TodoItem.cpp

COMPILER = g++

all :
	$(COMPILER) $(TARGET) $(LIBS) -o $(BUILD_TARGET)
TARGET = main.cpp

BUILD_TARGET = main

LIBS = src/TodoApp.cpp src/TodoItem.cpp

COMPILER = g++

all : $(BUILD_TARGET)
	$(COMPILER) $(TARGET) $(LIBS) -o $(BUILD_TARGET)
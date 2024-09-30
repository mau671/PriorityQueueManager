#pragma once

#include "ArrayList.h"
#include <iostream>

class Menu {
private:
    ArrayList<std::string> options;
    std::string title;

public:
    Menu(const std::string& title);
    void addOption(const std::string& option);
    void display();
    int getSelection();
};

#pragma once

#include "string"
#include "iostream"
#include "vector"
#include "map"

class InputList {
    std::vector<std::string> table;
public:
    InputList();

    void insert_item(int key, const std::string& command);
    void displayHash();
    bool find(int key);
    int count_command(const std::string& command);
    std::string getCommand(int key);
};
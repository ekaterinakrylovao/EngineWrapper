#pragma once
#include "Wrapper.h"

class Engine {
public:
    bool register_command(Wrapper* wrapper, std::string command_name) {
        if (wrappers.find(command_name) != wrappers.end()) {
            std::cout << "Attention, command \"" << command_name << "\" tried to be overridden, but it won't." << std::endl;
            return false;
        }
        wrappers[command_name] = wrapper;

        return true;
    }

    int execute(std::string command_name, const std::map<std::string, int>& arguments) {
        if (wrappers.find(command_name) != wrappers.end()) {
            return wrappers[command_name]->execute(arguments);
        }
        else {
            std::cout << "Command \"" << command_name << "\" doesn't exist, so this step will be skipped." << std::endl;
            return -1;
        }
    }

private:
    std::map<std::string, Wrapper*> wrappers;
};
#pragma once
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <map>

class Wrapper {
public:
    template<typename Subject, class... Args>
    Wrapper(Subject* subj, int(Subject::* func)(Args...), const std::map<std::string, int> args) {
        if (args.size() != sizeof...(Args)) {
            std::cout << "Error: Wrong number of arguments at the moment of wrapper setting." << std::endl;
            exit(1);
        }

        for (auto& arg : args) {
            argsNamesOrdered.push_back(arg.first);
        }
        funcl = [this, subj, func](const std::vector<int>& argsVec) {
            return call_function(subj, func, argsVec, std::index_sequence_for<Args...>{});
        };
    }

    int execute(const std::map<std::string, int>& arguments) {
        if (arguments.size() != argsNamesOrdered.size()) {
            std::cout << "Error: Wrong number of arguments." << std::endl;
            exit(1);
        }

        std::vector<int> argsFunc;
        for (const auto& argName : argsNamesOrdered) {
            argsFunc.push_back(const_cast<std::map<std::string, int>&>(arguments)[argName]);
        }

        return funcl(argsFunc);
    }

private:
    template <typename Subject, typename Method, std::size_t... I>
    int call_function(Subject* subj, Method func, const std::vector<int>& args, std::index_sequence<I...>) {
        return (subj->*func)(args[I]...);
    }

    std::function<int(const std::vector<int>& argsVec)> funcl;
    std::vector<std::string> argsNamesOrdered;
};
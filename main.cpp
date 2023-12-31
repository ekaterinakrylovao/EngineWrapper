﻿#include "Engine.h"
#include "Subject.h"

int main() {

    Subject subj;

    Wrapper wrapper(&subj, &Subject::f3, { {"arg1", 0}, {"arg2", 0} });

    Engine engine;

    engine.register_command(&wrapper, "command1");

    std::cout << engine.execute("command1", { {"arg1", 4}, {"arg2", 5} }) << std::endl;

}
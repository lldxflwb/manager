//
// Created by 48449 on 2023/1/15.
//

#include "TestAction.h"

std::shared_ptr<Manager> TestAction::MakeManager(int number) {
    return std::shared_ptr<Manager>();
}

std::string TestAction::RandomName() {
    std::string name,sex;
    DataBaseRoll(name,sex);
    return name;
}

time_t TestAction::RandomJoinTime() {
    return 0;
}

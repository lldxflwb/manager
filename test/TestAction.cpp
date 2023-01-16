//
// Created by 48449 on 2023/1/15.
//

#include "TestAction.h"
#include <chrono>
#include <ctime>
#include <iostream>
std::shared_ptr<Manager> TestAction::MakeManager(int number) {
    std::cout << "生成用户中";
    START_TIMER
    std::shared_ptr<Manager> manager = std::make_shared<Manager>();
    manager->user->reserve(number);
    for (int i = 0; i < number; ++i) {
        // id 自生成
        manager->user->push_back(User(RandomName(),RandomJoinTime()));
//        std::cout << "生成用户:" << tmp << std::endl;
    }
    std::cout << "生成用户结束" << std::endl;
    STOP_TIMER
    return manager;
}

std::string TestAction::RandomName() {
    std::string name,sex;
    DataBaseRoll(name,sex);
    return name;
}

time_t TestAction::RandomJoinTime() {
    std::tm date = {};
    date.tm_year = RandomRange(1998,2022) - 1900;
    date.tm_mon = RandomRange(0,11);
    date.tm_mday = RandomRange(1,28);
    date.tm_hour = 12;
    date.tm_min = 30;
    // 将日期转换为时间戳
    auto timestamp = std::chrono::system_clock::from_time_t(std::mktime(&date));
    auto time = std::chrono::system_clock::to_time_t(timestamp);
    return time;
}

int TestAction::RandomRange(int start_no, int end_no) {
    return rand()%(end_no-start_no+1)+start_no;
}

//
// Created by 48449 on 2023/1/15.
//

#include "PeopleInterface.h"

PeopleInterface::PeopleInterface() {
    id= nullptr;
    user_name = nullptr;
    join_time = nullptr;
}

PeopleInterface::PeopleInterface(int id , std::string name , time_t join_time) {
    this->id = std::make_shared<int>(id);
    this->user_name = std::make_shared<std::string>(name);
    this->join_time = std::make_shared<time_t>(join_time);
}

int PeopleInterface::get_next_id() {
    static int max_id = 1 ;
    return max_id ++;
}

PeopleInterface::PeopleInterface(std::string name, time_t join_time) {
    this->id = std::make_shared<int>(get_next_id());
    this->user_name = std::make_shared<std::string>(name);
    this->join_time = std::make_shared<time_t>(join_time);
}

const std::shared_ptr<int> &PeopleInterface::getId() const {
    return id;
}

void PeopleInterface::setId(int id) {
    (*PeopleInterface::id) = id;
}

const std::shared_ptr<time_t> &PeopleInterface::getJoinTime() const {
    return join_time;
}

void PeopleInterface::setJoinTime(time_t joinTime) {
    *join_time = joinTime;
}

const std::shared_ptr<std::string> &PeopleInterface::getUserName() const {
    return user_name;
}

void PeopleInterface::setUserName(std::string userName) {
    *user_name = userName;
}

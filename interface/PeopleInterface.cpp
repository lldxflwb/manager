//
// Created by 48449 on 2023/1/15.
//

#include "PeopleInterface.h"
#include <iostream>

PeopleInterface::PeopleInterface() {
    id= nullptr;
    user_name = nullptr;
    join_time = nullptr;
}

PeopleInterface::PeopleInterface(int id , std::string name , time_t join_time) {
    this->id = std::make_shared<IDTYPE>(id);
    this->user_name = std::make_shared<std::string>(name);
    this->join_time = std::make_shared<time_t>(join_time);
}

int PeopleInterface::get_next_id() {
    static IDTYPE max_id = 1 ;
    return max_id ++;
}

PeopleInterface::PeopleInterface(std::string name, time_t join_time) {
    this->id = std::make_shared<IDTYPE>(get_next_id());
    this->user_name = std::make_shared<std::string>(name);
    this->join_time = std::make_shared<time_t>(join_time);
}

const std::shared_ptr<IDTYPE> &PeopleInterface::getId() const {
    return id;
}

void PeopleInterface::setId(IDTYPE id) {
    if ( this->id == nullptr ){
        this->id = std::make_shared<IDTYPE>();
    }
    (*PeopleInterface::id) = id;
}

const std::shared_ptr<time_t> &PeopleInterface::getJoinTime() const {
    return join_time;
}

void PeopleInterface::setJoinTime(time_t joinTime) {
    if ( this->join_time == nullptr ){
        this->join_time = std::make_shared<time_t>();
    }
    *join_time = joinTime;
}

const std::shared_ptr<std::string> &PeopleInterface::getUserName() const {
    return user_name;
}

void PeopleInterface::setUserName(std::string userName) {
    if ( this->user_name == nullptr ){
        this->user_name = std::make_shared<std::string>();
    }
    *user_name = userName;
}

std::shared_ptr<PeopleInterface> PeopleInterface::clone() {
    return std::make_shared<PeopleInterface>((*this->id),*(this->user_name),*(this->join_time));
}

std::ostream &operator<<(std::ostream &os, const PeopleInterface &anInterface) {
    os << "id: " << *anInterface.id << " join_time: " << *anInterface.join_time << " user_name: "
       << *anInterface.user_name;
    return os;
}

PeopleInterface::~PeopleInterface() {
    if (this->id){
        this->id.reset();
        this->id = nullptr;
    }
    if (this->join_time){
        this->join_time.reset();
        this->join_time = nullptr;
    }
    if (this->user_name){
        this->user_name.reset();
        this->user_name = nullptr;
    }
}

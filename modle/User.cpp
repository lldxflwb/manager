//
// Created by 48449 on 2023/1/15.
//

#include "User.h"

User::User(const std::string &name, time_t joinTime) : PeopleInterface(name, joinTime) {}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << static_cast<const PeopleInterface &>(user);
    return os;
}

std::shared_ptr<PeopleInterface> User::clone() {
    auto c = std::make_shared<User>(std::move(*PeopleInterface::clone()));
    c->ref = ref;
    return c;
}

User::User(PeopleInterface &&p) : PeopleInterface(p){
    ref = nullptr;
}
#include <iostream>
User::~User() {
}

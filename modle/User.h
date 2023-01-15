//
// Created by 48449 on 2023/1/15.
//

#ifndef MANAGER_USER_H
#define MANAGER_USER_H

#include <ostream>
#include "../interface/PeopleInterface.h"

class User : public PeopleInterface{
public:
    User(const std::string &name, time_t joinTime);

    friend std::ostream &operator<<(std::ostream &os, const User &user);
};


#endif //MANAGER_USER_H

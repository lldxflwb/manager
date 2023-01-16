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
    virtual std::shared_ptr<PeopleInterface> clone() override;
    friend std::ostream &operator<<(std::ostream &os, const User &user);
    User(PeopleInterface && p);
};


#endif //MANAGER_USER_H

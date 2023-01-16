//
// Created by 48449 on 2023/1/16.
//

#include "Manager.h"

Manager::Manager() {
    users = std::make_shared<std::vector<User>>();
    name_tree = std::make_shared<NameTree>();
    number_tree = std::make_shared<NumberTree>();
    multi_number_tree = std::make_shared<MultiNumberTree>();
}

int Manager::AddUser(User &user) {
    Ecode e = Ecode::insert_error;
    this->users->push_back(user);
    e = name_tree->add_son(&user);
    if (e != success ){
        std::exit(-1);
    }
    e = number_tree->add_son(&user);
    if (e != success ){
        std::exit(-1);
    }
    e = multi_number_tree->add_son(&user);
    if (e != success ){
        std::exit(-1);
    }
    return e;
}

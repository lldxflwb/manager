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
    auto iter = this->users->insert(this->users->end(),user);
    (*iter).ref = iter;
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

int Manager::DeleteUser(IDTYPE id) {
    Ecode e = Ecode::insert_error;
    PeopleInterface u;
    u.setId(id);
    auto ret = number_tree->get_user(&u);
    if ( ret == nullptr ){
        std::exit(-1);
    }
    std::shared_ptr<User> user = std::dynamic_pointer_cast<User>(ret);
    e = name_tree->delete_son(user.get());
    if (e != success){
        std::exit(-1);
    }
    e = number_tree->delete_son(user.get());
    if (e != success){
        std::exit(-1);
    }
    e = multi_number_tree->delete_son(user.get());
    if (e != success){
        std::exit(-1);
    }
    users->erase(user->ref);
}

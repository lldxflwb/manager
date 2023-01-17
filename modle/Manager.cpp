//
// Created by 48449 on 2023/1/16.
//

#include "Manager.h"
#include <iostream>
Manager::Manager() {
    users = std::make_shared<UserSaveList>();
    name_tree = std::make_shared<NameTree>();
    number_tree = std::make_shared<NumberTree>();
    multi_number_tree = std::make_shared<MultiNumberTree>();
}

int Manager::AddUser(User &user) {
    Ecode e = Ecode::insert_error;
    auto iter = this->users->push_back(user);
    std::shared_ptr<User> u_ptr = std::dynamic_pointer_cast<User>(iter->user);
    u_ptr->ref = iter;
    e = name_tree->add_son(u_ptr.get());
    if (e != success ){
        std::cerr << "添加用户到 名称树错误 ， " << user <<std::endl;
        std::exit(-1);
    }
    e = number_tree->add_son(u_ptr.get());
    if (e != success ){
        std::cerr << "添加用户到 id树错误 ， " << user<<std::endl;
        std::exit(-1);
    }
    e = multi_number_tree->add_son(u_ptr.get());
    if (e != success ){
        std::cerr << "添加用户到 时间树错误 ， " << user<<std::endl;
        auto vec = multi_number_tree->get_order(0);
        for(auto item : *vec){
            std::cout << *item << std::endl;
        }
        std::exit(-1);
    }
    return e;
}

int Manager::DeleteUser(IDTYPE id) {
    Ecode e = Ecode::insert_error;
    PeopleInterface u;
    u.setId(id);
//    std::cout << "查找用户:" <<id << std::endl;
    auto ret = number_tree->get_user(&u);
//    std::cout << "查找用户成功" << std::endl;
    if ( ret == nullptr ){
        std::exit(-1);
    }
    std::shared_ptr<User> user = std::dynamic_pointer_cast<User>(ret);
//    std::cout << "删除 名称分支" << std::endl;
    e = name_tree->delete_son(user.get());
//    std::cout << "删除 名称分支成功" << std::endl;
    if (e != success){
        std::exit(-1);
    }
//    std::cout << "删除 id分支" << std::endl;
    e = number_tree->delete_son(user.get());
//    std::cout << "删除 id分支成功" << std::endl;
    if (e != success){
        std::exit(-1);
    }
//    std::cout << "删除 join_time分支" << std::endl;
    e = multi_number_tree->delete_son(user.get());
//    std::cout << "删除 join_time分支分支成功" << std::endl;
    if (e != success){
        std::exit(-1);
    }
    return users->delete_node(user->ref);
}

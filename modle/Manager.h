//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_MANAGER_H
#define MANAGER_MANAGER_H
#include "../tree/NameTree.h"
#include "../tree/MultiNumberTree.h"
#include "../tree/NumberTree.h"
#include "User.h"
#include <list>
#include <vector>
#include "UserSaveList.h"
class Manager {

public:
    std::shared_ptr<UserSaveList> users;
    std::shared_ptr<NameTree> name_tree;
    std::shared_ptr<NumberTree> number_tree;
    std::shared_ptr<MultiNumberTree> multi_number_tree;
    Manager();
    int AddUser(User & user );
    int DeleteUser( IDTYPE id );
};

#endif //MANAGER_MANAGER_H

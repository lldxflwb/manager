//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_MANAGER_H
#define MANAGER_MANAGER_H
#include "../tree/NameTree.h"
#include "../tree/MultiNumberTree.h"
#include "../tree/NumberTree.h"
#include "User.h"
#include <vector>
class Manager {
    std::shared_ptr<std::vector<User>> users;
    std::shared_ptr<NameTree> name_tree;
    std::shared_ptr<NumberTree> number_tree;
    std::shared_ptr<MultiNumberTree> multi_number_tree;
public:
    Manager();
    int AddUser(User & user );
};

#endif //MANAGER_MANAGER_H

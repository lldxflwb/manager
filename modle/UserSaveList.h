//
// Created by 48449 on 2023/1/17.
//

#ifndef MANAGER_USERSAVELIST_H
#define MANAGER_USERSAVELIST_H

#include "../interface/PeopleInterface.h"

class Node{
public:
    std::shared_ptr<PeopleInterface> user;
    Node * next_node , * pre_node;
    Node();
};

class UserSaveList {
public:
    Node * begin_node, * end_node;
    Node * push_back(PeopleInterface & user);
    bool delete_node(Node * node);
    Node * insert_node(Node * pos , PeopleInterface & user);
    UserSaveList();

    virtual ~UserSaveList();
};


#endif //MANAGER_USERSAVELIST_H

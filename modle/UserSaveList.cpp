//
// Created by 48449 on 2023/1/17.
//

#include "UserSaveList.h"

Node::Node() {
    this->user = nullptr;
    this->next_node = nullptr;
    this->pre_node = nullptr;
}

Node *UserSaveList::push_back(PeopleInterface & user) {
    return this->insert_node(end_node,user);
}
//#include <iostream>
bool UserSaveList::delete_node(Node *node) {
//    std::cout << "删除节点" << std::endl;
    if (node->pre_node == node){
        return false;
    }
    else if( node->next_node == node){
        return false;
    }
    node->pre_node->next_node = node->next_node;
    node->next_node->pre_node = node->pre_node;
    delete node;
    return true;
}

UserSaveList::UserSaveList() {
    begin_node = new Node();
    end_node = new Node();
    begin_node->next_node = end_node;
    begin_node->pre_node = begin_node;
    end_node->next_node = end_node;
    end_node->pre_node = begin_node;
}

Node *UserSaveList::insert_node(Node *pos, PeopleInterface & user) {
    Node * node = new Node();
    node->user = user.clone();
    if ( pos->pre_node == pos){
        // 如果是begin begin不动 begin不保存数据 begin就是开头
        pos->next_node->pre_node = node;
        node->next_node=pos->next_node;
        pos->next_node = node;
        node->pre_node = pos;
    }
    else if( pos->next_node == pos){
        // 如果是end
        // 看看开头是否是begin
        node->pre_node = pos->pre_node;
        node->next_node = pos;
        node->pre_node->next_node = node;
        node->next_node->pre_node = node;
    }else{
        auto start_node = pos->pre_node;
        auto end_node = pos->next_node;
        node->pre_node=start_node;
        node->next_node = end_node;
        start_node->next_node = node;
        end_node->pre_node=node;
    }
    return node;
}

UserSaveList::~UserSaveList() {
    auto iter = begin_node;
    auto last_iter = iter;
    do{
        iter = last_iter->next_node;
        delete last_iter;
        last_iter = iter;
    } while (last_iter!=end_node);
    delete end_node;
}

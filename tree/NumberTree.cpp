//
// Created by 48449 on 2023/1/16.
//

#include "NumberTree.h"

Ecode NumberTree::add_son(PeopleRef people) {
    return insert_error;
}

Ecode NumberTree::delete_son(PeopleRef people) {
    return insert_error;
}

std::shared_ptr<PeopleInterface> NumberTree::get_user(PeopleRef people) {
    return std::shared_ptr<PeopleInterface>();
}

std::shared_ptr<std::vector<PeopleInterface>> NumberTree::get_peoples(PeopleRef people) {
    return std::shared_ptr<std::vector<PeopleInterface>>();
}

std::shared_ptr<std::vector<PeopleInterface>> NumberTree::get_order(int order) {
    return std::shared_ptr<std::vector<PeopleInterface>>();
}

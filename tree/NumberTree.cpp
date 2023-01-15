//
// Created by 48449 on 2023/1/16.
//

#include "NumberTree.h"

Ecode NumberTree::add_son(PeopleRef people) {
    if (AddSon(people,*people->getId())){
        return success;
    }
    return Ecode::insert_error;
}

Ecode NumberTree::delete_son(PeopleRef people) {
    if (people->getId() == nullptr){
        return Ecode::no_id;
    }
    if (this->DeleteSon(people,*people->getId())){
        return success;
    }
    return delete_error;
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

int NumberTree::AddSon(PeopleRef people, IDTYPE id) {
    if ( id == 0 ) {
        if ( user != nullptr ) {
            return false;
        }
        user = people;
        return true;
    }
    if ( son == nullptr ) {
        son = new NumberTree*[NUMBER_TREE_MAX_NUMBER];
    }
    int index = id % NUMBER_TREE_MAX_NUMBER;
    if ( son[index] == nullptr ) {
        son[index] = new NumberTree();
    }
    bool flag_result = son[index]->AddSon(user,id/NUMBER_TREE_MAX_NUMBER);
    if ( flag_result ){
        son_sum ++ ;
        return true;
    }
    return false;
}

int NumberTree::DeleteSon(PeopleRef people, IDTYPE id) {
    if ( id == 0 ) {
        if ( user !=nullptr ) {
            if ( (*user->getId()) == (*people->getId())){
                user = nullptr;
                return true;
            }
            return false;
        }
        return false;
    }
    if (son==nullptr){
        return false;
    }
    if (son_sum == 0){
        return false;
    }
    int index = id % NUMBER_TREE_MAX_NUMBER;
    if ( son[index]== nullptr){
        return false;
    }
    bool flag_result = DeleteSon(people,id/NUMBER_TREE_MAX_NUMBER);
    if ( flag_result ){
        son_sum--;
        return true;
    }
    return false;
}

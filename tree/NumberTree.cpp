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
    if (people->getId() == nullptr){
        return nullptr;
    }
    return FindUserByID(*people->getId());
}

std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> NumberTree::get_peoples(PeopleRef people) {
    if (people->getId() == nullptr){
        return nullptr;
    }
    auto result = FindUserByID(*people->getId());
    if (result == nullptr){
        return nullptr;
    }
    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> vec = std::make_shared<std::vector<std::shared_ptr<PeopleInterface>>>();
    vec->push_back(result);
    return vec;
}

std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> NumberTree::get_order(int order) {
    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result = std::make_shared<std::vector<std::shared_ptr<PeopleInterface>>>();
    this->OrderInfo(result,order);
    return result;
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

void NumberTree::OrderInfo(std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result, int method) {
    if (son != nullptr) {
        if(method == 0 ){
            for( int i = 0 ; i < NUMBER_TREE_MAX_NUMBER ; i ++ ) {
                auto item = son[i];
                if ( item!= nullptr ) {
                    item->OrderInfo(result,method);
                }
            }
            if (user != nullptr) {
                result->push_back(user->clone());
            }
        }
        else{
            if (user != nullptr) {
                result->push_back(user->clone());
            }
            for( int i = NUMBER_TREE_MAX_NUMBER ; i >= 0 ; i -- ) {
                auto item = son[i];
                if ( item!= nullptr ) {
                    item->OrderInfo(result,method);
                }
            }
        }

    }
    else {
        if (user != nullptr) {
            result->push_back(user->clone());
        }
    }
}

std::shared_ptr<PeopleInterface> NumberTree::FindUserByID(IDTYPE id) {
    if ( id == 0 ) {
        if ( user != nullptr ) {
            return nullptr;
        }
        return user->clone();
    }
    if ( son == nullptr ) {
        return nullptr;
    }
    int index = id % NUMBER_TREE_MAX_NUMBER;
    if ( son[index] == nullptr ) {
        return nullptr;
    }
    return son[index]->FindUserByID(id/NUMBER_TREE_MAX_NUMBER);
}

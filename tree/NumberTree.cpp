//
// Created by 48449 on 2023/1/16.
//

#include "NumberTree.h"
#include <stack>
Ecode NumberTree::add_son(PeopleRef people) {
    IDTYPE id = *people->getId();
    auto q = GetIDs(id);
    if (AddSon(people,q)){
        return success;
    }
    return Ecode::insert_error;
}

Ecode NumberTree::delete_son(PeopleRef people) {
    if (people->getId() == nullptr){
        return Ecode::no_id;
    }
    auto q = GetIDs(*people->getId());
    if (this->DeleteSon(people,q)){
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

int NumberTree::AddSon(PeopleRef people, std::queue<int> &st) {
    if (st.empty() ) {
        if ( user != nullptr ) {
            return false;
        }
        user = people;
        return true;
    }
    if ( son == nullptr ) {
        son = new NumberTree*[NUMBER_TREE_MAX_NUMBER];
        for (int i = 0; i < NUMBER_TREE_MAX_NUMBER; ++i) {
            son[i] = nullptr;
        }
    }
    int index = st.front();
    st.pop();
    if ( son[index] == nullptr ) {
        son[index] = new NumberTree();
    }
    bool flag_result = son[index]->AddSon(people, st );
    if ( flag_result ){
        son_sum ++ ;
        return true;
    }
    return false;
}

int NumberTree::DeleteSon(PeopleRef people, std::queue<int> id) {
    if ( id.empty() ) {
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
    int index = id.front();
    id.pop();
    if ( son[index]== nullptr){
        return false;
    }
    bool flag_result = son[index]->DeleteSon(people,id);
    if ( flag_result ){
        son_sum--;
        return true;
    }
    return false;
}

void NumberTree::OrderInfo(std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result, int method) {
    if (son != nullptr) {
        if(method == 0 ){
            if (user != nullptr) {
                result->push_back(user->clone());
            }
            for( int i = 0 ; i < NUMBER_TREE_MAX_NUMBER ; i ++ ) {
                auto item = son[i];
                if ( item!= nullptr ) {
                    item->OrderInfo(result,method);
                }
            }

        }
        else{
            for( int i = NUMBER_TREE_MAX_NUMBER - 1 ; i >= 0 ; i -- ) {
                auto item = son[i];
                if ( item!= nullptr ) {
                    item->OrderInfo(result,method);
                }
            }
            if (user != nullptr) {
                result->push_back(user->clone());
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

std::queue<int> NumberTree::GetIDs(IDTYPE id) {
    std::queue<int> q;
    int deep = GetMaxDeep();
    int number_deep = GetMaxDeep(id);
    deep-=number_deep;
    while (deep--){
        q.push(0);
    }
    std::stack<int> st;
    while(id){
        st.push(id%NUMBER_TREE_MAX_NUMBER);
        id/=NUMBER_TREE_MAX_NUMBER;
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return std::move(q);
}

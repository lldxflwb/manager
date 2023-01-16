//
// Created by 48449 on 2023/1/16.
//

#include "MultiNumberTree.h"
#include <stack>

Ecode MultiNumberTree::add_son(PeopleRef people) {
    auto q = GetIDs(*people->getJoinTime());
    if (AddSon(people,q)){
        return success;
    }
    return Ecode::insert_error;
}

Ecode MultiNumberTree::delete_son(PeopleRef people) {
    if (people->getJoinTime() == nullptr){
        return Ecode::no_join_time;
    }
    if (people->getId() == nullptr){
        return Ecode::no_id;
    }
    auto q = GetIDs(*people->getJoinTime());
    if (this->DeleteSon(people,q)){
        return success;
    }
    return delete_error;
}

std::shared_ptr<PeopleInterface> MultiNumberTree::get_user(PeopleRef people) {
    auto q = GetIDs((*(people->getJoinTime())));
    return FindUserByJoinTimeAndID(people, q);
}

std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> MultiNumberTree::get_peoples(PeopleRef people) {
    auto q = GetIDs((*(people->getJoinTime())));
    return FindUsersByJoinTime(people,q);
}

std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> MultiNumberTree::get_order(int order) {
    auto result = std::make_shared< std::vector< std::shared_ptr<PeopleInterface> > > ();
    OrderInfo(result,order);
    return result;
}

int MultiNumberTree::AddSon(PeopleRef people, std::queue<int> &q) {
    if (q.empty() ) {
        if ( users == nullptr ) {
            users = std::make_shared<std::vector<PeopleRef>>();
        }
        // 校验是否加入，使用id
        for(auto & item : *users ){
            if ((*(item->getId())) == (*(people->getId()))){
                return false;
            }
        }
        users->push_back(people);
        return true;
    }
    if ( son == nullptr ) {
        son = new MultiNumberTree*[MULTI_NUMBER_TREE_MAX_NUMBER];
        for (int i = 0; i < MULTI_NUMBER_TREE_MAX_NUMBER; ++i) {
            son[i] = nullptr;
        }
    }
    int index = q.front();
    q.pop();
    if ( son[index] == nullptr ) {
        son[index] = new MultiNumberTree();
    }
    bool flag_result = son[index]->AddSon(people, q );
    if ( flag_result ){
        son_sum ++ ;
        return true;
    }
    return false;
}

std::queue<int> MultiNumberTree::GetIDs(IDTYPE id) {
    std::queue<int> q;
    int deep = GetMaxDeep();
    int number_deep = GetMaxDeep(id);
    deep-=number_deep;
    while (deep--){
        q.push(0);
    }
    std::stack<int> st;
    while(id){
        st.push(id%MULTI_NUMBER_TREE_MAX_NUMBER);
        id/=MULTI_NUMBER_TREE_MAX_NUMBER;
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    return std::move(q);
}

int MultiNumberTree::DeleteSon(PeopleRef people, std::queue<int> &q) {
    if ( q.empty() ) {
        if ( users ==nullptr ) {
            return false;
        }
        for( auto iter = (*users).begin(); iter != users->end() ; iter ++ ){
            if ( (*((*iter)->getId())) == (*(people->getId())) ){
                users->erase(iter);
                return true;
            }
        }
        return false;
    }
    if (son==nullptr){
        return false;
    }
    if (son_sum == 0){
        return false;
    }
    int index = q.front();
    q.pop();
    if ( son[index]== nullptr){
        return false;
    }
    bool flag_result = son[index]->DeleteSon(people,q);
    if ( flag_result ){
        son_sum--;
        return true;
    }
    return false;
}

std::shared_ptr<PeopleInterface> MultiNumberTree::FindUserByJoinTimeAndID(PeopleRef people, std::queue<int> &q) {
    if ( q.empty() ) {
        if ( users ==nullptr ) {
            return nullptr;
        }
        for( auto iter = (*users).begin(); iter != users->end() ; iter ++ ){
            if ( (*((*iter)->getId())) == (*(people->getId())) ){
                return (*iter)->clone();
            }
        }
        return nullptr;
    }
    if (son==nullptr){
        return nullptr;
    }
    if (son_sum == 0){
        return nullptr;
    }
    int index = q.front();
    q.pop();
    if ( son[index]== nullptr){
        return nullptr;
    }
    return son[index]->FindUserByJoinTimeAndID(people,q);
}

std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>>
MultiNumberTree::FindUsersByJoinTime(PeopleRef people, std::queue<int> &q) {
    if ( q.empty() ) {
        if ( users ==nullptr ) {
            return nullptr;
        }
        std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result = std::make_shared
                <std::vector<std::shared_ptr<PeopleInterface> > >() ;
        for( auto & item : * users){
            result->push_back(item->clone());
        }
        return result;
    }
    if (son==nullptr){
        return nullptr;
    }
    if (son_sum == 0){
        return nullptr;
    }
    int index = q.front();
    q.pop();
    if ( son[index]== nullptr){
        return nullptr;
    }
    return son[index]->FindUsersByJoinTime(people,q);
}

void MultiNumberTree::OrderInfo(std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result, int method) {
    if (son != nullptr) {
        if(method == 0 ){
            if (users != nullptr) {
                for ( int i = 0 ; i < users->size() ; i ++ ){
                    auto item = (*users)[i];
                    result->push_back(item->clone());
                }
            }
            for( int i = 0 ; i < MULTI_NUMBER_TREE_MAX_NUMBER ; i ++ ) {
                auto item = son[i];
                if ( item!= nullptr ) {
                    item->OrderInfo(result,method);
                }
            }

        }
        else{
            for( int i = MULTI_NUMBER_TREE_MAX_NUMBER - 1 ; i >= 0 ; i -- ) {
                auto item = son[i];
                if ( item!= nullptr ) {
                    item->OrderInfo(result,method);
                }
            }
            if (users != nullptr) {
                for ( int i = 0 ; i < users->size() ; i ++ ){
                    auto item = (*users)[i];
                    result->push_back(item->clone());
                }
            }
        }


    }
    else {
        if (users != nullptr) {
            for ( int i = 0 ; i < users->size() ; i ++ ){
                auto item = (*users)[i];
                result->push_back(item->clone());
            }
        }
    }
}

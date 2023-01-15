//
// Created by 48449 on 2023/1/15.
//

#include "NameTree.h"

Ecode NameTree::add_son(PeopleRef people) {
    if (people->getId() == nullptr){
        return Ecode::no_id;
    }
    if (people->getUserName() == nullptr){
        return Ecode::no_name;
    }
    if (this->AddSon(people,(*people->getUserName()).c_str(),(*people->getUserName()).length())){
        return success;
    }
    return Ecode::insert_error;
}

Ecode NameTree::delete_son(PeopleRef people) {
    if (people->getId() == nullptr){
        return Ecode::no_id;
    }
    if (people->getUserName() == nullptr){
        return Ecode::no_name;
    }
    if (this->DeleteSon(people,people->getUserName()->c_str(),people->getUserName()->length())){
        return success;
    }
    return delete_error;
}

std::shared_ptr<PeopleInterface> NameTree::get_user(PeopleRef people) {
    if (people->getId() == nullptr){
        return nullptr;
    }
    if (people->getUserName() == nullptr){
        return nullptr;
    }
    return FindUserByNameAndID(people->getUserName()->c_str(),people->getUserName()->length(),(*people->getId()));
}

std::vector<PeopleInterface> NameTree::get_peoples(PeopleRef people) {
    return *FindUserByName(people->getUserName()->c_str(),people->getUserName()->length());
}

std::vector<PeopleInterface> NameTree::get_order(int number, int order) {
    std::shared_ptr<std::vector<PeopleInterface>> result = std::make_shared<std::vector<PeopleInterface>>();
    this->OrderInfo(result,order);
    return *result;
}

int NameTree::AddSon(PeopleRef people, const char *name, int length) {
    this->son_sum ++ ;
    if (length==0){
        this->peoples->push_back(people);
        return true;
    }
    // 在这个节点放置
    if (this->son == nullptr){
        this->son = new NameTree*[16];
    }
    if (this->son[name[0]/16]== nullptr){
        this->son[name[0]/16] = new NameTree;
    }
    NameTree * tmp_root = this->son[name[0]/16];
    if (tmp_root->son == nullptr){
        tmp_root->son = new NameTree * [16];
    }
    if (tmp_root->son[name[0]%16]== nullptr){
        tmp_root->son[name[0]%16] = new NameTree;
    }
    return tmp_root->son[name[0] % 16]->AddSon(people, name + 1, length - 1);
}

int NameTree::DeleteSon(PeopleRef people, const char *name, int length) {
    if (length==0){
        // 除尽了 people在vector上面
        // 确认people是否为null
        if (peoples == nullptr ){
            return false;
        }
        if (peoples->size() == 0 ){
            return false;
        }
//        return peoples->dele;
        for (auto iter = peoples->begin(); iter != peoples->end() ; ++iter) {
            if ( (*(*iter)->getId()) == (*people->getId())){
                peoples->erase(iter);
                if (peoples->size() == 0 ){
//                    删除内容
                    delete peoples;
                    peoples = nullptr;
                }
                this->son_sum -- ;
                return true;
            }
        }
        return false;
    }
    // 需要往下走
    if (this->son == nullptr){
        // 子节点没有内容
        return false;
    }
    if (this->son[name[0]/16]== nullptr){
        // 字节的对应部分没有内容
        return false;
    }
    NameTree * tmp_root = this->son[name[0]/16];
    if (tmp_root->son == nullptr){
        // 子树没有内容
        return false;
    }
    if (tmp_root->son[name[0]%16]== nullptr){
        // 子树的子树没有内容
        return false;
    }
    // 往下继续删除
    if (DeleteSon(people,name+1,length-1)){
        this->son_sum -- ;
        return true;
    }
    return false;
}

std::shared_ptr<PeopleInterface> NameTree::FindUserByNameAndID(const char *name, int length, int id) {
    if (length==0){
        // find user in peoples
        if (peoples== nullptr){
            return nullptr;
        }
        for(auto & item : *peoples){
            if((*item->getId()) == id){
                return std::make_shared<PeopleInterface>(item->clone());
            }
        }
        return nullptr;
    }
    // 在这个节点放置
    if (this->son == nullptr){
        return nullptr;
    }
    if (this->son[name[0]/16]== nullptr){
        return nullptr;
    }
    NameTree * tmp_root = this->son[name[0]/16];
    if (tmp_root->son == nullptr){
        return nullptr;
    }
    if (tmp_root->son[name[0]%16]== nullptr){
        return nullptr;
    }
    return tmp_root->son[name[0] % 16]->FindUserByNameAndID(name + 1, length - 1,id);
}

std::shared_ptr<std::vector<PeopleInterface>> NameTree::FindUserByName(const char *name, int length) {
    if (length==0){
        // find user in peoples
        if (peoples== nullptr){
            return nullptr;
        }
        std::shared_ptr<std::vector<PeopleInterface>> result = std::make_shared<std::vector<PeopleInterface>>();
        for(auto & item : *peoples){
            result->push_back(item->clone());
        }
        return result;
    }
    // 在这个节点放置
    if (this->son == nullptr){
        return nullptr;
    }
    if (this->son[name[0]/16]== nullptr){
        return nullptr;
    }
    NameTree * tmp_root = this->son[name[0]/16];
    if (tmp_root->son == nullptr){
        return nullptr;
    }
    if (tmp_root->son[name[0]%16]== nullptr){
        return nullptr;
    }
    return tmp_root->son[name[0] % 16]->FindUserByName(name + 1, length - 1);
}

std::shared_ptr<std::vector<PeopleInterface>> NameTree::get_users(std::string name) {
    return FindUserByName(name.c_str(),name.length());
}

void NameTree::OrderInfo(std::shared_ptr<std::vector<PeopleInterface>> result, int method) {
    if (son != NULL) {
        if(method == 0 ){
            for( int i = 0 ; i < 16 ; i ++ ) {
                auto item = son[i];
                if ( item!= NULL ) {
                    item->OrderInfo(result);
                }
            }
            if (peoples != NULL) {
                for ( auto & item : *peoples) {
                    result->push_back(item->clone());
                }
            }
        }
        else{
            if (peoples != NULL) {
                for ( auto & item : *peoples) {
                    result->push_back(item->clone());
                }
            }
            for( int i = 15 ; i >= 0 ; i -- ) {
                auto item = son[i];
                if ( item!= NULL ) {
                    item->OrderInfo(result);
                }
            }
        }

    }
    else {
        if (peoples != NULL) {
            for ( auto & item : *peoples) {
                result->push_back(item->clone());
            }
        }
    }
}

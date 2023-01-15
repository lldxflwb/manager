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

PeopleInterface NameTree::get_user(PeopleRef people) {
//    return PeopleInterface(0, 0, __cxx11::basic_string());
}

std::vector<PeopleInterface> NameTree::get_peoples(PeopleRef people) {
    return std::vector<PeopleInterface>();
}

std::vector<PeopleInterface> NameTree::get_order(int number, int order) {
    return std::vector<PeopleInterface>();
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

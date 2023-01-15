//
// Created by 48449 on 2023/1/15.
//

#ifndef MANAGER_NAMETREE_H
#define MANAGER_NAMETREE_H

#include "../interface/MapTreeInterface.h"
class NameTree : MapTreeInterface{
    NameTree ** son;
    std::vector<PeopleRef> * peoples;
    int son_sum;
    int AddSon(PeopleRef people, const char *name, int length);
    int DeleteSon(PeopleRef people , const char *name , int length);
    std::shared_ptr<PeopleInterface> FindUserByNameAndID(const char *name , int length , int id);
    std::shared_ptr<std::vector<PeopleInterface>> FindUserByName(const char *name, int length );
    void OrderInfo(std::shared_ptr<std::vector<PeopleInterface>> result , int method = 0 );
public:
    NameTree();

    Ecode add_son(PeopleRef people) override;

    Ecode delete_son(PeopleRef people) override;

    std::shared_ptr<PeopleInterface> get_user(PeopleRef people) override;

    std::shared_ptr<std::vector<PeopleInterface>> get_users(std::string name);

    std::shared_ptr<std::vector<PeopleInterface>> get_peoples(PeopleRef people) override;

    std::shared_ptr<std::vector<PeopleInterface>> get_order(int number, int order) override;
};


#endif //MANAGER_NAMETREE_H

//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_NUMBERTREE_H
#define MANAGER_NUMBERTREE_H
#include "../modle/User.h"
#include "../interface/MapTreeInterface.h"
#define NUMBER_TREE_MAX_NUMBER 5l

class NumberTree : public MapTreeInterface{
    NumberTree ** son;
    PeopleRef user;
    int son_sum;
    int AddSon(PeopleRef people, IDTYPE id);
    int DeleteSon(PeopleRef people , IDTYPE id);
//    std::shared_ptr<PeopleInterface> FindUserByNameAndID(const char *name , int length , int id);
//    std::shared_ptr<std::vector<PeopleInterface>> FindUserByName(const char *name, int length );
    void OrderInfo(std::shared_ptr<std::vector<PeopleInterface>> result , int method = 0 );
public:
    Ecode add_son(PeopleRef people) override;

    Ecode delete_son(PeopleRef people) override;

    std::shared_ptr<PeopleInterface> get_user(PeopleRef people) override;

    std::shared_ptr<std::vector<PeopleInterface>> get_peoples(PeopleRef people) override;

    std::shared_ptr<std::vector<PeopleInterface>> get_order(int order) override;
};


#endif //MANAGER_NUMBERTREE_H

//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_NUMBERTREE_H
#define MANAGER_NUMBERTREE_H
#include "../modle/User.h"
#include "../interface/MapTreeInterface.h"
#define NUMBER_TREE_MAX_NUMBER 5l
#define SAVE_MAX_NUMBER 100000000l
#include <queue>
class NumberTree : public MapTreeInterface{
    NumberTree ** son;
    PeopleRef user;
    int son_sum;
    int AddSon(PeopleRef people, std::queue<int> &st);
    int DeleteSon(PeopleRef people , IDTYPE id);
    std::shared_ptr<PeopleInterface> FindUserByID(IDTYPE id );
    void OrderInfo(std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result , int method = 0 );
    constexpr int GetMaxDeep() {
        auto max_number = SAVE_MAX_NUMBER;
        int cnts = 0;
        while(max_number){
            max_number/=NUMBER_TREE_MAX_NUMBER;
            cnts++;
        }
        return cnts;
    }
    int GetMaxDeep(IDTYPE id){
        int cnts = 0;
        while(id){
            id/=NUMBER_TREE_MAX_NUMBER;
            cnts++;
        }
        return cnts;
    }
public:
    Ecode add_son(PeopleRef people) override;

    Ecode delete_son(PeopleRef people) override;

    std::shared_ptr<PeopleInterface> get_user(PeopleRef people) override;

    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> get_peoples(PeopleRef people) override;

    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> get_order(int order) override;
};


#endif //MANAGER_NUMBERTREE_H

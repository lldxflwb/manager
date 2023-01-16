//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_MULTINUMBERTREE_H
#define MANAGER_MULTINUMBERTREE_H
#include "../modle/User.h"
#include "../interface/MapTreeInterface.h"
#define MULTI_NUMBER_TREE_MAX_NUMBER 5l
#define MULTI_SAVE_MAX_NUMBER 1000000000l
#include <queue>

class MultiNumberTree : public MapTreeInterface {
    MultiNumberTree ** son;
    std::shared_ptr<std::vector<PeopleRef> > users;
    int son_sum;
    int AddSon(PeopleRef people, std::queue<int> &q);
    int DeleteSon(PeopleRef people, std::queue<int> & q);
    void OrderInfo(std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> result , int method = 0 );
    constexpr int GetMaxDeep() {
        auto max_number = MULTI_SAVE_MAX_NUMBER;
        int cnts = 0;
        while(max_number){
            max_number/=MULTI_NUMBER_TREE_MAX_NUMBER;
            cnts++;
        }
        return cnts;
    }
    int GetMaxDeep(IDTYPE id){
        int cnts = 0;
        while(id){
            id/=MULTI_NUMBER_TREE_MAX_NUMBER;
            cnts++;
        }
        return cnts;
    }
    std::queue<int> GetIDs(IDTYPE id);
    std::shared_ptr<PeopleInterface> FindUserByJoinTimeAndID(PeopleRef people,std::queue<int> & q );
    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> FindUsersByJoinTime( PeopleRef people , std::queue<int> & q);
public:
    MultiNumberTree() {
        son = nullptr;
        son_sum = 0 ;
        users = nullptr;
    }

    Ecode add_son(PeopleRef people) override; // ok

    Ecode delete_son(PeopleRef people) override; // ok

    std::shared_ptr<PeopleInterface> get_user(PeopleRef people) override; // ok

    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> get_peoples(PeopleRef people) override; // ok

    std::shared_ptr<std::vector<std::shared_ptr<PeopleInterface>>> get_order(int order) override;
};


#endif //MANAGER_MULTINUMBERTREE_H

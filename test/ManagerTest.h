//
// Created by 48449 on 2023/1/17.
//

#ifndef MANAGER_MANAGERTEST_H
#define MANAGER_MANAGERTEST_H

#include "TestAction.h"
#include "../modle/Manager.h"

class ManagerTest {
    std::shared_ptr<Manager> manager ;
    std::vector<IDTYPE> ids;
public:
    ManagerTest() {
        manager = std::make_shared<Manager>();
        ids.clear();
    }


    void test() {
        std::cout << "---------------- 开始测试 管理中心 ----------------" << std::endl;
        insert_test();
        query_test();
    }
    void insert_test() {
        std::cout << "------------- 管理中心 生成用户中  -------------"<< std::endl;
        START_TIMER
        for (int i = 0; i < 1000000; ++i) {
            // id 自生成
            User tmp(TestAction::RandomName(),TestAction::RandomJoinTime());
            manager->AddUser(tmp);
            ids.push_back(*tmp.getId());
        }
        std::cout << "------------- 管理中心 生成用户结束 -------------" << std::endl;
        STOP_TIMER
    }

    void query_test() {
        START_TIMER
        std::cout << "------------- 管理中心 删除用户开始 -------------" << std::endl;
        for(auto id : ids){
            if(!manager->DeleteUser(id)){
                std::cerr << " 删除错误 !";
                exit(-1);
            }
        }
        std::cout << "------------- 管理中心 删除用户结束 -------------" << std::endl;
        STOP_TIMER
    }
};


#endif //MANAGER_MANAGERTEST_H

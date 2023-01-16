//
// Created by 48449 on 2023/1/15.
//

#include "NameTreeTest.h"
#include "TestAction.h"

void NameTreeTest::test() {
    std::cout << "---------------- 开始测试 名称索引 ----------------" << std::endl;
    insert_test();
    query_test();
}

void NameTreeTest::insert_test() {
    std::cout << "开始插入，插入用户数量为：" << manager->user->size() << std::endl;
    START_TIMER
    for (auto & item : *((*manager).user)) {
        tree->add_son(&item);
    }
    STOP_TIMER
    std::cout << std::endl;
}

void NameTreeTest::query_test() {
    {
        std::cout << "测试正向获取用户列表" <<std::endl;
        START_TIMER
        auto vec = tree->get_order(0);
//        for (auto & item : *vec) {
//            std::cout << (*item.getUserName()) << std::endl;
//        }
        STOP_TIMER
        std::cout << "测试正向获取用户列表结束"<<std::endl;
    }
    {
        std::cout << "测试反向获取用户列表"<<std::endl;
        START_TIMER
        auto vec = tree->get_order(1);
//        for (auto & item : *vec) {
//            std::cout << (*item.getUserName()) << std::endl;
//        }
        STOP_TIMER
        std::cout << "测试反向获取用户列表结束"<<std::endl;
    }

    {
        std::cout << "根据名称获取用户信息测试 --------- start ---------" <<std::endl;
        START_TIMER
        for( auto & item : *(manager->user)){
            PeopleInterface peopleInterface(0,*item.getUserName(),0);
            auto result = tree->get_peoples(&peopleInterface);
            if ( result == nullptr ){
                std::cerr << "查找用户 " << *item.getUserName() << " ,失败"<< std::endl;
            }
//            std::cout << *result<<std::endl;
        }
        STOP_TIMER
        std::cout << "根据名称获取用户信息测试 --------- end   ---------"<<std::endl;
    }

    {
        std::cout << "根据名称和id取用户信息测试 --------- start ---------" <<std::endl;
        START_TIMER
        for( auto & item : *(manager->user)){
            PeopleInterface peopleInterface(*item.getId(),*item.getUserName(),0);
            auto result = tree->get_user(&peopleInterface);
            if ( result == nullptr ){
                std::cerr << "查找用户 " << item << " ,失败" << std::endl;
            }
//            std::cout << *result<<std::endl;
        }
        STOP_TIMER
        std::cout << "根据名称和id获取用户信息测试 --------- end   ---------"<<std::endl;
    }

    {
        std::cout << "根据名称和id删除用户信息测试 --------- start ---------" <<std::endl;
        START_TIMER
        for( auto & item : *(manager->user)){
            PeopleInterface peopleInterface(*item.getId(),*item.getUserName(),0);
            auto ecode = tree->delete_son(&peopleInterface);
            if ( ecode != success ){
                std::cerr << "删除用户 " << item << " ,失败"<< std::endl;
            }
        }
        STOP_TIMER
        std::cout << "根据名称和id删除用户信息测试 --------- end   ---------"<<std::endl;
    }

    {
        std::cout << "测试正向获取用户列表" <<std::endl;
        auto vec = tree->get_order(0);
        std::cout << "索引中存在数据： " << vec->size() << "条" << std::endl;
    }

    tree.reset();
    manager.reset();
}


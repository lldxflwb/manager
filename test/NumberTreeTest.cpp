//
// Created by 48449 on 2023/1/16.
//

#include "NumberTreeTest.h"

void NumberTreeTest::test() {
    insert_test();
    query_test();
}

void NumberTreeTest::insert_test() {
    std::cout << "开始插入，插入用户数量为：" << manager->user->size() << std::endl;
    START_TIMER
    for (auto & item : *((*manager).user)) {
        tree->add_son(&item);
    }
    STOP_TIMER
    std::cout << std::endl;
}

void NumberTreeTest::query_test() {
    {
        std::cout << "测试正向获取用户列表" <<std::endl;
        START_TIMER
        auto vec = tree->get_order(0);
//        for (auto & item : *vec) {
//            std::cout << *item << std::endl;
//        }
        STOP_TIMER
        std::cout << "测试正向获取用户列表结束"<<std::endl;
    }
    {
        std::cout << "测试反向获取用户列表"<<std::endl;
        START_TIMER
        auto vec = tree->get_order(1);
//        for (auto & item : *vec) {
//            std::cout << (*item) << std::endl;
//        }
        STOP_TIMER
        std::cout << "测试反向获取用户列表结束"<<std::endl;
    }
}


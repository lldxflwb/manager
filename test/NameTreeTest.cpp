//
// Created by 48449 on 2023/1/15.
//

#include "NameTreeTest.h"
#include "TestAction.h"

void NameTreeTest::test() {
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
    START_TIMER
    auto vec = tree->get_order(0);
    for (auto & item : *vec) {
        std::cout << (*item.getUserName()) << std::endl;
    }
    STOP_TIMER
}


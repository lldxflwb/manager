//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_NUMBERTREETEST_H
#define MANAGER_NUMBERTREETEST_H

#include "TestAction.h"
#include "../tree/NumberTree.h"

class NumberTreeTest {
    std::shared_ptr<Manager> manager ;
    std::shared_ptr<NumberTree> tree ;

public:
    NumberTreeTest() {
        manager = TestAction::MakeManager(1000000);
//        manager = TestAction::MakeManager(100);
        tree = std::make_shared<NumberTree>();
    }
    void test();
    void insert_test();
    void query_test();
};


#endif //MANAGER_NUMBERTREETEST_H

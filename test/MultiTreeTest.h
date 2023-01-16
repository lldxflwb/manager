//
// Created by 48449 on 2023/1/16.
//

#ifndef MANAGER_MULTITREETEST_H
#define MANAGER_MULTITREETEST_H

#include "TestAction.h"
#include "../tree/MultiNumberTree.h"

class MultiTreeTest {
    std::shared_ptr<TestManager> manager ;
    std::shared_ptr<MultiNumberTree> tree ;
public:
    MultiTreeTest() {
        manager = TestAction::MakeManager(1000000);
        tree = std::make_shared<MultiNumberTree>();
    }

    void test();
    void insert_test();
    void query_test();
};


#endif //MANAGER_MULTITREETEST_H

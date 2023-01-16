//
// Created by 48449 on 2023/1/15.
//

#ifndef MANAGER_NAMETREETEST_H
#define MANAGER_NAMETREETEST_H
#include "TestAction.h"
#include "../tree/NameTree.h"
class NameTreeTest {
    std::shared_ptr<Manager> manager ;
    std::shared_ptr<NameTree> tree ;

public:
    NameTreeTest() {
        manager = TestAction::MakeManager(1000000);
//        manager = TestAction::MakeManager(100);
        tree = std::make_shared<NameTree>();
    }

    void test();
    void insert_test();
    void query_test();
};


#endif //MANAGER_NAMETREETEST_H

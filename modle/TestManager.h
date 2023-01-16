//
// Created by 48449 on 2023/1/15.
//

#ifndef MANAGER_TESTMANAGER_H
#define MANAGER_TESTMANAGER_H
#include "../tree/NameTree.h"
#include "User.h"
#include <vector>
class TestManager {
public:
    std::shared_ptr<std::vector<User>> user;
    TestManager();
};


#endif //MANAGER_TESTMANAGER_H

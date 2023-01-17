#include <iostream>
#include "test/NameTreeTest.h"
#include "test/NumberTreeTest.h"
#include "test/MultiTreeTest.h"
#include "test/ManagerTest.h"
#include <thread>
int main() {
    std::cout << "Hello, World!" << std::endl;
    {
        NameTreeTest name_test;
        name_test.test();
    }
    {
        NumberTreeTest number_test;
        number_test.test();
    }
    {
        MultiTreeTest multiTreeTest;
        multiTreeTest.test();
    }
    {
        ManagerTest manager_test;
        manager_test.test();
    }
    return 0;
}

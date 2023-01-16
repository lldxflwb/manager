#include <iostream>
#include "test/NameTreeTest.h"
#include "test/NumberTreeTest.h"
#include "test/MultiTreeTest.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    NameTreeTest name_test;
    name_test.test();
    NumberTreeTest number_test;
    number_test.test();
    MultiTreeTest multiTreeTest;
    multiTreeTest.test();
    return 0;
}

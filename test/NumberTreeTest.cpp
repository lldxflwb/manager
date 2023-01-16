//
// Created by 48449 on 2023/1/16.
//

#include "NumberTreeTest.h"

void NumberTreeTest::test() {
    std::cout << "---------------- 开始测试 id索引 ----------------" << std::endl;
    insert_test();
    query_test();
}

void NumberTreeTest::insert_test() {
    std::cout << "开始插入，插入用户数量为：" << manager->user->size() << std::endl;
    START_TIMER
    for (auto & item : *((*manager).user)) {
        if(tree->add_son(&item)!=Ecode::success){
            std::cerr<< " 插入错误 ， 用户 ： " << item << std::endl;
            return ;
        }
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

    {
        std::cout << "根据id获取用户信息测试 --------- start ---------" <<std::endl;
        START_TIMER
        for( auto & item : *(manager->user)){
            PeopleInterface peopleInterface(*item.getId(),"",0);
            auto result = tree->get_user(&peopleInterface);
            if ( result == nullptr ){
                std::cerr << "查找用户 " << item << " ,失败";
            }
//            std::cout << *result<<std::endl;
        }
        STOP_TIMER
        std::cout << "根据id获取用户信息测试 --------- end   ---------"<<std::endl;
    }

    {
        std::cout << "根据id删除用户信息测试 --------- start ---------" <<std::endl;
        START_TIMER
        for( auto & item : *(manager->user)){
            PeopleInterface peopleInterface(*item.getId(),"",0);
            auto ecode = tree->delete_son(&peopleInterface);
            if ( ecode != success ){
                std::cerr << "查找用户 " << item << " ,失败";
            }
        }
        STOP_TIMER
        std::cout << "根据id删除用户信息测试 --------- end   ---------"<<std::endl;
    }

    {
        std::cout << "测试正向获取用户列表" <<std::endl;
        auto vec = tree->get_order(0);
        std::cout << "索引中存在数据： " << vec->size() << "条" << std::endl;
    }

}


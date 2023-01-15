//
// Created by 48449 on 2023/1/15.
//

#ifndef MANAGER_MAPTREEINTERFACE_H
#define MANAGER_MAPTREEINTERFACE_H

#include "PeopleInterface.h"
#include "../public/Public.h"
#include <vector>
class MapTreeInterface {
public:
    virtual Ecode add_son(PeopleRef people) = 0;
    virtual Ecode delete_son(PeopleRef people) = 0;
    virtual std::shared_ptr<PeopleInterface> get_user(PeopleRef people) = 0;
    virtual std::shared_ptr<std::vector<PeopleInterface>> get_peoples(PeopleRef people) = 0 ;
    virtual std::shared_ptr<std::vector<PeopleInterface>> get_order(int order = 0) = 0 ;
};


#endif //MANAGER_MAPTREEINTERFACE_H

//
// Created by 48449 on 2023/1/15.
//

#ifndef MANAGER_PEOPLEINTERFACE_H
#define MANAGER_PEOPLEINTERFACE_H

#include <string>
#include <ostream>
#include <memory>
typedef long int IDTYPE;
class PeopleInterface {
    std::shared_ptr<IDTYPE> id;
    std::shared_ptr<time_t> join_time;
    std::shared_ptr<std::string> user_name;
public:
    virtual ~PeopleInterface();

public:
    // use for save ， the id will bigger
    PeopleInterface(std::string name , time_t join_time);

    // use for copy
    PeopleInterface();
    PeopleInterface(int id , std::string name , time_t join_time);
    static int get_next_id();

    const std::shared_ptr<IDTYPE> &getId() const;

    void setId(IDTYPE id);

    const std::shared_ptr<time_t> &getJoinTime() const;

    void setJoinTime(time_t joinTime);

    const std::shared_ptr<std::string> &getUserName() const;

    void setUserName(std::string userName);

    friend std::ostream &operator<<(std::ostream &os, const PeopleInterface &anInterface);

    virtual std::shared_ptr<PeopleInterface> clone();
};
typedef PeopleInterface * PeopleRef ;

#endif //MANAGER_PEOPLEINTERFACE_H

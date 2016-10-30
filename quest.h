#ifndef QUEST_H_INCLUDED
#define QUEST_H_INCLUDED
#include "loot.h"
#include <iostream>
#include <cstring>
using namespace std;
class Quest{
public:
    Quest();//
    Quest(Loot const&  given_loot,int const& given_experience);//
    void destroy();//does nothing
    virtual ~Quest();//calls destroy
    Quest(Quest const& given);//
    Quest& operator= (Quest const& given);//
    void copy(Quest const& given);//
    Loot get_reward()const;//
    int get_experience()const;//
    void print_quest()const;//
    bool operator==(Quest const& given)const;
private:
    Loot reward;
    int experience;
};

#endif // QUEST_H_INCLUDED

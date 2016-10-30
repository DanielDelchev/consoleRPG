#ifndef QUEST_GIVER_H_INCLUDED
#define QUEST_GIVER_H_INCLUDED
#include "merchant.h"
class Quest_giver:public Merchant{
public:
    Quest_giver();
    Quest_giver(Quest const& held);
    Quest_giver& operator=(Quest_giver const& given);
    Quest_giver(Quest_giver const& given);
    void copy(Quest_giver const& given);
    void destroy();
    virtual ~Quest_giver();
    bool get_reward(Player& player);
    bool begin_quest(Player& player);
    Quest const& get_quest()const;
private:
    Quest quest_held;
};



#endif // QUEST_GIVER_H_INCLUDED

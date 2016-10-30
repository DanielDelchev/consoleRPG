#include "quest_giver.h"
void Quest_giver::destroy(){
}
Quest_giver::~Quest_giver(){
    destroy();
}
Quest_giver::Quest_giver():Merchant::Merchant(){
    quest_held=Quest();
}
Quest_giver::Quest_giver(Quest const& held):Merchant::Merchant(){
    quest_held=held;
}

Quest const& Quest_giver::get_quest()const{
    return quest_held;
}

void Quest_giver::copy(Quest_giver const& given){
    quest_held=given.get_quest();
}

Quest_giver::Quest_giver(Quest_giver const& given):Merchant(given){
    copy(given);
}

Quest_giver& Quest_giver::operator=(Quest_giver const& given){
    if (this!=&given){
        Merchant::operator=(given);
        destroy();
        copy(given);
    }
    return *this;
}

bool Quest_giver::begin_quest(Player& player){
    player.add_quest_taken(quest_held);//add_quest само си прави проверка дали куеста вече не е включен преди това
    return true;
}

bool Quest_giver::get_reward(Player& player){
    bool passed=false; int j=0;
    for (int i=0;i<player.get_quests_completed_count();i++){
        if (*(player.get_quests_completed()+i)==quest_held){
            passed=true; j=i; //куеста може да го има само на 1 позиция(подсигурено е от начина на добавяне на куести)
        }
    }
    if (!passed){
        cout<<"Quest not passed yet!"<<endl;
        return false;
    }
    else if (passed){
        player.gain_experience(quest_held.get_experience());
        player.add_gold(quest_held.get_reward().get_gold());
        for (int i=0;i<quest_held.get_reward().get_items_count();i++){
            player.add_item (*(quest_held.get_reward().get_item_arr()+i));
        }
        player.lose_quest_completed(*(player.get_quests_completed()+j));
    }
}
//ако нямаме куеста с единия метод ни го дава в taken_quests
//ако имаме изпълнен куест се маха от quests_completed и ни дава наградата

#include "quest.h"
void Quest::destroy(){
}

Quest::~Quest(){
    destroy();
}

int Quest::get_experience()const{
    return experience;
}

Loot Quest::get_reward()const{
    return reward;
}

void Quest::copy(Quest const& given){
    experience=given.get_experience();
    reward=given.get_reward();
}

Quest::Quest(Quest const& given){
    copy(given);
}

Quest& Quest::operator=(Quest const& given){
    if (this!=&given){
        destroy();
        copy(given);
    }
    return *this;
}

Quest::Quest(){
    reward=Loot();
    experience=0;
}

Quest::Quest(Loot const& given_loot,int const& given_experience){
    reward=given_loot;
    experience=given_experience;
}

void Quest::print_quest()const{
    cout<<"experience: "<<experience<<endl;
    cout<<"reward: ";
    reward.print_loot();
}

bool Quest::operator==(Quest const& given)const{
    return (experience==given.get_experience() && reward==given.get_reward());
}


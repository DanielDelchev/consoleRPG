#include "boss.h"
void Boss::destroy(){
}

Boss::~Boss(){
    destroy();
}

void Boss::print()const{
    cout<<"boss: ";
    int i=0;
    while (*((get_name())+i)){
        cout<<*(get_name()+i);
        i++;
    }
    i=0;
    cout<<"( ";
    while (*((get_race())+i)){
        cout<<*(get_race()+i);
        i++;
    }
    cout<<" )";
    cout<<"offence: "<<get_offence()<<" defence: "<<get_defence()<<" health: "<<get_health()<<" level: "<<get_level()<<" ";
    if (is_armed()){
        cout<<"( armed )";
    }
    else{
        cout<<"( not armed )";
    }
    cout<<endl<<"loot:"<<endl; get_loot().print_loot();
    cout<<endl;cout<<"Quest:"<<endl; quest.print_quest();
}

Boss::Boss():Monster(){
    quest=Quest();
}


Boss::Boss(char* name_,char* race_,int dmg ,int def,int hp,int lvl ,bool arm,Loot const& reward_,Quest const& given):
    Monster(name_,race_,dmg,def,hp,lvl,arm,reward_)
{
    quest=given;
}

Boss::Boss(Boss const& given):Monster(given){
    copy(given);
}

Boss& Boss::operator=(Boss const& given){
    if (this!=&given){
        Monster::operator=(given);
        destroy();
        copy(given);
    }
    return *this;
}

const Quest& Boss::get_boss_quest()const{
    return quest;
}

void Boss::copy(Boss const& given){
    quest=given.get_boss_quest();
}

#include "monster.h"
const Loot& Monster::get_loot()const{
    return loot;
}

void Monster::destroy(){
}

Monster::~Monster(){
}

void Monster::copy(Monster const& given){
    loot=given.get_loot();
}

Monster::Monster(Monster const& given):Creature(given){
    copy(given);
}

Monster& Monster::operator=(Monster const& given){
    Creature::operator=(given);
    if (this!=&given){
        destroy();
        copy(given);
    }
    return *this;
}
void Monster::print()const{
    cout<<"monster: ";
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
    cout<<endl<<"loot:"<<endl; loot.print_loot();
}

Monster::Monster():Creature(){
    loot=Loot();
}

Monster::Monster(char* name_,char* race_,int dmg,int def,int hp,int lvl,bool armed_,Loot const& given):Creature(name_,race_,dmg,def,hp,lvl,armed_){
    loot=given;
}

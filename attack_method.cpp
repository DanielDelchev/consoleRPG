#include "attack_method.h"

int Attack_method:: get_damage()const{
    return damage;
}

void Attack_method::change_damage(int given){
    damage=given;
}

Attack_method::Attack_method(){
    change_damage(0);
}

Attack_method::Attack_method(int given){
    change_damage(given);
}

void Attack_method::destroy(){
}

Attack_method::~Attack_method(){
    destroy();
}

void Attack_method::copy(Attack_method const& given){
    damage=given.get_damage();
}

Attack_method::Attack_method(Attack_method const& given){
    copy(given);
}

Attack_method& Attack_method::operator=(Attack_method const& given){
    if (this!=&given){
        destroy();
        copy(given);
    }
    return *this;
}

const int count_of_attack_methods=6;
Attack_method shoot(10);  //0
Attack_method strike(8);  //1
Attack_method siege(14);  //2
Attack_method pierce(12); //3
Attack_method stab(10);    //4
Attack_method harras(1);   //5
Attack_method list_of_methods [count_of_attack_methods]={shoot,strike,siege,pierce,stab,harras};

#include "creature.h"
#include <cstring>
int Creature::get_health()const{
    return health;
}

int Creature::get_defence()const{
    return defence;
}

int Creature::get_offence()const{
    return offence;
}

int Creature::get_level()const{
    return level;
}

bool Creature::is_armed()const{
    return armed;
}

void Creature::engarde(){
    armed=true;
}

const char* Creature::get_name()const{
    return name;
}

const char* Creature::get_race()const{
    return race;
}

void Creature::destroy(){
    delete [] name;
    delete [] race;
}

Creature::~Creature(){
    destroy();
}

void Creature::copy(Creature const& given){
    health=given.get_health();
    offence=given.get_offence();
    defence=given.get_defence();
    level=given.get_level();
    armed=given.is_armed();
    name=new char[strlen(given.get_name())+1];
    race=new char[strlen(given.get_race())+1];
    strcpy(name,given.get_name());
    strcpy(race,given.get_race());
}

Creature::Creature(Creature const& given):name(NULL),race(NULL){
    copy(given);
}

Creature& Creature::operator=(Creature const& given){
    if (this!=&given){
        destroy();
        copy(given);
    }
    return *this;
}

Creature::Creature():name(NULL),race(NULL){
    char generic_name [] ="sheep";
    char generic_race []="beast";
    name=new char[strlen(generic_name)+1];
    race=new char[strlen(generic_race)+1];
    strcpy(name,generic_name);
    strcpy(race,generic_race);
    health=1;
    defence=1;
    offence=1;
    armed=false;
    level=1;
}

Creature::Creature(char* name_,char* race_,int dmg,int def,int hp,int lvl,bool armed_):name(NULL),race(NULL){
    name=new char[strlen(name_)+1];
    race=new char[strlen(race_)+1];
    strcpy(name,name_);
    strcpy(race,race_);
    health=hp;
    defence=def;
    offence=dmg;
    armed=armed_;
    level=lvl;
}

void Creature::print()const{
    cout<<"creature: ";
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
    cout<<"offence: "<<offence<<" defence: "<<defence<<" health: "<<health<<" level: "<<level<<endl;
    if (is_armed()){
        cout<<"( armed )";
    }
    else{
        cout<<"( not armed )";
    }
    cout<<endl;
}


int Creature::attack(Creature& target,const Attack_method* att ){
    if (health>0){
    armed=true; //въоражава се за да атакува
    if (!(target.is_armed())){
            if (att==NULL){
                target.change_hp(max(offence,0)); //прави Dmg
                target.engarde(); //жертвата се въоражава след като е понесла първия удар без щит
                return max(offence,0); //връща колко Dmg e направено
        }
            else if (att!=NULL){
                target.change_hp(max((offence+att->get_damage()),0)); //прави Dmg
                target.engarde(); //жертвата се въоражава
                return max((offence+att->get_damage()),0); //връща колко Dmg e направено
            }
    }
    else {
        if ((target.is_armed())){
            if (att==NULL){
                target.change_hp(max(offence-target.get_defence(),0)); //прави Dmg
                target.engarde(); //жертвата се въоражава след като е понесла първия удар без щит
                return max((offence-target.get_defence()),0); //връща колко Dmg e направено
        }
            else if (att!=NULL){
                target.change_hp(max(((offence+att->get_damage())-target.get_defence()),0)); //прави Dmg
                target.engarde(); //жертвата се въоражава
                return max((offence-target.get_defence()+att->get_damage()),0); //връща колко Dmg e направено
            }

        }
    }
    }
}

void Creature::battle(Creature& target,const Attack_method* att,const Attack_method* target_att ){
    int i=1;
    while (get_health()>0&&target.get_health()>0&&(get_offence()>0||target.get_offence()>0)){
        cout<<"*****************Round"<<i<<"******************"<<endl; i++;
        if (get_health()>0){
            this->print(); cout<<"HAS DONE ";
            cout<<attack(target,att);
            cout<<"DAMAGE TO ";cout<<endl;
            target.print();
        }
        cout<<endl;
        if (target.get_health()<=0){this->print(); cout<<"HAS WON!"<<endl; break;}
        if (target.get_health()>0){
            target.print(); cout<<"HAS DONE ";
            cout<<target.attack(*this,target_att);
            cout<<" DAMAGE TO "; cout<<endl;
            this->print();
        }
        if (get_health()<=0){target.print(); cout<<"HAS WON!"<<endl; break;}
        cout<<endl;
    }
}

const Loot& Creature::get_loot() const{
}

const Quest& Creature::get_boss_quest()const{
}

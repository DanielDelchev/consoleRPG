#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED
#include "attack_method.h"
#include "loot.h"
#include "quest.h"
#include <iostream>
using namespace std;
class Creature{
public:
    void destroy();//
    void copy(Creature const& given);//
    Creature();//
    Creature(char*,char*,int,int,int,int,bool);//
    Creature(Creature const& given);//
    Creature& operator=(Creature const& given);//
    virtual ~Creature();//
    const char* get_name()const;//
    const char* get_race()const;//
    virtual int get_health()const;//за player  са различни щото има итеми
    virtual int get_defence()const;//
    virtual int get_offence()const;//
    int get_level()const;//
    bool is_armed()const;//
    void engarde();//
    void change_hp(int x){health-=x;};//
    void change_level(int x){level+=x;};//само Player качва левел
    virtual int attack(Creature& target,const Attack_method* =NULL);
    virtual void battle(Creature& target,const Attack_method* =NULL,const Attack_method* =NULL);
    virtual void print()const;
    virtual const Loot& get_loot() const;
    virtual const Quest& get_boss_quest()const;
private:
    char* name;
    char* race;
    int health;
    int offence;
    int defence;
    int level;
    bool armed;         //false поначало от конструкторите
};


#endif // CREATURE_H_INCLUDED

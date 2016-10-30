#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED
#include "creature.h"
#include "loot.h"
class Monster:public Creature{
public:
    Monster();//
    Monster(char*,char*,int,int,int,int,bool,Loot const& given);//
    virtual ~Monster();//
    Monster(Monster const& given);//
    Monster& operator=(Monster const& given);//
    void copy(Monster const& given);//
    void destroy();//
    virtual const Loot& get_loot() const;//
    virtual void print()const;//
private:
    Loot loot;
};

#endif // MONSTER_H_INCLUDED

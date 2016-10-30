#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include "creature.h"
#include "item.h"
class Character:public Creature{
public:
    Character();//
    Character(char*,char*,int,int,int,int,bool,Item*,int,int);//
    void copy(Character const& given);//
    void destroy();//
    virtual ~Character();//
    Character(Character const& given);//
    Character& operator=(Character const& given);//

    void add_gold(int x){gold=gold+x;};//
    void reduce_gold(int x){gold=gold-x;};//
    int get_gold()const{return gold;};//
    const Item* get_inventory()const{return inventory;};//
    int get_items_in_inventory()const{return items_in_inventory;};//
    virtual void print()const;//

    void add_item(Item const&);//добавя по 1 итем няма капацитет
    void lose_item(Item const&);
protected:
    Item* inventory;
    int items_in_inventory; //без лимит е
private:
    int gold;
};

#endif // CHARACTER_H_INCLUDED

#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include <iostream>
#include <cstring>
#include "spell.h"
using namespace std;

class Item{
public:
    Item();//
    Item(int hp,int dmg,int def,int gold,char* name_given,Spell* given_spells,int count_of_spells);
    Item(Item const& given);//
    Item& operator=(Item const& given);//
    virtual ~Item();//
    void copy(Item const& given);//
    void destroy();//
    int get_health()const;//
    int get_offence()const;//
    int get_defence()const;//
    int get_spells_count()const;//
    int get_gold_value()const;//
    const char* get_name()const;//
    const Spell* get_spell_list()const;//
    void print_item()const;//
    bool operator==(Item const& given)const;
    bool operator!=(Item const& given)const;
protected:
    Spell* spells;
    int spells_count;
private:
    char* name;
    int health;
    int offence;
    int defence;
    int gold_value;
};


#endif // ITEM_H_INCLUDED

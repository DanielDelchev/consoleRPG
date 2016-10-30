#ifndef SPELL_H_INCLUDED
#define SPELL_H_INCLUDED
#include "attack_method.h"
#include <cstring>
#include <iostream>
using namespace std;
class Spell:public Attack_method{
public:
    Spell(); //
    Spell(char* given,int dmg);//
    void copy(Spell const& given); //
    void destroy(); //
    virtual ~Spell();        //
    Spell(Spell const& given);//
    Spell& operator=(Spell const& given);//
    const char* get_name()const;  //
    void print_spell()const;   //
    bool operator==(Spell const& given)const;
    bool operator!=(Spell const& given)const;
private:
    char* name;
};



#endif // Spell_H_INCLUDED

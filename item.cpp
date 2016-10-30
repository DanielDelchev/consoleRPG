#include "item.h"
int Item::get_defence()const{
    return defence;
}

int Item::get_gold_value()const{
    return gold_value;
}

int Item::get_offence()const{
    return offence;
}

int Item::get_health()const{
    return health;
}

int Item::get_spells_count()const{
    return spells_count;
}

const char* Item::get_name()const{
    return name;
}

const Spell* Item::get_spell_list()const{
    return spells;
}

void Item::destroy(){
    delete [] spells;
    delete [] name;
}

Item::~Item(){
    destroy();
}

void Item::copy(Item const& given){
    gold_value=given.get_gold_value();
    health=given.get_health();
    defence=given.get_defence();
    offence=given.get_offence();
    name=new char[strlen(given.get_name())+1];
    strcpy(name,given.get_name());
    spells=new Spell[given.get_spells_count()];
    for (int i=0;i<given.get_spells_count();i++){
        spells[i]=*(given.get_spell_list()+i);
    }
    spells_count=given.get_spells_count();
}

Item::Item():spells(NULL),name(NULL){
    char generic[]="No item";
    name=new char[strlen(generic)+1];
    strcpy(name,generic);
    gold_value=0;
    spells_count=0;
    health=0;
    defence=0;
    offence=0;
}

void Item::print_item()const{
    int i=0;
    while (*((get_name())+i)){
        cout<<*(get_name()+i);
        i++;
    }
    cout<<"   offence: "<<offence<<" defence:"<<defence<<" health:"<<health<<" gold value:"<<gold_value<<endl;
    cout<<"Spells:"<<endl;
    if (spells_count==0){
        cout<<"None"<<endl;
    }
    else{
            for (int i=0;i<spells_count;i++){
                (spells+i)->print_spell();
            }
            cout<<endl;
        }
}

Item::Item(Item const& given):spells(NULL),name(NULL){
    copy(given);
}

Item& Item::operator=(Item const& given){
    if (this!=&given){
        destroy();
        copy(given);
    }
    return *this;
}

Item::Item(int hp,int dmg,int def,int gold,char* name_given,Spell* given_spells,int count_of_spells):spells(NULL),name(NULL){
    health=hp;
    offence=dmg;
    defence=def;
    gold_value=gold;
    name=new char[strlen(name_given)+1];
    strcpy(name,name_given);
    spells= new Spell[count_of_spells];
    for (int i=0;i<count_of_spells;i++){
        spells[i]=*(given_spells+i);
    }
    spells_count=count_of_spells;
}

bool Item::operator==(Item const& given)const{
    bool same_name=false;
    if (strcmp(get_name(),given.get_name())==0){
        same_name=true;
    }

    bool same_parameters= (spells_count==given.get_spells_count()&&health==given.get_health()
                           &&defence==given.get_defence()&&offence==given.get_offence()&&gold_value==given.get_gold_value());

    bool same_spells=true;
    for (int i=0;i<spells_count;i++){
        if ( *(spells+i)!=*(get_spell_list()+i) )
            same_spells=false;
    }

    return same_name&&same_parameters&&same_spells;
}

bool Item::operator!=(Item const& given)const{
    return operator==(given);
}

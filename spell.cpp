#include"spell.h"
void Spell::destroy(){
    delete [] name;
}

Spell::~Spell(){
    destroy();
}

Spell::Spell():Attack_method(),name(NULL){
    char generic[]="No Spell";
    name=new char[strlen(generic)+1];
    strcpy(name,generic);
}

Spell::Spell(char* given,int dmg):Attack_method(dmg),name(NULL){
    name=new char[strlen(given)+1];
    strcpy(name,given);
}

const char* Spell::get_name()const{
    return name;
}
void Spell:: print_spell()const{
    int i=0;
    while (*((get_name())+i)){
        cout<<*(get_name()+i);
        i++;
    }
    cout<<" "<<get_damage()<<" damage"<<endl;
}

void Spell::copy(Spell const& given){
    name=new char[strlen(given.get_name())+1];
    strcpy(name,given.get_name());
}

Spell::Spell(Spell const& given):Attack_method(given),name(NULL){
    copy(given);
}

Spell& Spell::operator=(Spell const& given){
    if (this!=&given){
        destroy();
        Attack_method::operator=(given);
        copy(given);
    }
    return * this;
}


bool Spell::operator==(Spell const& given)const{
    bool same_name_= ( strcmp(name,given.get_name())==0 );
    bool same_dmg_=get_damage()==given.get_damage();
    return same_name_&&same_dmg_;
}

bool Spell::operator!=(Spell const& given)const{
    return operator==(given);
}

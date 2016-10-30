#include "character.h"
void Character::print()const{
        cout<<"character: ";
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
    cout<<" gold:"<<get_gold()<<endl;
    cout<<"Inventory: ";
    if (get_items_in_inventory()!=0){
        for (int i=0;i<items_in_inventory;i++){
            (inventory+i)->print_item();
        }
    }
    else{
        cout<<"empty";
    }
    cout<<endl;
}

void Character::destroy(){
    delete [] inventory;
}

Character::~Character(){
    destroy();
}


void Character::copy(Character const& given){
    inventory= new Item[given.get_items_in_inventory()];
    for (int i=0;i<given.get_items_in_inventory();i++){
        inventory [i]=*(given.get_inventory()+i);
    }
    items_in_inventory=given.get_items_in_inventory();
    gold=given.get_gold();
}

Character::Character(Character const& given):Creature(given),inventory(NULL){
    copy(given);
}

Character& Character::operator=(Character const& given){
    if (this!=&given){
        Creature::operator=(given);
        destroy();
        copy(given);
    }
    return *this;
}

Character::Character():Creature::Creature(),inventory(NULL),gold(0),items_in_inventory(0){
}

Character::Character(char* name_,char* race_,int dmg,int def,int hp,int lvl,bool armed_,Item* inventory_,int items_count,int gold_):
    Creature(name_,race_,dmg,def,hp,lvl,armed_),inventory(NULL){
    items_in_inventory=items_count;
    gold=gold_;
    inventory= new Item[items_count];
    for (int i=0;i<items_count;i++){
        inventory[i]=*(inventory_+i);
    }

}


void Character::add_item(Item const& given){
    int old_count=items_in_inventory;
    items_in_inventory+=1;
    Item* new_inventory=new Item[items_in_inventory];
    for (int i=0;i<old_count;i++){
        new_inventory[i]=*(inventory+i);
    }
    new_inventory[items_in_inventory-1]=given;
    delete [] inventory;
    inventory=new_inventory;
}

void Character::lose_item(Item const& given){
    bool found=false;
    int i=0;
    for (i;i<items_in_inventory;i++){
        if (strcmp((inventory+i)->get_name(),given.get_name())==0){
            found=true; //намира първото срещане на итема
            break;
        }
    }
    if (found){
        for (int j=i;j<items_in_inventory-1;j++){
                inventory[j]=inventory[j+1];
        }
        items_in_inventory--;
    }
}

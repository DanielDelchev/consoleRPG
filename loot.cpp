#include "loot.h"
int Loot::get_gold()const{
    return gold;
}

int Loot::get_items_count()const{
    return items_count;
}

const Item* Loot::get_item_arr()const{
    return items;
}

void Loot::destroy(){
    delete [] items;
}

Loot::~Loot(){
    destroy();
}

void Loot::copy(Loot const& given){
    gold=given.get_gold();
    items=new Item[given.get_items_count()];
    for (int i=0;i<given.get_items_count();i++){
        items[i]=*(given.get_item_arr()+i);
    }
    items_count=given.get_items_count();
}

Loot::Loot(Loot const& given):items(NULL){
    copy(given);
}

Loot& Loot::operator=(Loot const& given){
    if (this!=&given){
        destroy();
        copy(given);
    }
    return *this;
}

Loot::Loot():items(NULL){
    items_count=0;
    gold=0;
}

Loot::Loot(Item* given_arr,int arr_length,int gold_):items(NULL){
    gold=gold_;
    items= new Item[arr_length];
    for (int i=0;i<arr_length;i++){
        items[i]=*(given_arr+i);
    }
    items_count=arr_length;
}

void Loot::print_loot()const{
    cout<<"gold: "<<gold<<endl<<"items: "<<endl;
    if (items_count==0){
        cout<<"None"<<endl;
    }
    else{
        for (int i=0;i<items_count;i++){
            items[i].print_item();
        }
    }

}

bool Loot::operator==(Loot const& given)const{
       bool same_items=true;
       for (int i=0;i<items_count;i++){
            if ( *(items+i)!=*(given.get_item_arr()+i) )
                same_items=false;
       }
    return (gold==given.get_gold() && items_count==given.get_items_count()&& same_items);
}

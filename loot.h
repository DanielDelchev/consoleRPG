#ifndef LOOT_H_INCLUDED
#define LOOT_H_INCLUDED
#include "item.h"
class Loot{
public:
    Loot();//
    Loot(Item* given_arr,int arr_length,int gold_);
    Loot(Loot const& given);//
    Loot& operator=(Loot const& given);//
    virtual ~Loot();//
    void destroy();//
    void copy(Loot const& given);//
    const Item* get_item_arr()const;//
    int get_gold()const;//
    int get_items_count()const;//
    void print_loot()const;
    bool operator==(Loot const& given)const;
protected:
    Item* items;
    int items_count;
private:
    int gold;
};

#endif // LOOT_H_INCLUDED

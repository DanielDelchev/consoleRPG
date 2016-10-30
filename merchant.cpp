#include "merchant.h"
void Merchant::destroy(){};

Merchant::~Merchant(){destroy();};

void Merchant::copy(Merchant const& given){};

Merchant::Merchant():Character(){};

Merchant::Merchant(Merchant const& given){
    Character::copy(given);
    copy(given);
}

Merchant& Merchant::operator=(Merchant const& given){
    if (this!=&given){
        Character::operator=(given);
        destroy();
        copy(given);
    }
    return *this;
}

int Merchant::buy(const char* item_name,Player& seller){ //merchant buys from the player, the player sells to the merchant
    bool found=false; int j=0;
    for (int i=0;i<seller.get_items_in_inventory();i++){
        if (strcmp((seller.get_inventory()+i)->get_name(),item_name)==0){
            found=true; j=i;
        }
    }
    if (!found){
        return 0; //ако няма такъв итем в инвентори нищо не става , въща се 0 gold от продажбата на нищо
    }
    if (found){
        seller.add_gold((seller.get_inventory()+j)->get_gold_value());
        seller.lose_item(*(seller.get_inventory()+j));
    }
    return ((seller.get_inventory()+j)->get_gold_value());//връща голда от продажбата
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//предполага се че само тези итеми могат да се копуват, всички други в играта са от босове и куестове или нещо такова

char spell_1_name[]="hit hard";
Spell spell_edno(spell_1_name,10);
char spell_2_name[]="slap hard";
Spell spell_dve(spell_2_name,3);
char spell_3_name[]="push";
Spell spell_tri(spell_3_name,7);
char spell_4_name[]="tackle";
Spell spell_chetiri(spell_4_name,12);
char spell_5_name[]="enroot";
Spell spell_pet(spell_5_name,8);
char spell_6_name[]="smack";
Spell spell_shest(spell_6_name,15);
char spell_7_name[]="spray";
Spell spell_sedem(spell_7_name,30);
char spell_8_name[]="poison touch";
Spell spell_osem(spell_8_name,14);
char spell_9_name[]="rocket shot";
Spell spell_devet(spell_9_name,15);
char spell_10_name[]="hide";
Spell spell_deset(spell_10_name,19);

Spell spells_for_item_1[]={spell_dve};
Spell spells_for_item_2[]={spell_tri,spell_deset};
Spell spells_for_item_3[]={spell_chetiri};
Spell spells_for_item_4[]={spell_pet};
Spell spells_for_item_5[]={spell_shest,spell_devet};
Spell spells_for_item_6[]={spell_sedem};
Spell spells_for_item_7[]={spell_sedem,spell_osem,spell_edno};

char first_item_name[]="club of war";
Item item_for_sale1(10,10,10,10,first_item_name,spells_for_item_1,1);

char second_item_name[]="shield of war";
Item item_for_sale2(10,8,13,12,second_item_name,spells_for_item_2,2);

char third_item_name[]="cap of defience";
Item item_for_sale3(8,10,4,10,third_item_name,spells_for_item_3,1);

char fourth_item_name[]="soul reaver";
Item item_for_sale4(2,2,2,1,fourth_item_name,spells_for_item_4,1);

char fifth_item_name[]="ring of health";
Item item_for_sale5(3,10,5,10,fifth_item_name,spells_for_item_5,2);

char sixth_item_name[]="clover";
Item item_for_sale6(10,9,12,10,sixth_item_name,spells_for_item_6,1);

char seventh_item_name[]="jacket of coolness";
Item item_for_sale7(10,16,13,1000,seventh_item_name,spells_for_item_7,3);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int const count_items_for_sale=7;
Item items_for_sale[]={item_for_sale1,item_for_sale2,item_for_sale3,item_for_sale4,item_for_sale5,item_for_sale6,item_for_sale7};
//при добавяне на итем  в списъка трябва да дигнем и константата
// (предполага се че повреме на игра не се създават нови итеми)

//ТЪЙ КАТО ИТЕМА СЕ ПОДАВА ПО ИМЕ ТЪРСИМ ДАЛИ ИМА ТАКЪВ В ГОРЕДЕКЛАРИРАНИЯ СПИСЪК ОТ ИТЕМИ
//САМО ОТ ТЯХ МОЖЕ ДА СЕ КОПУВАТ ИТЕМИ В ИГРАТА, ДРУГИТЕ ИТЕМИ СА ОТ БОСОВЕ ИЛИ НЕЩОТ ТАКОВА


int Merchant::sell(const char* item_name,Player& buyer){//merchant sells to player, player buys from merchant
    bool found=false; int j=0;//тук турсим дали има итем с такова име в масива от всички итеми на играта (в "items_quests_spells_etc.h")
    for (int i=0;i<count_items_for_sale;i++){
        if (strcmp((items_for_sale+i)->get_name(),item_name)==0){
            found=true; j=i;
        }
    }
    if (!found){
    return 0; //ако няма такъв итем нищо не става , от player се е взело 0 голд
    }
    if (found){
        if (buyer.get_gold()<((items_for_sale+j)->get_gold_value())){
            cout<<"Not enough gold to buy the item!"<<endl;
            return 0;
        }
            buyer.reduce_gold((items_for_sale+j)->get_gold_value());//плаща
            buyer.add_item(*(items_for_sale+j));//слага итема в инвентори
    }
    return (items_for_sale+j)->get_gold_value();
}

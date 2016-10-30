#ifndef ITEMS_QUESTS_SPELLS_ETC_H_INCLUDED
#define ITEMS_QUESTS_SPELLS_ETC_H_INCLUDED
#include "quest.h"
#include "item.h"
#include "spell.h"
#include "player.h"

/*—⁄ƒ⁄–∆¿ —¿ÃŒ ƒ≈ À¿–¿÷»» Õ¿ Ã¿√»»,»√–¿◊»,»“≈Ã» » ƒ–”√» »«œŒ«À¬¿Õ» «¿ “≈—“Œ¬≈, Õ≈ ≈ ¬ ﬁ≈Õ ¬ Õ» Œ… ƒ–”√ ‘¿»À Œ—¬≈Õ ¬ MAIN */

//spells
char tel[]="teleport";
                //name,dmg
Spell teleport(tel,0);
char smi[]="smite";
Spell smite(smi,10);
char fre[]="freeze";
Spell freeze(fre,12);
char cur[]="curse";
Spell curse(cur,5);
char bli[]="blind";
Spell blind(bli,15);

char bcry[]="battlecry";
Spell battlecry(bcry,8);


char wind[]="windwalk";
Spell windwalk(wind,2);


//items
char weapon1[]="sword of darkenss";
Spell arr_sp1[]={teleport,curse};
                        //offende,defence,health,gold,name,spells arr,length of arr
Item sword_of_darkness(3,4,5,10,weapon1,arr_sp1,2);

char weapon2[]="cap of honour";
Spell arr_sp2[]={freeze};
Item cap_of_honor(1,2,3,7,weapon2,arr_sp2,1);

char weapon3[]="gloves of haste";
Spell arr_sp3[]={smite};
Item gloves_of_haste(5,2,2,9,weapon3,arr_sp3,1);

char weapon4[]="shovel of ultimate destruction";
Spell arr_sp4[]={freeze,teleport,blind,smite,curse};
Item shovel_of_ultimate_destruction(30,40,50,100,weapon4,arr_sp4,5);
//loot
Item for_first_loot[]={sword_of_darkness};
                    //items arr,length,gold
Loot for_first_quest(for_first_loot,1,120);

Item for_second_loot[]={gloves_of_haste,gloves_of_haste}; //‰‚‡ ˜ËÙÚ‡
Loot for_second_quest(for_second_loot,2,200);

Item for_third_loot[]={cap_of_honor};
Loot for_third_quest(for_third_loot,1,300);

Item for_fourth_loot[]={shovel_of_ultimate_destruction};
Loot for_fourth_quest(for_fourth_loot,1,9000);
//quest
Quest one1(for_first_quest,300);
Quest two2 (for_second_quest,800);
Quest three3 (for_third_quest,2000);
Quest four4 (for_fourth_quest,5000);
Quest five5 (for_first_quest,8000);
Quest six6 (for_third_quest,16000);
//Boss
char name_d[]="diablo";
char race_d[]="devil";
Boss diablo(name_d,race_d,20,10,100,10,false,for_first_quest,three3);
//character
char namer_[]="John Jo Shelvey";
char racer_[]="midfielder";
Character john(namer_,racer_,10,12,13,7,true,for_second_loot,2,500);

//Ó˘Â ËÚÂÏË
char weapon11[]="sword of fire";
Spell arr_sp11[]={teleport};
                        //offence,defence,health,gold,name,spells arr,length of arr
Item sword_of_fire(4,5,6,11,weapon11,arr_sp11,1);

char weapon22[]="shield of fire";
Spell arr_sp22[]={blind};
                        //offence,defence,health,gold,name,spells arr,length of arr
Item shield_of_fire(4,15,6,11,weapon22,arr_sp22,1);

char weapon33[]="golden bow";
Spell arr_sp33[]={teleport};
                        //offence,defence,health,gold,name,spells arr,length of arr
Item golden_bow(14,5,6,11,weapon33,arr_sp33,1);

char weapon44[]="golden shield";
Spell arr_sp44[]={freeze};
                        //offence,defence,health,gold,name,spells arr,length of arr
Item golden_shield(14,5,16,12,weapon44,arr_sp44,1);

Spell spell_book_player1[]={battlecry};
Spell spell_book_player2[]={windwalk};

Quest quests_taken_by_player1[]={one1};
Quest quests_completed_by_player1[]={two2};

Quest quests_taken_by_player2[]={three3};
Quest quests_completed_by_player2[]={four4};

char name_of_player1[]="Boromir";       char name_of_player2[]="Legolas";
char race_of_player1[]="Human";         char race_of_player2[]="Elf";
char class_of_player1[]="Tank";         char class_of_player2[]="Archer";
        //ËÏÂ,‡Ò‡,ËÚÂÏ,dmg,def,hp,lvl,armed,inventory,items in inventory,gold,class,experience,weapon,weapon ON,shield,shield ON,
Player player_one( name_of_player1,race_of_player1,20,15,100,8,true,
        for_third_loot,1,350,
        class_of_player1,175,sword_of_darkness,true,shield_of_fire,true,
        spell_book_player1,1,quests_taken_by_player1,1,quests_completed_by_player1,1
       );

Player player_two( name_of_player2,race_of_player2,22,13,95,3,true,
        for_second_loot,2,250,
        class_of_player2,195,golden_bow,true,golden_shield,true,
        spell_book_player2,1,quests_taken_by_player2,1,quests_completed_by_player2,1
       );


#endif // ITEMS_QUESTS_SPELLS_ETC_H_INCLUDED

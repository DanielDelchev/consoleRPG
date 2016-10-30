#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <typeinfo>
#include "character.h"
#include "quest.h"
#include "boss.h"
class Player:public Character{
public:
    virtual int attack(Creature& target,const Attack_method* =NULL);
    virtual void battle(Creature& target,const Attack_method* =NULL,const Attack_method* =NULL);
    virtual void print()const;//
    virtual int get_health()const;//за player  са различни щото има итеми
    virtual int get_defence()const;//
    virtual int get_offence()const;//
    const char* get_klas()const;//
    int get_experience()const;//
    int gain_experience(int new_experience);//
    const Item& get_weapon()const;//
    const Item& get_shield()const;//
    const Spell* get_spell_book()const;//
    int get_spell_book_count()const;//
    const Quest* get_quests_taken()const;//
    int get_quests_taken_count()const;//
    const Quest* get_quests_completed()const;//
    int get_quests_completed_count()const;//
    void add_spell(Spell const&);//
    void lose_spell(Spell const&);//
    void add_quest_taken(Quest const&);//
    void lose_quest_taken(Quest const&);//
    void add_quest_completed(Quest const&);//
    void lose_quest_completed(Quest const&);//
    void put_weapon_on(const Item&);//взима го от инвентори и го слага
    void put_weapon_down(); //връща го в инвентори
    void put_shield_on(const Item&);//взима го от инвентори и го слага
    void put_shield_down();//връща го в инвентори
    bool const& is_weapon_equiped()const{return weapon_equiped;};//
    bool const& is_shield_equiped()const{return shield_equiped;};//
    bool give_item(const char* item_name,Player&  receiver);//взима итем от инвентара и го дава в инвентара на другия герой!
    bool give_gold(int gold_sum,Player&  receiver);           //итем дава магии на spell_book само когато е equip-нат!

    Player();//
    Player(char* name_,char* race_,int dmg_,int def_,int hp_,int lvl_,bool armed_,
            Item* inventory_,int items_count_,int gold_,char* klas_,int experience_,
            Item& weapon_,bool weapon_qeuiped_,Item& shield_,bool shield_qeuiped_,Spell* book_,
            int spell_book_count_,Quest* taken_,int quests_taken_count,Quest* completed_,int quests_completed_count);//
    void copy(Player const& given);//
    void destroy();//
    virtual ~Player();//
    Player(Player const& given);//
    Player& operator=(Player const& given);//

protected:
    Spell* spell_book;
    int spell_book_count;
    Quest* quests_taken;
    int quests_taken_count;
    Quest* quests_completed;
    int quests_completed_count;
private:
    char* klas;
    int experience;
    bool weapon_equiped;
    bool shield_equiped;
    Item weapon;
    Item shield;
};

// ако няма оръжие или щит bool показва това
//ако сложим щит /меч от инвентори той се присвоява на weapon/shield и изчезва от инвентори
//ако свалим се връща в инвентори

#endif // PLAYER_H_INCLUDED

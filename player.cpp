#include "player.h"

Player GenericPlayer;
Creature GenericCreature;
Monster GenericMonster;
Boss GenericBoss;



void Player::destroy(){
    delete [] klas;
    delete [] quests_completed;
    delete [] quests_taken;
    delete [] spell_book;
}

Player::~Player(){
    destroy();
}

int Player::get_health()const{
    return Creature::get_health()+weapon.get_health()+shield.get_health();
}

int Player::get_defence()const{
    return Creature::get_defence()+weapon.get_defence()+shield.get_defence()*10;
}

int Player::get_offence()const{
    return Creature::get_defence()+shield.get_defence()+weapon.get_offence()*10;
}

const char* Player::get_klas()const{
    return klas;
}

int Player::get_experience()const{
    return experience;
}

const Item& Player::get_weapon()const{
    return weapon;
}

const Item& Player::get_shield()const{
    return shield;
}

const Spell* Player::get_spell_book()const{
    return spell_book;
}

int Player::get_spell_book_count()const{
    return spell_book_count;
}

const Quest* Player::get_quests_taken()const{
    return quests_taken;
}

int Player::get_quests_taken_count()const{
    return quests_taken_count;
}

const Quest* Player::get_quests_completed()const{
    return quests_completed;
}

int Player::get_quests_completed_count()const{
    return quests_completed_count;
}

void Player::copy(Player const& given){
    Creature::copy(given);
    klas=new char[strlen(given.get_klas())+1];
    strcpy(klas,given.get_klas());
    experience=given.get_experience();
    weapon_equiped=given.is_weapon_equiped();
    shield_equiped=given.is_shield_equiped();
    weapon=given.get_weapon();
    shield=given.get_shield();
    spell_book=new Spell[given.get_spell_book_count()];
    for (int i=0;i<given.get_spell_book_count();i++){
        spell_book[i]=*(given.get_spell_book()+i);
    }
    quests_taken=new Quest[given.get_quests_taken_count()];
    for (int i=0;i<given.get_quests_taken_count();i++){
        quests_taken[i]=*(given.get_quests_taken()+i);
    }
    quests_completed=new Quest[given.get_quests_completed_count()];
    for (int i=0;i<given.get_quests_completed_count();i++){
        quests_completed[i]=*(given.get_quests_completed()+i);
    }
    quests_completed_count=given.get_quests_completed_count();
    quests_taken_count=given.get_quests_taken_count();
    spell_book_count=given.get_spell_book_count();
}


Player::Player(Player const& given):Character::Character(given),klas(NULL),spell_book(NULL),quests_completed(NULL),quests_taken(NULL){
    copy(given);
}

Player& Player::operator=(Player const& given){
    if (this!=&given){
        Character::operator=(given);
        destroy();
        copy(given);
    }
    return *this;
}

Player::Player():Character::Character(),klas(NULL),spell_book(NULL),quests_completed(NULL),quests_taken(NULL){
    char regular[]="No class";
    klas= new char[strlen(regular)+1];
    strcpy(klas,regular);
    quests_taken_count=0;
    quests_completed_count=0;
    spell_book_count=0;
    experience=0;
}

Player::Player(char* name_,char* race_,int dmg_,int def_,int hp_,int lvl_,bool armed_,
                Item* inventory_,int items_count_,int gold_,char* klas_,int experience_,
                Item& weapon_,bool weapon_equiped_,Item& shield_,bool shield_equiped_,
                Spell* book_,int spell_book_count_,Quest* taken_,int quests_taken_count_,
                Quest* completed_,int quests_completed_count_):
                Character::Character(name_,race_,dmg_,def_,hp_,lvl_,armed_,inventory_,items_count_,gold_),
                klas(NULL),spell_book(NULL),quests_completed(NULL),quests_taken(NULL){

    klas=new char[strlen(klas_)+1];
    strcpy(klas,klas_);
    experience=experience_;
    weapon=weapon_;
    shield=shield_;
    shield_equiped=shield_equiped_;
    weapon_equiped=weapon_equiped_;
    quests_completed_count=quests_completed_count_;
    quests_taken_count=quests_taken_count_;
    spell_book_count=spell_book_count_;
    quests_taken=new Quest[quests_taken_count];
    spell_book=new Spell[spell_book_count];
    quests_completed=new Quest[quests_completed_count];
    for (int i=0;i<quests_completed_count;i++){
        quests_completed[i]=*(completed_+i);
    }
    for (int i=0;i<quests_taken_count;i++){
        quests_taken[i]=*(taken_+i);
    }
    for (int i=0;i<spell_book_count;i++){
        spell_book[i]=*(book_+i);
    }

    while (experience>=1000*get_level()) {
        change_level(1);
        experience-=1000*get_level();
    }

    if (weapon_equiped){
        for (int i=0;i<weapon.get_spells_count();i++){
            add_spell(*(weapon.get_spell_list()+i));
        }
    }

    if (shield_equiped){
        for (int i=0;i<shield.get_spells_count();i++){
            add_spell(*(shield.get_spell_list()+i));
        }
    }
}

void Player::print()const{
        cout<<"player: ";
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
    cout<<" ) ";
    int j=0;
    cout<<"( ";
    while (*((get_klas())+j)){
        cout<<*(get_klas()+j);
        j++;
    }
    cout<<" )";
    cout<<"offence: "<<get_offence()<<" defence: "<<get_defence()<<" health: "<<get_health()<<endl;
    cout<<" level: "<<get_level()<<" "<<"experience"<<get_experience();
    if (is_armed()){
        cout<<"( armed )";
    }
    else{
        cout<<"( not armed )";
    }
    cout<<" gold:"<<get_gold()<<endl;
    cout<<"Weapon equiped:"; if (weapon_equiped) {weapon.print_item();} else {cout<<"none"<<endl;}
    cout<<"Shield equiped:"; if (shield_equiped) {shield.print_item();} else {cout<<"none"<<endl;}
    cout<<"****************************************************************************"<<endl;
    cout<<"Inventory: "<<endl;
    if (get_items_in_inventory()!=0){
        for (int i=0;i<items_in_inventory;i++){
            cout<<"Item "<<(i+1)<<endl;
            (inventory+i)->print_item();
        }
    }
    else{
        cout<<"empty";
    }
    cout<<endl;
    cout<<"******************************************************************************"<<endl;
    cout<<"Quests taken:"<<endl;
    if (quests_taken_count==0){cout<<"none"<<endl;}
    else {
            for (int i=0;i<quests_taken_count;i++){
                cout<<"Quest "<<(i+1)<<endl;
                (quests_taken+i)->print_quest();
                 cout<<endl;
            }
    }
    cout<<"****************************************************************************"<<endl;
    cout<<"Completed quests:"<<endl;
    if (quests_completed_count==0){cout<<"none"<<endl;}
    else {
            for (int i=0;i<quests_completed_count;i++){
                cout<<"Quest "<<(i+1)<<endl;
                (quests_completed+i)->print_quest();
                 cout<<endl;
            }
    }
    cout<<"****************************************************************************"<<endl;
    cout<<"Spells in book: "<<endl;
    if (spell_book_count==0){cout<<"none"<<endl;}
    else{
        for (int i=0;i<spell_book_count;i++){
            cout<<"Spell "<<(i+1)<<endl;
            (spell_book+i)->print_spell();
            cout<<endl;
        }
    }
    cout<<endl;
}


void Player::add_spell(Spell const& given){
    int old_count=spell_book_count;
    spell_book_count+=1;
    Spell* new_book=new Spell[spell_book_count];
    for (int i=0;i<old_count;i++){
        new_book[i]=*(spell_book+i);
    }
    new_book[spell_book_count-1]=given;
    delete [] spell_book;
    spell_book=new_book;
}

void Player::lose_spell(Spell const& given){
    bool found=false;
    int i=0;
    for (i;i<spell_book_count;i++){
        if (strcmp((spell_book+i)->get_name(),given.get_name())==0){
            found=true;
            break;
        }
    }
    if (found){
        for (int j=i;j<spell_book_count-1;j++){
                spell_book[j]=spell_book[j+1];
        }
        spell_book_count--;
    }
}

void Player::put_weapon_down(){
    if(weapon_equiped){
        weapon_equiped=false;//������ �� ���� ������
        for (int i=0;i<weapon.get_spells_count();i++){
            lose_spell(*(weapon.get_spell_list()+i));
        }
        add_item(weapon);//����� �������� � ���������
        weapon=Item();
    }
}

void Player::put_weapon_on(const Item& given){//
    bool found=false;
    for(int i=0;i<items_in_inventory;i++){
        if (strcmp((inventory+i)->get_name(),given.get_name())==0){ //���������� �� �� ���� ����� � ������� ����� �� �������� �����
            found=true;
        }

    }
    //��� � �������� ����� ���� � ��������� �� �����
    if (found){ //���� ������� �� �����
        if (weapon_equiped){put_weapon_down();}//��� ��� ������ �� ����� � �� ���� �������
        weapon=given;//����� �����
        weapon_equiped=true;//������ �� ��� ������
        lose_item(given);//���� �� �� ���������
        for (int i=0;i<weapon.get_spells_count();i++){
            add_spell(*(weapon.get_spell_list()+i));
        }//����� ������� �� ����� ���� � ���� ����
    }
    if (!found){ cout<<"No such item in inventory!"<<endl;}
}

//������ �� �� shield


void Player::put_shield_down(){
    if(shield_equiped){
        shield_equiped=false;//������ �� ���� ������
        for (int i=0;i<shield.get_spells_count();i++){
            lose_spell(*(shield.get_spell_list()+i));
        }
        add_item(shield);//����� �������� � ���������
        shield=Item();
    }
}

void Player::put_shield_on(const Item& given){//
    bool found=false;
    for(int i=0;i<items_in_inventory;i++){
        if (strcmp((inventory+i)->get_name(),given.get_name())==0){ //���������� �� �� ���� ����� � ������� ����� �� �������� �����
            found=true;
        }

    }
    //��� � �������� ����� ���� � ��������� �� �����
    if (found){ //���� ������� �� �����
        if (shield_equiped){put_shield_down();}//��� ��� ������ �� ����� � �� ���� �������
        shield=given;//����� �����
        shield_equiped=true;//������ �� ��� ������
        lose_item(given);//���� �� �� ���������
        for (int i=0;i<shield.get_spells_count();i++){
            add_spell(*(shield.get_spell_list()+i));
        }//����� ������� �� ����� ���� � ���� ����
    }
    if (!found){ cout<<"No such item in inventory!Cannot equip it!"<<endl;}
}

int Player::gain_experience(int new_experience){
        experience+=new_experience;
        while (experience>=1000*get_level()) {
        change_level(1); //���� 1 ���
        experience-=1000*get_level();
    }
    return experience; //������ � ����� ������ �� ������ � ����� ������� exp;
}

bool Player::give_gold(int gold_sum,Player& receiver){
    if (gold_sum>get_gold()) {return false;}//���� ������� ���� � �� ���� �� �� ����
    else if(gold_sum>0) {
        reduce_gold(gold_sum);
        receiver.add_gold(gold_sum);
    }
    return true; //���������� � ����������
}



//����������� �����, ����� �� �� ����������,������
//���� ���� ����� �� spellbook ���� ��� � ������
//��������� ������ ���� �� ����� �� ���������!
//����� ��� ��������� �� ��� ���� ����� ��
//����� ������� �� ���� ��� ���� � ���� �� ������ ����� � ������
bool Player::give_item(const char* item_name,Player& receiver){
    bool found=false; int j=0;
    for (int i=0;i<get_items_in_inventory();i++){
        if (strcmp(item_name,(inventory+i)->get_name())==0){
            found=true; j=i; break; //�������� � ����� ���� ������� �� ��������� � ����� �� �����
                                    //������ ���� �������� �� ��� 20 ����� ������� � ��������� � ��� ������ ����� ����
                                    //�� ����� 20 ���� ��� �� ��� ������
        }
    }
    if (!found) {
        return false;
    }
    if (found){
        receiver.add_item(*(inventory+j));
        lose_item(*(inventory+j));
    }
    return true;
}

void Player::add_quest_taken(Quest const& given){
    bool already_in=false;
    for (int i=0;i<quests_taken_count;i++){
        if (*(quests_taken+i)==given){
            already_in=true;
        }
    }
    if (already_in) {
        return;
    }

    int old_count=quests_taken_count;
    quests_taken_count+=1;
    Quest* new_quests_taken=new Quest[quests_taken_count];
    for (int i=0;i<old_count;i++){
        new_quests_taken[i]=*(quests_taken+i);
    }
    new_quests_taken[quests_taken_count-1]=given;
    delete [] quests_taken;
    quests_taken=new_quests_taken;
}

void Player::lose_quest_taken(Quest const& given){
    bool found=false;
    int i=0;
    for (i;i<quests_taken_count;i++){
        if (*(quests_taken+i)==given){
            found=true;
            break;
        }
    }
    if (found){
        for (int j=i;j<quests_taken_count-1;j++){
                quests_taken[j]=quests_taken[j+1];
        }
        quests_taken_count--;
    }
}
//���������� �� quest_completed
void Player::add_quest_completed(Quest const& given){
    bool already_in=false;
    for (int i=0;i<quests_completed_count;i++){
        if (*(quests_completed+i)==given){
            already_in=true;
        }
    }
    if (already_in) {
        return;
    }

    int old_count=quests_completed_count;
    quests_completed_count+=1;
    Quest* new_quests_completed=new Quest[quests_completed_count];
    for (int i=0;i<old_count;i++){
        new_quests_completed[i]=*(quests_completed+i);
    }
    new_quests_completed[quests_completed_count-1]=given;
    delete [] quests_completed;
    quests_completed=new_quests_completed;
}

void Player::lose_quest_completed(Quest const& given){
    bool found=false;
    int i=0;
    for (i;i<quests_completed_count;i++){
        if (*(quests_completed+i)==given){
            found=true;
            break;
        }
    }
    if (found){
        for (int j=i;j<quests_completed_count-1;j++){
                quests_completed[j]=quests_completed[j+1];
        }
        quests_completed_count--;
    }
}

int Player::attack(Creature& target,const Attack_method* att){
    if (get_health()>0){
        engarde(); //��������� �� �� �� �������
        if (!(target.is_armed())){
                if (att==NULL){
                    target.change_hp(max(get_offence(),0)); //����� Dmg
                    target.engarde(); //�������� �� ��������� ���� ���� � ������� ������ ���� ��� ���
                    return max(get_offence(),0); //����� ����� Dmg e ���������
            }
                else if (att!=NULL){
                    target.change_hp(max(get_offence()+att->get_damage(),0)); //����� Dmg
                    target.engarde(); //�������� �� ���������
                    return max(get_offence()+att->get_damage(),0); //����� ����� Dmg e ���������
                }
        }
        else {
            if ((target.is_armed())){
                if (att==NULL){
                target.change_hp(max(get_offence()-target.get_defence(),0)); //����� Dmg
                target.engarde(); //�������� �� ��������� ���� ���� � ������� ������ ���� ��� ���
                return max((get_offence()-target.get_defence()),0); //����� ����� Dmg e ���������
                }
                else if (att!=NULL){
                    target.change_hp(max(((get_offence()+att->get_damage())-target.get_defence()),0)); //����� Dmg
                    target.engarde(); //�������� �� ���������
                    return max((get_offence()-target.get_defence()+att->get_damage()),0); //����� ����� Dmg e ���������
                }

            }
        }
    }
}


void Player::battle(Creature& target,const Attack_method* att,const Attack_method* target_att ){
    int i=1;
    bool target_died=false; bool attacker_died=false;
    while (get_health()>0&&target.get_health()>0&&(get_offence()>0||target.get_offence()>0)){
        cout<<"*****************Round"<<i<<"******************"<<endl; i++;
        if (get_health()>0){
            this->print(); cout<<"HAS DONE ";
            cout<<attack(target,att);
            cout<<"DAMAGE TO ";cout<<endl;
            target.print();
        }
        cout<<endl;
        if (target.get_health()<=0){this->print(); cout<<"HAS WON!"<<endl; target_died=true; break;}

        if (target.get_health()>0){
            target.print(); cout<<"HAS DONE ";
            cout<<target.attack(*this,target_att);
            cout<<" DAMAGE TO "; cout<<endl;
            this->print();
        }
        if (get_health()<=0){target.print(); cout<<"HAS WON!"<<endl; attacker_died=true; break;}
        cout<<endl;
    }
    //��� player � ������� � � ���� Creature,Monster ��� Boss ��� �����������
    if (target_died&&(typeid(target)==typeid(GenericCreature))){
        gain_experience(target.get_level());
    }

    else if (target_died&&(typeid(target)==typeid(GenericMonster))){
        gain_experience(target.get_level());//����� exp
        add_gold(target.get_loot().get_gold());//����� gold
        for (int i=0;i<target.get_loot().get_items_count();i++){//������ �������
            add_item(*(target.get_loot().get_item_arr()+i));
        }
    }
    else if (target_died&&(typeid(target)==typeid(GenericBoss))){
        gain_experience(target.get_level());//����� exp
        add_gold(target.get_loot().get_gold());//����� gold
        for (int i=0;i<target.get_loot().get_items_count();i++){//������ �������
            add_item(*(target.get_loot().get_item_arr()+i));
        }
        for (int i=0;i<quests_taken_count;i++){//������ ����� ��� �� ��� ����
            if (*(quests_taken+i)==target.get_boss_quest()){
                add_quest_completed(target.get_boss_quest());
                lose_quest_taken(target.get_boss_quest());
            }
        }
    }
}

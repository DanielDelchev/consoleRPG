#include "windows.h"
#include <iostream>
#include "spell.h"
#include "boss.h"
#include "player.h"
#include "quest.h"
#include "quest_giver.h"
#include "items_quests_spells_etc.h"
using namespace std;

int main()
{   system ("color 02");

    //attack tests
    cout<<"************************START_OF_ATTACK_METHOD_TESTS*******************"<<endl;
    Attack_method slap;
    Attack_method shoot(10);
    cout<<slap.get_damage()<<endl;
    slap.change_damage(100);
    cout<<slap.get_damage()<<endl;
    cout<<shoot.get_damage()<<endl;
    cout<<"************************END_OF_ATTACK_METHOD_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    // spells test
    cout<<"************************START_OF_SPELLS_TESTS*******************"<<endl;
    Spell one;
    one.print_spell();
    char spell_1[]="frost bolt";
    char spell_2[]="fire ball";
    char* p_spell_1=spell_1;
    char* p_spell_2=spell_2;
    Spell first(p_spell_1,10);
    Spell second(p_spell_2,30);
    first.print_spell();
    second.print_spell();
    first.print_spell();
    Spell third=second;
    third.print_spell();
    Spell another(p_spell_1,7);
    third=another;
    third.print_spell();
    cout<<"************************END_OF_SPELLS_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //spell array test
    cout<<"************************START_OF_SPELL_ARRAY_TESTS*******************"<<endl;
    Spell arr[]={one,first,second,another,third};
    for (int i=0;i<5;i++){
        arr[i].print_spell();
    }
    cout<<"************************END_OF_SPELL_ARRAY_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //item tests
    cout<<"************************START_OF_ITEMS_TESTS*******************"<<endl;
    Item generic;
    cout<<generic.get_offence()<<endl;
    generic.print_item();
    Spell first_arr[]={first,second};//2
    Spell second_arr[]={second,first};//2
    char item_name_1[]="desolator";
    char item_name_2[]="medal of courage";
    char* p_item_2=item_name_2;
    char* p_item_1=item_name_1;
    cout<<endl;
    shovel_of_ultimate_destruction.print_item(); cout<<endl;
    Item sword(10,7,8,12,p_item_1,first_arr,2);
    Item helmet(1,13,12,3,p_item_2,second_arr,2);
    sword.print_item();
    cout<<endl;
    helmet.print_item();
    cout<<endl;
    Item forgery=sword;
    forgery.print_item();
    forgery=helmet;
    cout<<endl;
    forgery.print_item();
    cout<<"************************END_OF_ITEMS_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //loot tests
    cout<<"************************START_OF_LOOT_TESTS*******************"<<endl;
    Loot normal;
    normal.print_loot(); cout<<endl;
    Item list_of_items[]={sword,helmet,forgery,sword};//4
    Item* p_list=list_of_items;
    Item list_of_items2[]={sword,helmet};//2
    Item* p_list2=list_of_items2;
    Loot built(p_list,4,125);
    built.print_loot();
    Loot built2(p_list2,2,100);
    built2.print_loot();
    Loot yet_another(built);
    yet_another.print_loot();
    yet_another=built2;
    yet_another.print_loot();
    cout<<"************************END_OF_LOOT_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //quest tests
    cout<<"************************START_OF_QUESTS_TESTS*******************"<<endl;
    Quest qwerty;
    qwerty.print_quest();

    Quest qwerty2(built2,20000);
    qwerty2.print_quest();
    cout<<"************************END_OF_QUESTS_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //creature tests
    cout<<"************************START_OF_CREATURE_TESTS*******************"<<endl;
    Creature ordinary;
    ordinary.print();
    ordinary.engarde();

    char name_ []="Illidan";
    char race_[]="nightelf";

    Creature cr_1(name_,race_,100,17,202,30,1);
    cr_1.print();

    ordinary=cr_1;
    ordinary.print();

    Creature cpycnstr=cr_1;
    cpycnstr.print();

    char name2_[]="Uther";
    Creature another_creature(name2_,race_,100,17,202,30,1);
    cout<<"************************END_OF_CREATURE_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //monster tests
    cout<<"************************START_OF_MONSTER_TESTS*******************"<<endl;
    Monster guy;
    guy.print();
    Monster strong (name_,race_,2,4,5,3,1,built2);
    strong.print();
    Monster copied=strong;
    copied.print();
    cout<<"************************END_OF_MONSTER_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    cout<<"************************START_OF_BOSS_TESTS*******************"<<endl;
    //boss tests
    char uno[]="cow";
    Boss edno(name_,race_,90,15,180,29,1,built2,one1);
    Boss dve(uno,race_,80,20,9,2,1,built,two2);
    edno.print();cout<<endl<<endl;
    dve.print();cout<<endl<<endl;
    Boss tri=dve;
    tri.print();cout<<endl<<endl;
    tri=edno;
    tri.print();
    cout<<"************************END_OF_BOSS_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    //character tests
    cout<<"************************START_OF_CHARACTER_TESTS*******************"<<endl;
        john.print(); //john  � ��������� � items_quests_spells_etc.h
        Character  other=john;
        other.print();
        Character gen;
        gen.print();
        gen=john;
        gen.print();
    cout<<"************************ADDING_ITEMS_TO_INVENTORY_TESTS*******************"<<endl;
        //�� ������ (��� ������������) � ��������� ��� ���� 2 ����� ��������
        //�������� 3 ������
        john.add_item(shovel_of_ultimate_destruction);
        john.add_item(shovel_of_ultimate_destruction);
        john.add_item(shovel_of_ultimate_destruction);
        john.print();
    cout<<"************************REMOVING_ITEMS_FROM_INVENTORY_TESTS*******************"<<endl;
        //������ 1 ���� �������� � 5 ����� ������ (���� 3�� ����� ������ ����� �� ������� 2 ���� �� ����� ���� �� ����)
        john.lose_item(gloves_of_haste);
        john.lose_item(shovel_of_ultimate_destruction);
        john.lose_item(shovel_of_ultimate_destruction);
        john.lose_item(shovel_of_ultimate_destruction);
        john.lose_item(shovel_of_ultimate_destruction);
        john.lose_item(shovel_of_ultimate_destruction);//��� �������� �� ������ item ���� �� ���� ���� �� �� ������
        john.print();//������� � � 1 ���� ��������
    cout<<"************************END_OF_CHARACTER_TESTS*******************"<<endl;
    system("pause");
    system("cls");
    cout<<"************************START_OF_BATTLE_TESTS*******************"<<endl;
    char name5_ []="Illidan";
    char race5_[]="nightelf";

    Creature elf(name5_,race5_,10,20,200,30,0);


    char name7_ []="Death Knight";
    char race7_[]="undead";

    Creature und(name7_,race7_,18,8,250,35,0);
    cout<<"***********************BATTLE_1*********************************"<<endl;
    cout<<"***********************2_CREATURES_FIGHT************************"<<endl;
    und.battle(elf,&freeze,&smite);
    system("pause");
    system("cls");
    cout<<"***********************BATTLE_2*********************************"<<endl;
    cout<<"***********************BOSS_AND_CREATURE_FIGHT******************"<<endl;
    edno.battle(another_creature);
    cout<<"************************END_OF_BATTLE_TESTS*******************"<<endl;
    system("pause");
    system("cls");



    cout<<"***********************START_OF_PLAYER_TESTS*************************"<<endl;
    player_two.print(); //player_one � player_two �� ��������� � items_quets_spells_etc.h!!!
    cout<<"***********************PLAYER_LOSES_SPELL_TEST************************"<<endl;
    player_two.lose_spell(windwalk); //���� �� ���� ����� � �� ������
    player_two.print();
    system("pause");
    system("cls");
    cout<<"***********************EQUIPING_ITEMS_TEST***************************"<<endl;
    player_two.put_weapon_on(gloves_of_haste);//����� �� ���� � ������ ���� �������� ����� �� ���� � ��������� � ����� ��� ����
    player_two.print();
    player_two.put_shield_down();//����� �� ����
    player_two.print();
    player_two.put_shield_on(shovel_of_ultimate_destruction);//���� �� � ��������� � �� ���� �� �� �����
    player_two.print();
    system("pause");
    system("cls");
    cout<<"***********************TRANSFERING_GOLD_TESTS***************************"<<endl;
    cout<<"BEFORE TRANSFERING ANY GOLD"<<endl;
    player_two.print();//��� 250 gold
    player_one.print();//��� 350 gold
    system("pause");
    system("cls");
    cout<<"PLAYER ONE WANTS TO GIVE 500 GOLD TO PLAYER TWO BUT DOESN`T HAVE ENOUGH GOLD"<<endl;
    cout<<"NOTHING CHANGES"<<endl;
    player_one.give_gold(500,player_two);//���� ������� gold  � �� �� ����
    player_one.print();
    player_two.print();
    system("pause");
    system("cls");
    cout<<"PLAYER ONE GIVES 200 GOLD TO PLAYER TWO"<<endl;
    player_one.give_gold(200,player_two);//��� ������� gold  � �� ����
    player_one.print();
    player_two.print();
    system("pause");
    system("cls");
    cout<<"***********************TRANSFERING_ITEMS_TEST***************************"<<endl;
    cout<<"BEFORE ITEM TRANSFER"<<endl;
    player_one.print();
    player_two.print();
    system("pause");
    system("cls");
    player_two.give_item(golden_bow.get_name(),player_one);
    cout<<"AFTER ITEM TRANSFER"<<endl;
    player_one.print(); //����������� ����� (�� ��� �� ������� �� �������� ��� �� ��� ���,
    player_two.print();//��� �� ���� ���� �� �����), ����� �� �� ����������,������
                        //���� ���� ����� �� spellbook ���� ��� � ������
                        //��������� ������ ���� �� ����� �� ���������!
                        // ����� ��� ��������� �� ��� ���� ����� �� ����� ������� � spellbook ������ �����
    system("pause");
    system("cls");
    cout<<"*********CONSTRUCTOR_WITHOUT_PARAMETERS_FOR_PLAYER***************************"<<endl;
    Player no_param;//������ �� ������� ���� ������ �� ����� �� ���� � � �� �����
    no_param.print();
    system("pause");
    system("cls");
    cout<<"*********OPERATOR == FOR QUEST TEST****************************************"<<endl;
    cout<<(one1==two2)<<endl; //0
    cout<<(three3==three3)<<endl;//1
    cout<<(four4==four4)<<endl;//1
    cout<<(one1==four4)<<endl;//0
    system("pause");
    system("cls");
    cout<<"*********ADDING/LOSING QUESTS TESTS***************************"<<endl;
    cout<<"*********TAKEN QUESTS******************************************"<<endl;
    cout<<"BEFORE ADDING QUESTS"<<endl;
    no_param.print();
    no_param.add_quest_taken(one1);
    no_param.add_quest_taken(two2);
    cout<<"AFTER ADDING QUESTS"<<endl;
    no_param.print();
    no_param.add_quest_taken(one1);//���� �� �� ������ 2�� ���
    no_param.lose_quest_taken(three3);//���� �� �� ����� ���� �� ����
    no_param.lose_quest_taken(one1);//��� �� � �� ����
    cout<<"AFTER LOSING 1 QUESTS"<<endl;
    no_param.print();
    no_param.lose_quest_taken(two2);
    cout<<"AFTER LOSING THE OTHER QUESTS"<<endl;
    no_param.print();
    system("pause");
    system("cls");
    //���������� �� quest_completed
    cout<<"*********QUESTS COMPLETED******************************************"<<endl;
    Player no_param2;
    no_param2.add_quest_completed(one1);
    no_param2.add_quest_completed(one1);//���� �� �� ����� 2�� ���
    no_param2.add_quest_completed(two2);
    no_param2.add_quest_completed(three3);
    no_param2.print();
    no_param2.lose_quest_completed(four4);//���� �� � ���� �� �� ������
    no_param2.lose_quest_completed(one1);
    no_param2.lose_quest_completed(two2);
    no_param2.lose_quest_completed(three3);
    no_param2.print();//������� ��� �����
    no_param2.add_quest_completed(four4);// �������� 1 ���
    no_param2.print();
    //quest giver �� ������ ���� ������ ��-�����
    cout<<"****************END OF PLAYER TESTS**************************************"<<endl;
    system("pause");
    system("cls");
    cout<<"****************START OF MERCHANT TESTS**************************************"<<endl;
    cout<<"***************PLAYER SELLS ITEM TO MERCHANT********************************"<<endl;
    player_one.print();
    Merchant magazin;
    char ime[]="golden bow";
    magazin.buy(ime,player_one); //merchant buys the item from the player
    player_one.print();//������� � player ����� � � ���� ���������� �� � �����
    system("pause");
    system("cls");
    //������� � ������� ����� �� ����������� � merchant.cpp
    //������� ����� ����� �� �� ������� �� ����� ���� � �� ����� ����������
    //(� ������� �� 7 �� ����� �������� �� �� ������� ���)
    char ime2[]="club of war";
    char ime3[]="shield of war";
    char ime4[]="ring of health";
    char ime5[]="jacket of coolness";//���� ������� ���� �� ���� �� �� ����
    cout<<"***************PLAYER BUYSS ITEMS FROM MERCHANT********************************"<<endl;
    magazin.sell(ime2,player_one);
    magazin.sell(ime3,player_one);
    magazin.sell(ime4,player_one);
    magazin.sell(ime5,player_one);
    player_one.print();//����� � ������� 3 ����� � � ������� ���� ������� �� � ����������
                        //�� � ����� ��������� ���� ������ ���� ������� ����
    cout<<"***************END OF MERCHANT TESTS********************************"<<endl;
    system("pause");
    system("cls");
    cout<<"********QUEST GIVER TESTS********************************************"<<endl;
    cout<<"*******PLAYER TAKES QUEST FROM QUEST GIVER*****************************"<<endl;
    Quest_giver warlock(five5);
    player_two.print();
    warlock.begin_quest(player_two);//player_two � ���� ������
    player_two.print();
    system("pause");
    system("cls");
    cout<<"*************PLAYER GETS REWARD FROM QUEST GIVER FOR COMPLETED QUEST*******"<<endl;
    Quest_giver generous(four4);//�� ���� quest_giver player_TWO �� ��� ������ � completed_quests;
    generous.get_reward(player_two);
    player_two.print();//���� ���� � ����� ������ ���� �� ���� � ������� � ������, ����� ��� ���� ,����� ��� ������� � ��������� � ��� �����
                        //exp � ��� ������� �����(���������� ��� exp � ���������� � ������ �� 3 ����� 4 ���)
    cout<<"****************END OF QUEST GIVER TESTS*******************************"<<endl;
    system("pause");
    system("cls");


    cout<<"*************START OF BATTLE TESTS FOR PLAYER*************"<<endl;
    cout<<"PLAYER 'ONE' `S  EXP BEFORE KILLING A CREATURE"<<endl;
    cout<<"EXP"<<player_one.get_experience()<<"EXP"<<endl;
    player_one.battle(und);//����� creature  ����� ���
    cout<<endl<<"PLAYER 'ONE' `S EXP AFTER KILLING A CREATURE"<<endl;
    cout<<"EXP"<<player_one.get_experience()<<"EXP"<<endl;
    system("pause");
    system("cls");

    cout<<"PLAYER 'TWO'  BEFORE KILLING A MONSTER"<<endl;
    player_two.print();//����� �� � 1 hit
    player_two.battle(strong,(player_two.get_weapon().get_spell_list()),&shoot);//����� ������� � ����� ����� gold � exp
    cout<<"PLAYER 'TWO'  AFTER KILLING A MONSTER"<<endl;
    player_two.print();
    system("pause");
    system("cls");

    cout<<"PLAYER 'TWO'  BEFORE KILLING A BOSS"<<endl;
    player_two.print();
    system("pause");
    system("cls");
    player_two.battle(diablo,(player_two.get_weapon().get_spell_list()),&freeze);//����� boss � ����� ����� gold � exp
                                                                                //� ����� ������ �� ���� boss �� taken � completed
    system("pause");
    system("cls");
    cout<<"PLAYER 'TWO'  AFTER KILLING A BOSS"<<endl;
    player_two.print();
    system("pause");
    system("cls");

    cout<<"PLAYER 'TWO' BEFORE GETTING REWARD FOR THE QUEST OF THE KILLED BOSS"<<endl;
    player_two.print();
    Quest_giver giver(three3);//����� �� reward �� ������
    system("pause");
    system("cls");
    giver.get_reward(player_two);
    cout<<"PLAYER 'TWO' AFTER GETTING REWARD FOR THE QUEST OF THE KILLED BOSS"<<endl;
    player_two.print();
    system("pause");
    system("cls");

    cout<<"******************************END OF TESTS******************************"<<endl;
    return 0;
}

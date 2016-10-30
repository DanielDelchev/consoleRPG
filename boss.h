#ifndef BOSS_H_INCLUDED
#define BOSS_H_INCLUDED
#include "monster.h"
#include "quest.h"
class Boss:public Monster{
public:
    Boss();//
    Boss(char*,char*,int,int,int,int,bool,Loot const& ,Quest const& given);//
    void copy(Boss const& given);
    void destroy();//
    virtual ~Boss();//
    Boss(Boss const& given);//
    Boss& operator=(Boss const& given);//
    const Quest& get_boss_quest()const;//
    virtual void print()const;//
private:
    Quest quest;                                    //
};

#endif // BOSS_H_INCLUDED

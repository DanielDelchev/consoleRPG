#ifndef MERCHANT_H_INCLUDED
#define MERCHANT_H_INCLUDED
#include "player.h"
//предполага се че можем да му продадем всеки итем без значение какъв е стига да е в нашата инвентория
// може и итема който носим да продадем но първо трябва да го свалим в инвентори и после да го продадем
//и може да купим който и да е итем и да го получим отново в инвенторията ни (стига да имаме толкова gold)


//не е предвидено merchant И questgiver да участват в битки затова нямат конструктори с параметри както другите класове
//няма и свой принт
class Merchant:public Character{
public:
    Merchant();
    Merchant& operator=(Merchant const& given);
    Merchant(Merchant const& given);
    void copy(Merchant const& given);
    void destroy();
    virtual ~Merchant();
    int buy(const char* item_name,Player& seller);//merchant buys the item and the gives player gold
    int sell(const char* item_name,Player& buyer);//Player sells the item and gets gold,merchant does not need to lose gold
private:
};
#endif // MERCHANT_H_INCLUDED

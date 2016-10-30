#ifndef MERCHANT_H_INCLUDED
#define MERCHANT_H_INCLUDED
#include "player.h"
//���������� �� �� ����� �� �� �������� ����� ���� ��� �������� ����� � ����� �� � � ������ ����������
// ���� � ����� ����� ����� �� �������� �� ����� ������ �� �� ������ � ��������� � ����� �� �� ��������
//� ���� �� ����� ����� � �� � ���� � �� �� ������� ������ � ������������ �� (����� �� ����� ������� gold)


//�� � ���������� merchant � questgiver �� �������� � ����� ������ ����� ������������ � ��������� ����� ������� �������
//���� � ���� �����
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

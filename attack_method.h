#ifndef ATTACK_METHOD_H_INCLUDED
#define ATTACK_METHOD_H_INCLUDED
class Attack_method{
public:
    Attack_method();
    Attack_method(int given);
    void destroy();
    void copy(Attack_method const& given);
    virtual ~Attack_method();
    Attack_method(Attack_method const& given);
    Attack_method& operator=(Attack_method const& given);
    int get_damage()const;
    void change_damage(int given);
private:
    int damage;
};




#endif // ATTACK_METHOD_H_INCLUDED

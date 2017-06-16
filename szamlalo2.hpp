#ifndef SZAMLALO2_HPP_INCLUDED
#define SZAMLALO2_HPP_INCLUDED
#include "ososztaly.h"
#include "graphics.hpp"

using namespace std;

class szamlalo2 : public widget
{
protected:
    bool kivalasztva;
    int szamol;

public:
    szamlalo2(int a, int b, int mereta, int meretb);
    void kirajzol();
    void csinal(genv::event ev);
    string aktualis();

    //szamlalo(int a, int b, int mereta, int meretb) : widget(a, b, mereta, meretb){}
};

#endif // SZAMLALO_HPP_INCLUDED

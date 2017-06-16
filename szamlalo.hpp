#ifndef SZAMLALO_HPP_INCLUDED
#define SZAMLALO_HPP_INCLUDED
#include "ososztaly.h"
#include "graphics.hpp"

using namespace std;

class szamlalo : public widget
{
protected:
    bool kivalasztva;
    int szamol;
    int minimum;
    int maximum;
public:
    szamlalo(int a, int b, int mereta, int meretb, int minimum, int maximum);
    void kirajzol();
    void csinal(genv::event ev);
    string  aktualis();

    //szamlalo(int a, int b, int mereta, int meretb) : widget(a, b, mereta, meretb){}
};

#endif // SZAMLALO_HPP_INCLUDED

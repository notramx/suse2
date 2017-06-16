#ifndef GOMB_HPP_INCLUDED
#define GOMB_HPP_INCLUDED

#include "ososztaly.h"
#include "graphics.hpp"
#include "vector"

using namespace std;
using namespace genv;

class gomb : public widget
{
protected:
    string szoveg;

public:
    kivalaszto(int a, int b, int mereta, int meretb, string kiir);
    void kirajzol();
    void csinal(genv::event ev);
    bool folottevane(int egerx, int egery);
    string aktualis();
    string kivalasztott();
};

#endif // GOMB_HPP_INCLUDED

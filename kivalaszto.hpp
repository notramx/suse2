#ifndef KIVALASZTO_HPP_INCLUDED
#define KIVALASZTO_HPP_INCLUDED
#include "ososztaly.h"
#include "graphics.hpp"
#include "vector"

using namespace std;
using namespace genv;

class kivalaszto : public widget
{
protected:
    vector<string>lehetoseg;
    int kivalasztott_indexe = -1;
    string hozzaad = "";
public:
    kivalaszto(int a, int b, int mereta, int meretb);
    void kirajzol();
    int hanyadik(event ev);
    void csinal(genv::event ev);
    bool folottevane(int egerx, int egery);
    string aktualis();
    string kivalasztott();
};


#endif // KIVALASZTO_HPP_INCLUDED

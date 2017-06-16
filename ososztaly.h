#ifndef OSOSZTALY_H_INCLUDED
#define OSOSZTALY_H_INCLUDED
#include <string>
#include "graphics.hpp"

using namespace std;

class widget
{
protected:
    int meretx, merety, fixx, fixy;

public:
    widget(int a, int b, int mereta, int meretb);
    virtual bool folottevane(int egerx, int egery); ///eger aktualis pozicioja az adott widget felett van e ahol dolgozni akarunk
    virtual void csinal(genv::event ev); ///adott widget működese
    virtual void kirajzol(); ///kirajzolja az adott widgetet
    bool kivalasztva; ///megadja melyyik widget van epp kivalasztva
    virtual string aktualis() const; ///fajlba irashoz fuggveny
    virtual string kivalasztott() const; ///fajlba irashoz seged fuggveny
};

#endif // OSOSZTALY_H_INCLUDED

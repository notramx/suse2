#include "ososztaly.h"
#include "graphics.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace genv;

widget::widget(int a, int b, int mereta, int meretb)
{
    fixx = a;
    fixy = b;
    meretx = mereta;
    merety = meretb;
}

bool widget::folottevane(int egerx, int egery)
{
    if ((fixx <= egerx && fixx+meretx >= egerx) && (fixy <= egery && fixy + merety >= egery))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void widget::csinal(genv::event ev)
{

}
void widget::kirajzol()
{
    gout << color(0,0,0);
    gout << move_to(160,30) << text("Kedves Felhasználó!");
    gout << move_to(25, 60) << text("ENTER: Textboxok lehetosegeinek hozzaadasa a listahoz. ");
    gout << move_to(60, 80) << text("F5: Widgetek aktualis tartalmanak mentese.");
}
string widget::aktualis() const
{

}

string widget::kivalasztott() const
{

}

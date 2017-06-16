#include "kivalaszto.hpp"
#include "ososztaly.h"
#include "graphics.hpp"
#include "cstdlib"
#include "sstream"
#include "iostream"
#include "vector"

using namespace genv;
using namespace std;

kivalaszto::kivalaszto(int a, int b, int mereta, int meretb)
    :widget(a,b,mereta,meretb)
{
    lehetoseg.push_back("proba");

}

void kivalaszto::kirajzol()
{
    gout << color(208, 204, 204) << move_to(fixx, fixy-110) << box(meretx, 20);
    gout << color (237, 237, 237) << move_to(fixx+1, fixy-109) << box(meretx-2, 18);
    gout << color(0,0,0) << move_to(fixx+2, fixy-110+gout.cascent()) << text(hozzaad);
    gout << color(0,0,0) << move_to(fixx-60, fixy-110+gout.cascent()) << text("cím");

    gout << color(208,204,204) << move_to(fixx+100, fixy-40) << box(80, 30);
    gout << color(237, 237, 237) << move_to(fixx+101, fixy-39) << box(78, 28);
    gout << color(0,0,0) << move_to(fixx+110, fixy-34+gout.cascent()) << text("hozzáad");

    gout << color(208,204,204) << move_to(fixx, fixy+merety+10) << box(meretx, 30);
    gout << color(237, 237, 237) << move_to(fixx+1, fixy+merety+11) << box(meretx-2, 28);
    gout << color(0,0,0) << move_to(fixx+25+gout.twidth("Torol"), fixy+merety+15+gout.cascent())  << text("Torol");

    for(int i=kivalasztott_indexe; i<lehetoseg.size(); i++)
    {
        if(i<(merety/20)+kivalasztott_indexe)
        {
            if(i==kivalasztott_indexe )
            {
                gout << color(0,255,255) << move_to(fixx,(i-kivalasztott_indexe)*20+fixy) << box(meretx,20) << color(0,0,255) << move_to((fixx)+3,(fixy+((i-kivalasztott_indexe)*20+1)+gout.cascent())) << text(lehetoseg[i]);
            }
            else
            {
                gout << color(0,255,0) << move_to((fixx)+3,(fixy+((i-kivalasztott_indexe)*20+1)+gout.cascent())) << text(lehetoseg[i]);
            }
        }
    }
    gout << color(208, 204, 204)  << move_to(fixx, fixy) << box(meretx, merety);
    gout << color(237, 237, 237) << move_to(fixx+1, fixy+1) << box(meretx-2, merety-2);

    for(int i=0; i<lehetoseg.size(); i++)
    {
        if ( merety/20 >= i+1 )
        {
            if (kivalasztott_indexe == i )
            {
                gout << color(123,123,123) << move_to(fixx, fixy+20*i) << box(meretx, 20);
                gout << color(255,255,255) << move_to(fixx+2, fixy+15+(20*i)) << text(lehetoseg[i]);
            }
            else
            {
                gout << color(0,0,0) << move_to(fixx+2, fixy+15+(20*i)) << text(lehetoseg[i]);
            }
        }
    }
}
bool kivalaszto::folottevane(int egerx, int egery)
{
    if ((fixx <= egerx && fixx+meretx >= egerx) && (fixy-110 <= egery && (fixy+merety+110) >= egery))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int kivalaszto::hanyadik(event ev)
{
    "megmondja melyik vidgeten vagy";
    int a;
    if(((fixx <= ev.pos_x && fixx+meretx >= ev.pos_x) && (fixy <= ev.pos_y && fixy + merety >= ev.pos_y)) && ev.button == btn_left)
    {
        kivalasztott_indexe = a;
    }
    return a;
}
void kivalaszto::csinal(genv::event ev)
{
    "string hozzáadás";
    int a = (ev.pos_y-fixy)/20;
    if(((fixx <= ev.pos_x && fixx+meretx >= ev.pos_x) && (fixy <= ev.pos_y && fixy + merety >= ev.pos_y)) && ev.button == btn_left)
    {
        kivalasztott_indexe = a;
    }
    if ( ev.type == ev_key && ev.keycode >= 32 && ev.keycode <= 162)
    {
        hozzaad = hozzaad + (char)ev.keycode;
    }

    if (gout.twidth(hozzaad) > meretx)
    {
        hozzaad.resize(hozzaad.length()-1);
    }

    if (ev.keycode == key_backspace && hozzaad.length() != 0)
    {
        hozzaad.resize(hozzaad.length()-1);
    }
    if (ev.type==ev_mouse && ev.button == btn_left && ev.pos_x> fixx+ 101 && ev.pos_x < fixx+180 && ev.pos_y > fixy-39 && ev.pos_y < fixy-9) ///!!!!
    {
        lehetoseg.push_back(hozzaad);
        hozzaad.clear();
    }
"számbeallítás" ;

    if(ev.type==ev_mouse && ev.button == btn_left && ev.pos_x>=fixx+meretx && ev.pos_x<=fixx+meretx+10  && ev.pos_y>=fixy && ev.pos_y<=fixy+merety)
    {
        if(ev.pos_y>=fixy+merety-20)
        {
            kivalasztott_indexe++;
        }
        else if(ev.pos_y<=fixy-20)
        {
            kivalasztott_indexe--;
        }
        if(kivalasztott_indexe <=0)
        {
            kivalasztott_indexe=0;
        }
        if(kivalasztott_indexe > lehetoseg.size()-( merety/20))
        {
            kivalasztott_indexe = lehetoseg.size()-(merety/20);
        }
    }


    "törlés";
//    if (ev.type == ev_mouse && ev.button == btn_left && ev.pos_x > fixx && ev.pos_x < fixx+meretx && ev.pos_y > fixy+merety +30 && fixy <= fixy+merety+60)
//    {
//        for (int i=0; i < lehetoseg.size(); i++)
//        {
//            lehetoseg[i].clear();
//            lehetoseg[i] = lehetoseg[i-1];
//        }
//    }
}

string kivalaszto::kivalasztott()
{
    if(kivalasztott_indexe>=0 && kivalasztott_indexe<=lehetoseg.size())
    {
        return lehetoseg[kivalasztott_indexe];
    }

    return "nincs kiv";
}

string kivalaszto::aktualis()
{
    string s;
    s =" kivalasztott opcio " + kivalasztott();
    return s;
}

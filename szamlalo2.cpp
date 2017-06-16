#include "szamlalo2.hpp"
#include "ososztaly.h"
#include "graphics.hpp"
#include "cstdlib"
#include "sstream"
#include "iostream"

using namespace genv;
using namespace std;

szamlalo2::szamlalo2(int a, int b, int mereta, int meretb)
    :widget(a,b,mereta,meretb)
{
    szamol = 1;
}

void szamlalo2::kirajzol()
{
    gout << color(208, 204, 204) << move_to(fixx, fixy) << box(meretx, merety);
    gout << color(0,0,0) << move_to(110, 165+gout.cascent()) << text("hossz");
    gout << color(237, 237, 237) << move_to (fixx+1, fixy+1) << box(meretx-20, merety-2); ///amiben a szam van
    gout << color(247, 247, 247) << move_to(fixx+62, fixy+1) << box(meretx-63, merety-17); ///növekedes
    gout << color(156, 158, 153) << move_to(fixx+67, fixy+12) << text("+");
    gout << color(247,247,247) << move_to(fixx+62, fixy+16) << box(meretx-63, merety-17); ///csokkenes
    gout << color(156,158,153) << move_to(fixx+67, fixy+20) << text("_");

    string s;
    stringstream szam;
    szam << szamol;
    szam >> s;
    gout << color(0,0,0) << move_to(fixx+5, fixy+20) << text(s);
}

void szamlalo2::csinal(genv::event ev)
{
    if (ev.button == btn_left  && folottevane(ev.pos_x, ev.pos_y))
    {
        if (fixx+62 <= ev.pos_x && (fixx+62)+(meretx-63) >= ev.pos_x &&  fixy+1 <= ev.pos_y && (fixy+1)+(merety-17)>= ev.pos_y)
        {
            szamol++;
        }
        else if(fixx+62 <= ev.pos_x && fixx+62+meretx-63 >= ev.pos_x && fixy+16 <= ev.pos_y && fixy+16+merety-17 >= ev.pos_y)
        {
            szamol--;
        }
    }
    if ( ev.keycode == key_down) szamol--;
    if (ev.keycode == key_up) szamol++;

    if (ev.keycode == key_pgup) szamol+=10;
    if (ev.keycode == key_pgdn) szamol-=10;

    if (szamol <= 0 ) szamol = 0;

}
string szamlalo2::aktualis()
{
    string s;
    stringstream szam;
    szam << szamol;
    szam >> s;
    return s;
}

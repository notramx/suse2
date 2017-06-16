#include "graphics.hpp"
#include "ososztaly.h"
#include "szamlalo.hpp"
#include "szamlalo2.hpp"
#include "vector"
#include "stdlib.h"
#include "time.h"
#include "iostream"
#include"kivalaszto.hpp"
#include "fstream"

using namespace genv;

int main()
{
    gout.open(500,500);
    gout << color(170,170,170) << move_to(0,0) << box(500,500);
    srand(time(NULL));
    vector<widget*>widgetek;
    widget *ora= new szamlalo(170,120,80,30,0,23);
    widgetek.push_back(ora);
    widget *perc = new szamlalo(270, 120, 80, 30, 0, 59);
    widgetek.push_back(perc);
    widget *hossz = new szamlalo2(170, 160, 80, 30);
    widgetek.push_back(hossz);
    widget *kiv1 = new kivalaszto(170,200,180,200);
    widgetek.push_back(kiv1);

    for (int i = 0; i < widgetek.size(); i++)
    {
        widgetek[i]->kirajzol();
    }
    event ev;
    gout << refresh;
    while(gin >> ev)
    {
        for (int i = 0; i < widgetek.size(); i++)
        {
            widgetek[i]->kirajzol();
        }
        gout << refresh;

        if (ev.type == ev_mouse && ev.button == btn_left)
        {
            for(int i = 0; i < widgetek.size(); i++)
            {
                if(widgetek[i] -> folottevane(ev.pos_x, ev.pos_y))
                {
                    widgetek[i] ->  kivalasztva = true;
                }
                else
                {
                    widgetek[i] -> kivalasztva = false;
                }
            }
        }

        for (int i=0; i < widgetek.size(); i++)
        {
            if(widgetek[i] -> kivalasztva == true)
            {
                widgetek[i]->csinal(ev);
                //widgetek[i] -> gorgeto(ev);
            }
        }
    }


    return 0;
}

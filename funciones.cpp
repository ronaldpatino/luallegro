//
// Created by ronald on 07/07/15.
//

#include <allegro.h>
#include <lua.hpp>
#include "funciones.h"
#include "16fade.h"
#include <iostream>



BITMAP *bmp = NULL;
PALETTE paleta;

int decir(lua_State *l){

    int x = lua_tointeger(l, 1);
    int y = lua_tointeger(l, 2);
    const char *s =lua_tostring(l, 3);
    std::cout << s << std::endl;
    textout_ex(screen, font, s, x, y,
               makecol(0, 0, 255), -1);
    return 0;
}

int wait(lua_State *l){
    readkey();
}

int cargar_imagen(lua_State *l){
    const char *imagen = lua_tostring(l, 1);
    std::cout << imagen << std::endl;
    bmp = load_bmp(imagen, paleta);
    if (bmp){
        std::cout << "CARGANDO BMP" << imagen << std::endl;
    }
    return 0;
}

int fin(lua_State *l){
    int tiempo=lua_tonumber(l,1);
    highcolor_fade_in(bmp, tiempo);

}


int fout(lua_State *l){
    int tiempo=lua_tonumber(l,1);
    highcolor_fade_out(tiempo);
}

int wait(){
    readkey();
}
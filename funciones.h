//
// Created by ronald on 07/07/15.
//

#ifndef LUALLEGRO_FUNCIONES_H
#define LUALLEGRO_FUNCIONES_H
#include <lua.hpp>

int decir(lua_State *l);
int fin(lua_State *l);
int fout(lua_State *l);
int cargar_imagen(lua_State *l);
int wait(lua_State *l);

#endif //LUALLEGRO_FUNCIONES_H

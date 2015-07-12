//
// Created by ronald on 07/07/15.
//

#include "luastuff.h"

lua_State * init_lua(){

    lua_State *lua_state = luaL_newstate();

    static const luaL_Reg lualibs[] =
            {
                    {"base", luaopen_base},
                    {"io", luaopen_io},
                    {NULL, NULL}
            };
    const luaL_Reg *lib = lualibs;

    for(; lib->func != NULL; lib++)
    {
        luaL_requiref(lua_state, lib->name, lib->func, 1);
        lua_settop(lua_state, 0);
    }

    return  lua_state;
}

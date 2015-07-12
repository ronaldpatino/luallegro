#include <iostream>
#include <allegro.h>
#include "luastuff.h"
#include "funciones.h"


using namespace std;

    BITMAP *tmp;
    BITMAP *imagen = NULL;
    BITMAP *scr;


int main() {
    allegro_init();
    install_keyboard();
    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

    if (!(tmp = create_bitmap(SCREEN_W, SCREEN_H))) exit(1);


    lua_State *lua_state = init_lua();
    lua_register(lua_state, "decir", decir);
    lua_register(lua_state, "fin", fin);
    lua_register(lua_state, "fout", fout);
    lua_register(lua_state, "wait", wait);
    lua_register(lua_state, "cargar_imagen", cargar_imagen);

    int status = luaL_loadfile(lua_state, "/home/ronald/ClionProjects/luallegro/test.lua");
    int result = 0;
    if(status == LUA_OK)
    {
        result = lua_pcall(lua_state, 0, LUA_MULTRET, 0);
    }

    destroy_bitmap(imagen);

    return 0;
}
END_OF_MAIN()
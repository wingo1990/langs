#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

int l_bar(lua_State *L)
{
    const char *str = lua_tostring(L, -1);
    printf("str: %s\n", str);
    int len = 0;
    while(1) {
        char c = str[len];
        if (c == '\0') {
            break;
        }
        len++;
    }
    printf("xxxxx\n");
    lua_pushstring(L, str);
    printf("yyyyyyy\n");
    lua_pushnumber(L, len);
    return 2;
}

int main()
{
    //initialize the state
    lua_State *L = luaL_newstate();
    //load the library
    luaL_openlibs(L);
    
    lua_pushcfunction(L, l_bar);
    lua_setglobal(L, "bar");

    //do file
    luaL_dofile(L, "foo.lua");

    lua_getglobal(L, "foo");
    //foo
    lua_pushstring(L, "Hello baby!");
    //foo str
    lua_pcall(L, 1, 1, 0);
    //table
    
    lua_pushstring(L, "hamburger");
    //table key
    lua_gettable(L, -2);
    //table value
    int result2 = lua_tonumber(L, -1);
    printf("result2 = %d\n", result2);
    
    lua_getglobal(L, "x");
    //table value x 
    int x = lua_tonumber(L, -1);
    printf ("x = %d\n", x);

    lua_close(L);
    
    return 0;
}

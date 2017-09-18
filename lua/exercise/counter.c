#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

static int counter(lua_State *L) 
{
	int val = lua_tonumber(L, lua_upvalueindex(1));
	val++;

	lua_pushnumber(L, val);
	lua_pushvalue(L, -1);

	lua_replace(L, lua_upvalueindex(1));
	return 1;
}

int new_counter(lua_State *L)
{
	lua_pushnumber(L, 1);
	lua_pushcclosure(L, counter, 1);
	return 1;
}

int luaopen_counter(lua_State *L)
{
	luaL_Reg reg[] = {
		{"get_counter", new_counter},
		{NULL, NULL}
	};
	luaL_newlib(L, reg);
	return 1;
}

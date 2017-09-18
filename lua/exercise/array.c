#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

typedef struct _array {
	int size;
	double values[1];
}Array;

static int newarray(lua_State *L) 
{
	int size = luaL_checkinteger(L, -1);
	Array *ar = lua_newuserdata(L, sizeof(Array) + (size - 1) * sizeof(double));
	ar->size = size;
	return 1;
}

static int setarray(lua_State *L)
{
	Array *ar = lua_touserdata(L, 1);
	int index = luaL_checkinteger(L, 2);
	double value = luaL_checknumber(L, 3);

	luaL_argcheck(L, ar != NULL, 1, "`array' expected.");
	luaL_argcheck(L, index > 0 && index <= ar->size, 2, "index out of range.");

	ar->values[index - 1] = value;
	return 0;
}

static int getarray(lua_State *L)
{
	Array *ar = lua_touserdata(L, 1);
	int index = luaL_checkinteger(L, 2);

	luaL_argcheck(L, ar != NULL, 1, "`array' expected.");
	luaL_argcheck(L, index > 0 && index <= ar->size, 2, "index out of range.");

	lua_pushnumber(L, ar->values[index - 1]);
	return 1;
}

luaL_Reg reg[] = {
	{"new", newarray},
	{"get", getarray},
	{"set", setarray},
	{NULL, NULL}
};

int luaopen_array(lua_State *L)
{
	luaL_newlib(L, reg);
	return 1;
}

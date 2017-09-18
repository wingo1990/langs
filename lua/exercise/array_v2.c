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
	
	luaL_getmetatable(L, "zwt.array");
	lua_setmetatable(L, -2);
	
	return 1;
}

static void *checkarray(lua_State *L, int index)
{
	void *udata = luaL_checkudata(L, index, "zwt.array");
	luaL_argcheck(L, udata != NULL, index, "`array' expected.");
	return udata;
}

static int setarray(lua_State *L)
{
	Array *ar = checkarray(L, 1); 
	int index = luaL_checkinteger(L, 2);
	double value = luaL_checknumber(L, 3);

	luaL_argcheck(L, index > 0 && index <= ar->size, 2, "index out of range.");

	ar->values[index - 1] = value;
	return 0;
}

static int getarray(lua_State *L)
{
	Array *ar = checkarray(L, 1);
	int index = luaL_checkinteger(L, 2);

	luaL_argcheck(L, index > 0 && index <= ar->size, 2, "index out of range.");

	lua_pushnumber(L, ar->values[index - 1]);
	return 1;
}

int arraysize(lua_State *L)
{
	Array *ar = checkarray(L, 1);
	int size = ar->size;

	lua_pushinteger(L, size);
	return 1;
}

luaL_Reg reg[] = {
	{"new", newarray},
	{NULL, NULL}
};

luaL_Reg reg2[] = {
	{"get", getarray},
	{"set", setarray},
	{"size", arraysize},
	{NULL, NULL}
};

int luaopen_array(lua_State *L)
{
	luaL_newmetatable(L, "zwt.array");
	
	lua_pushstring(L, "__index");
	lua_pushvalue(L, -2);
	lua_settable(L, -3);

	luaL_setfuncs(L, reg2, 0);
	lua_pop(L, 1);
	
	luaL_newlib(L, reg);
	return 1;
}

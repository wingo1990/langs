#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int load_config(char *filename, int *l, int *w)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	int err = luaL_loadfile(L, filename) || lua_pcall(L, 0, 0, 0);
	if (err) {
		printf("%s\n", lua_tostring(L, -1));
		lua_close(L);
		return -1;
	}

	lua_getglobal(L, "width");
	lua_getglobal(L, "height");
	
	*l = lua_tonumber(L, -1);
	*w = lua_tonumber(L, -2);
	
	lua_close(L);
	return 0;
}

int main()
{
	int h, w;
	int err = load_config("./config.conf", &h, &w);
	if (err) {
		printf("config.conf error.\n");
		return -1;
	}

	printf("height: %d, width: %d\n", h, w);
	return 0;
}

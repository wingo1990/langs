#include <stdio.h>
#include <string.h>

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main()
{
	char buffer[1024] = {0};
	int error;

	lua_State *L = luaL_newstate();
	luaopen_io(L);
	luaopen_table(L);
	luaopen_string(L);
	luaopen_math(L);
	luaopen_base(L);

	while(fgets(buffer, 1024, stdin)) {
		error = luaL_loadbuffer(L, buffer, strlen(buffer), "line")
				|| lua_pcall(L, 0, 0, 0);
		if (error) {
			printf("%s\n", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}
	
	lua_close(L);
	return 0;
}

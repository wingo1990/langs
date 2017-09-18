#!/usr/bin/env lua

local _declare_names = {}
function declare(name, initval)
	rawset(_G, name, initval)
	_declare_names[name] = true
end

setmetatable(_G, {
	__newindex = function(t, n, v)
		if _declare_names[n] then
			rawset(t, n, v)	
		else
			error("Attempt to write undeclared variable "..n, 2)
		end
	end,

	__index = function(t, n, v)
		if _declare_names[n] then
			return nil
		else
			error("Attempt to read undeclared variabe " .. n, 2)
		end
	end
})

--declare("b", 1)
declare("a")
print(b)
a = 1000
print(a)

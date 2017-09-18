#!/usr/bin/env lua

co = coroutine.wrap(function (a, b)
	print("resume args:" .. a .. "," .. b)
	ret = coroutine.yield()
	print("yield return:" .. ret)
end)

print(type(co))
co(1, 2)
co(3)

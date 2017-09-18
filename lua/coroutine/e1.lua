#!/usr/bin/env lua

co = coroutine.create(function (a, b)
	print("resume args:" .. a .. "," .. b)
	ret = coroutine.yield()
	print("yield return:" .. ret)
end)

coroutine.resume(co, 1, 2)
coroutine.resume(co, 3)

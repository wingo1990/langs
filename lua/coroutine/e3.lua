#!/usr/bin/env lua

function status()
	print("co1's status:" .. coroutine.status(co1))
	print("co2's status:" .. coroutine.status(co2))
end

co1 = coroutine.create(function(a)
	print("arg is :" .. a)
	status()
	local stat, re = coroutine.resume(co2, "2")
	print("resume's return is " .. re)
	status()
	local stat2, re2 = coroutine.resume(co2, "4")
	print("resume's return is " .. re2)
	--local arg = coroutine.yield("6")
end)

co2 = coroutine.create(function(a)
	print("arg is :" .. a)
	status()
	local rey = coroutine.yield("3")
	print("yeild's return is " .. rey)
	status()
	coroutine.yield("5")
end)

stat = coroutine.resume(co1, "1")
print(stat)
status()
print("last return is " .. mainre)

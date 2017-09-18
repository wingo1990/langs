#!/usr/bin/env lua

weakTable = {}
weakTable[1] = function() print("i am the first element") end
weakTable[2] = function() print("i am the second element") end
weakTable[3] = {10, 20, 30}

setmetatable(weakTable, {__mode = "v"})

print(#weakTable)

ele = weakTable[1]
collectgarbage()
print(#weakTable)

ele = nil
collectgarbage()
print(#weakTable)

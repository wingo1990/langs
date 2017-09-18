array = require "array"

ar = array.new(10);
print(ar:size())

for i = 1, 10 do
	ar:set(i, i^2)
end

for i = 1, 10 do 
	print(ar:get(i))
end

function treaverse_global_env(curtable,level)
	    for key,value in pairs(curtable or {}) do
			local prefix = string.rep(" ",level*5)
			print(string.format("%s%s(%s)",prefix,key,type(value)))

			--注意死循环
			if (type(value) == "table" ) and key ~= "_G" and (not value.package) then
				treaverse_global_env(value,level + 1)
			elseif (type(value) == "table" ) and (value.package) then
				print(string.format("%sSKIPTABLE:%s",prefix,key))
			end 
	    end 
end

treaverse_global_env(_G,0)

t = getmetatable(ar)
for k, v in pairs(t) do
	print(k, v)
end

array = require "array"

a = array.new(10);
for i = 1, 10 do
	array.set(a, i, i^2)
end

for i = 1, 10 do
	v = array.get(io.stdin, i)
	print(v)
end


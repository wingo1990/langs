#!/usr/bin/env lua

local aux = require("aux")

local Account = {}
function Account:new(o)
	if not o then
		o = {balance = 0}
	end
--	setmetatable(o, self)
--	self.__index = self
	local tmp = {}
	setmetatable(o, tmp)
	tmp.__index = self
	return o
end

function Account:withdraw(v)
	if v > self.balance then
		print("nosufficient funds")
		return
	end
	self.balance = self.balance - v
	print("withdraw money: " .. v)
end

function Account:deposit(v)
	self.balance = self.balance + v
	print("deposit money: " .. v)
end

local ac = Account:new{balance = 100}
aux.print_r(ac)
print("ac balance: " .. ac.balance)
ac:withdraw(1000)
ac:withdraw(50)
print("ac balance: " .. ac.balance)
ac:withdraw(20)
print("ac balance: " .. ac.balance)
ac:deposit(200)
print("ac balance: " .. ac.balance)


local SpecialAccount = Account:new()
function SpecialAccount:withdraw(v)
	if v > self:limit() then
		print("withdraw money limited..")
		return
	end
	self.balance = self.balance - v
	print("withdraw money: " .. v)
	return
end

function SpecialAccount:limit()
	return 0.3 * self.balance
end

local sa = SpecialAccount:new{balance = 100}
print("sa balance: " .. sa.balance)
sa:withdraw(40)
sa:withdraw(10)
print("sa balance: " .. sa.balance)
sa:deposit(20)
print("sa balance: " .. sa.balance)

function sa:limit()
	return 50
end
sa:withdraw(60)
print("sa balance: " .. sa.balance)
sa:withdraw(40)
print("sa balance: " .. sa.balance)

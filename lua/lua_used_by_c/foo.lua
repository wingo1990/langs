foo = function (str)
    local s, len = bar(str);
    print(s);
    local s2, len2 = bar("hamburger")
    local t = {}
    t[s] = len;
    t[s2] = len2;
    return t
end

x = 5

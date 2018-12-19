from copy import deepcopy, copy
class Sequence:
    #Constructor taking an iterable as argument
    def __init__(self, iterable):
        self.elems = deepcopy(list(iterable))
    def __str__(self):
        return str(self.elems)
    def __len__(self):
        return len(self.elems)
    def __eq__(self, other):
        return self.elems == other.elems
    def __getitem__(self, key):
        return self.elems[key]
    def __setitem__(self, key, val):
        self.elems[key] = val
    def __delitem__(self, key):
        del self.elems[key]
    def __iter__(self):
        return iter(self.elems)
    def insert(self, key, value):
        self.elems[key]=value
    def append(self, value):
        self.elems.append(value)
    def __copy__(self):
        return Sequence(deepcopy(self.elems))



s = Sequence(range(10))
print("s:",s)
print("len(s):",len(s))
print("s == Sequence(range(11)):",s == Sequence(range(11)))
print("setting s[0] to 99")
s[0]=99
print("s:",s)
print("deletting s[5]")
del s[5]
print("s:",s)
print("printing s elements on each line")
for x in s:
    print("-",x)
print("inserting 5 at position 4")
s.insert(4,5)
print("inserting 77 at position -1")
s[-1]=77
print("appending 'end'")
s.append('end')
print("s:",s)
print("creating deep copy s2")
s2 = copy(s)
print("s == s2:",s == s2)
print("s is s2:",s is s2)
print("appending 's2end' to s2")
s2.append('s2end')
print("s:",s)
print("s2:",s2)
print("77 in s:", 77 in s)

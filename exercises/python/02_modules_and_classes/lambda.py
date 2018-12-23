def rev_spell_list (l):
    if type(l) is list:
        return sorted(l, key=(lambda x : ''.join(reversed(x))))
    else:
        print(type(l), " is not a valid argument type, required list")
        return None

if __name__ == '__main__':
    a1 = ['abc', 'hello', 'dlrow', 'bye', 'zaa', 'lez']
    print(rev_spell_list(a1))
    a2 = 'hellooo'
    print(rev_spell_list(a2))

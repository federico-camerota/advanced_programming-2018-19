
def is_palindrome(string_var):     
    '''
    returns True if string_var is palindrome, False otherwise
    '''
    ret = None
    if type(string_var) is str:
        return string_var == ''.join(reversed(string_var))
    else:
        print(string_var, "is not a valid argument")
    return ret 

#Test is_palindrome function
print(is_palindrome(6543))
print(is_palindrome('abcdcba'))
print(is_palindrome('anna'))
print(is_palindrome('sdlkjf'))

def histogram_letters(string_var):     
    '''
    count how many times a letter is present in the string_var
    and returns a dict

    '''
    ret = None
    if type(string_var) is str:
        d = {val : string_var.count(val) for val in string_var}
        return d
    else:
        print(string_var, "is not a valid argument")
    return ret 

#Test histogram_letters function
print(histogram_letters(234))
print(histogram_letters('hello, world! how are you?'))

def get_most_frequent(list_var):
    '''
    returns a tuple with the most frequent object in the list with the 
    corresponing number
    '''
    ret = None
    if type(list_var) is list:
        max_item = max(set(list_var), key=list_var.count)
        return (max_item, list_var.count(max_item))
    else:
        print("'",list_var, "'", "is not a valid argument")
    return ret

#Test get_most_frequent function
print(get_most_frequent([1,2,3,4,2,3,2,2,3,4,1,5,2,6,2,6,3,1,1,2]))
print(get_most_frequent([1,2,3,4,5]))
print(get_most_frequent('hello, world'))

def which_duplicates(list_var):
    '''
    return a dict with containing the repeted object and the number of repetitions
    '''
    ret = None
    if type(list_var) is list:
        return {val : list_var.count(val) for val in list_var if list_var.count(val) > 1}
    else:
        print(list_var, "is not a valid argument")
    return ret

#Test which_duplicates function
print(which_duplicates([1,2,3,3,3,4,1,2,4,5,2,3,4,7,8]))

def compute_factorial(int_val):
    '''
    returns factorial of a number
    '''
    ret = None
    if type(int_val) is int:
        prod = 1
        for i in range(int_val+1)[1:]:
            prod *= i
        return prod
    else:
        print(int_val, "is not a valid argument")
    return ret

#Test compute_factorial function
print(compute_factorial(5))

def is_prime(int_val):
    '''
    returns True if int_val is prime, False otherwise
    '''
    ret = None
    if type(int_val) is int:
        if int_val in [2,3]:
            return True
        if int_val == 1:
            return False
        tests = range(2, int_val)
        prime = min([int_val % t for t in tests], default=1)
        if prime == 0:
            return False
        else:
            return True
    else:
        print(int_val, "is not a valid argument")
    return ret

#Test is_prime function
print(is_prime(4))
print(is_prime(13))
print(is_prime(1))
print(is_prime(2))
print(is_prime(53154)) 


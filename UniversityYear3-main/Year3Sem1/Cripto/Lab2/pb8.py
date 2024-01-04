# 8. Algorithm for determining all bases b with respect to which
# a composite odd number n is pseudoprime. Use the repeated
# squaring modular exponentiation method.

#convery into base 2 any number
def base2conv(k):
    binary = []
    while k:
        binary.append(k % 2)
        k //= 2
    return binary

#
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)



# input b, k, n
# output b^k % n
#b=base, k to power , n number 
def repeated_squaring_modular_exponentiation(b, k, n):
    binary_k = base2conv(k)
    a = 1
    if k == 0:  # if k is 0, then we have a number raised at the power 0, which is always 1
        return a
    c = b
    if binary_k[0] == 1: #  pt ca ii la puterea 0 asa ca avem b 
        a = b
    for ki in binary_k[1:]:
        c = (c * c) % n
        if ki == 1:
            a = (c * a) % n
    return a


# Fermat Test
# An odd number n is pseudoprime to the base b
# if we have:
# gcd(b, n) = 1
# b ^ (n - 1) = 1 (mod n)
def is_pseudoprime(n, b):
    if repeated_squaring_modular_exponentiation(b, n - 1, n) == 1:
        return True
    return False


if __name__ == "__main__":
    n = int(input("n = "))
    baseList = []
    for b in range(1, n):
        if is_pseudoprime(n, b):
            baseList.append(b)
    print(n, "is pseudoprime to bases", baseList)
    print("There are ", len(baseList))






# A number is PseudoPrime to a base if it passes the ferma test :
# gcd(b,n) = 1
#(b^(n-1)) %n = 1 


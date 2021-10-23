import math
import sympy


def encrypt(M, K):
    res = ''
    CTList = []
    for i in M:
        CTList.append(i**K[0] % K[1])
        res += chr(((i**K[0] % K[1]) % 26) + 64)
    return res, CTList


def decrypt(C, K):
    res = ''
    for i in C:
        res += chr(((i**K[0] % K[1]) % 26) + 64)
    return res


p = int(input("Enter Value Of p :: "))
q = int(input("Enter Value of q :: "))
n = p * q
f = (p-1) * (q-1)

primes = [i for i in range(1, f) if sympy.isprime(i)]

for i in primes:
    if math.gcd(f, i) == 1:
        e = i
        break
    else:
        continue

i = 1

while (i*e) % f != 1:
    i += 1
d = i

pu = [e, n]
pr = [d, n]

print("\np =", p)
print("q =", q)
print(f"\nn = p * q = {p} * {q} = {n}")
print(f"f = (p-1) * (q-1) = {p-1} * {q-1} = {f}")
print(f"\nFind e Such That GCD({f},e) = 1")
print(f"GCD({f},{e}) = 1")
print("Hence e =", e)
print(f"\nFind d Such That d * {e} % {f} = 1")
print(f"{d} * {e} % {f} = 1")
print("Hence d =", d)
print("\nHence")
print(f"PU = [e,n] = {pu}")
print(f"PR = [d,n] = {pr}")

msg = input("\nEnter Message :: ").upper()
numList = []
temp = list(msg)
for i in temp:
    numList.append((ord(i)-65)+1)

encMsg, CNumList = encrypt(numList, pu)
print("\n==========")
print("Encryption")
print("==========")
print("Message :", msg)
print("Encrypted Message :", encMsg)

print("\n==========")
print("Decryption")
print("==========")
print("Message :", encMsg)
print("Decrypted Message :", decrypt(CNumList, pr))

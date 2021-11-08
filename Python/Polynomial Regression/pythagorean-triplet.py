"""
What is Pythagorean Triplet?

A Pythagorean triple consists of three positive integers a, b, and c,
such that a² + b² = c². Such a triple is commonly written, and a well-known example is.
If is a Pythagorean triple, then so is for any positive integer k.
A primitive Pythagorean triple is one in which a, b and c are coprime. 
"""

n = 24
print("checking...")
for k in range(1,n):
    for i in range(1,n):
        for j in range(1,n):
            if i+j+k == n:
                if (i**2)+(j**2)==(k**2):
                    print(str(i)+'^2 + ',str(j)+'^2 = ',str(k)+'^2')
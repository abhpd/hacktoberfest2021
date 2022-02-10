# Monte Carlo methods, or Monte Carlo experiments, are a broad class of computational algorithms
# that rely on repeated random sampling to obtain numerical results. The underlying concept is to
# use randomness to solve problems that might be deterministic in principle.

# Estimating value of pi

import random

n = int(input("Enter value of n:"))
no_of_point_circle = 0
total_no_of_point = 0
    
for _ in range(n):
    x = random.uniform(0,1)
    y = random.uniform(0,1)
    distance = x**2 + y**2
    if distance <= 1:
        no_of_point_circle += 1
    total_no_of_point += 1    

pi = 4 * no_of_point_circle/total_no_of_point
print(pi)






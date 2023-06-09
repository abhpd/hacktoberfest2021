print("gauss eliminations")
order = int(input("input a order of matrix: "))
matriz = []

for x in range(order):
    matriz.append([])

print('''enter only the coefficients of the variable
and then the value after equality
''')
for i in range(order):
    for j in range(order + 1):
        matriz[i].append(int(input()))


print("")
for i in range(order):
    for j in range(order):
        if j > 0 and matriz[i][j] > 0:
            print("+{}x{}".format(matriz[i][j], j + 1), end=' ')
        else:
            print("{}x{}".format(matriz[i][j], j + 1), end=' ')

    print("= {}".format(matriz[i][order]))

for i in range(order-1):
    j = i

    if matriz[i][j] == 0:
        comut = matriz[i]
        matriz[i] = matriz[i+1]
        matriz[i+1] = comut

i = 0
j = 0

while i < order - 1:
    i2 = i

    while i2 < order -1:
        multi = matriz[i2+1][j] / matriz[i][j]
        j2 = 0

        while j2 <= order:
            matriz[i2+1][j2] = matriz[i2+1][j2] - (matriz[i][j2] * multi)
            j2 += 1

        i2 += 1

    i += 1
    j += 1

print('''
scaled matrix''')
for i in range(order):
    for j in range(order):
        if matriz[i][j] == 1:
            if j == i:
                print("x{}".format(j+1), end=' ')
            else:
                print("+x{}".format(j+1), end=' ')
        elif matriz[i][j] == -1:
            print("-x{}".format(j+1), end=' ')
        elif matriz[i][j] == 0:
            print("   ", end=' ')
        elif j > 0 and matriz[i][j] > 2:
            print("+{:.0f}x{}".format(matriz[i][j], j + 1), end=' ')
        else:
            print("{:.0f}x{}".format(matriz[i][j], j + 1), end=' ')

    print("= {:.0f}".format(matriz[i][order]))

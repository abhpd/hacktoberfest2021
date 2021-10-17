# Resolver o sistema da matriz triangular inferior
def triangular_inferior(A, b):
    
    n = len(A)
    x = n * [0]

    for i in range(0, n):
        S = 0
        for j in range(0, i):
            S = S + A[i][j] * x[j]
        x[i] = (b[i]-S)/A[i][i]
    return x

# Resolver o sistema da matriz triangular superior
def triangular_superior(A, b):

    n = len(A)
    x = n * [0] 
    
    for i in range(n-1, -1, -1):
            S = 0
            for j in range(i+1, n):
                S = S + A[i][j] * x[j]
            x[i] = (b[i] - S)/A[i][i]
    
    return x

# Criar uma matriz idenditade de tamanho n
def identidade(n):
    m = []
    for i in range(0, n):
        linha = [0] * n
        linha[i] = 1
        m.append(linha)
    return m

# Fatorar a Matriz A nas matrizes L e U
def lu(A):
    
    n = len(A)
    L = identidade(n)
    
    for k in range(0, n-1):
        for i in range(k+1, n):
            m = - A[i][k]/A[k][k]
            L[i][k] = -m
            for j in range(k+1, n):
                    A[i][j] = m * A[k][j]+ A[i][j]
            A[i][k] = 0

    return (L, A)


def finish(L,U,b):
 
    y = triangular_inferior(L, b)
    x = triangular_superior(U, y)
    
    return x

# Imprimir matriz 
def formata_matriz(M):
    m = len(M) 
    n = len(M[0]) 
    s = ""
    for i in range(m):
        for j in range(n):
           s += "%9.3f " % M[i][j]
        s += "\n"
    return s

A = [[1, -3, 2],
     [-2, 8, -1],
     [4, -6, 5]]
b = [11, -15, 29]

(L, U) = lu(A)
print("L: \n%s" % formata_matriz(L))
print("U: \n%s" % formata_matriz(U))

x = finish(L, U, b)
print(x)


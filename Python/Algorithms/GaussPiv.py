import math

def gaussPivoteamento(A,b):
    #acessar as linhas
    for i in range(len(A)):
        #verificar qual e o maior pivo
        pivo = math.fabs(A[i][i])
        linhaPivo = i
        for j in range(i+1, len(A)):
            if math.fabs( A[j][i] > pivo ):
                pivo = math.fabs( A[j][i])
                linhaPivo = j
        #permutar as linhas
        if linhaPivo != i:
            linhaAuxiliar = A[i]
            A[i] = A[linhaPivo]
            A[linhaPivo] = linhaAuxiliar

            bAuxiliar = b[i]
            b[i] = b[linhaPivo]
            b[linhaPivo] = bAuxiliar
        # eliminacao gaussiana
        for m in range( i+1, len(A) ):
            multiplicador = A[m][i]/A[i][i]
            for n in range( i, len(A) ):
                A[m][n] -= multiplicador*A[i][n]
            b[m] -= multiplicador*b[i]
    # printar matriz A escalonada e o vetor b escalonado
    for k in range( len(A) ):
        print( A[k] )
    print()
    print(b)

c = [[1,2,-1],[2,-1,1],[1,1,1]]
d = [2,3,6]

gaussPivoteamento(c,d)
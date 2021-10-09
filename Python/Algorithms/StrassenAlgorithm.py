def setZero(sizeM):
    a=[]
    for i in range(sizeM):
        tmp = []
        for j in range(sizeM):
            tmp.append(0)
        a.append(tmp)
    return a

def inputMatriks(sizeM):
    a=[]
    for i in range(sizeM):
        tmp = []
        for j in range(sizeM):
            x = int(input("[%i][%i] :" %(i,j)))
            tmp.append(x)
        a.append(tmp)
    return a

def add(a,b):
    if type(a) == int:
        d = a+b
    else:
        d = []
        for i in range(len(a)):
            tmp = []
            for j in range(len(a[0])):
                tmp.append(a[i][j]+b[i][j])
            d.append(tmp)
    return d

def sub(a,b):
    if type(a) == int:
        d = a-b
    else:
        d = []
        for i in range(len(a)):
            tmp = []
            for j in range(len(a[0])):
                tmp.append(a[i][j]-b[i][j])
            d.append(tmp)
    return d

def split(mtr):
    a=mtr
    b=mtr
    c=mtr
    d=mtr
    while(len(a)>len(mtr)/2):
        a=a[:len(a)//2]
        b=b[:len(b)//2]
        c=c[len(c)//2:]
        d=d[len(d)//2:]
    while(len(a[0])>len(mtr[0])/2):
        for i in range(len(a[0])//2):
            a[i]=a[i][:len(a[i])//2]
            b[i]=b[i][len(b[i])//2:]
            c[i]=c[i][:len(c[i])//2]
            d[i]=d[i][len(d[i])//2:]
    return a,b,c,d

def strassen(a, b, size):
    if size == 1:
        m=[[0]]
        m[0][0] = a[0][0] * b[0][0]
        return m
    else:
        a11, a12, a21, a22 = split(a)
        b11, b12, b21, b22 = split(b)
        
        p1 = strassen(a11,sub(b12,b22),size/2)
        p2 = strassen(add(a11,a12),b22,size/2)
        p3 = strassen(add(a21,a22),b11,size/2)
        p4 = strassen(a22,sub(b21,b11),size/2)
        p5 = strassen(add(a11,a22),add(b11,b22),size/2)
        p6 = strassen(sub(a12,a22),add(b21,b22),size/2)
        p7 = strassen(sub(a11,a21),add(b11,b12),size/2)
        
        c11 = add(sub(add(p5,p4),p2),p6)
        c12 = add(p1,p2)
        c21 = add(p3,p4)
        c22 = sub(sub(add(p1,p5),p3),p7)
        
        C=setZero(len(c11)*2)
        for i in range(len(c11)):
            for j in range(len(c11)):
                C[i][j] = c11[i][j]
                C[i][j+len(c11)] = c12[i][j]
                C[i+len(c11)][j] = c21[i][j]
                C[i+len(c11)][j+len(c11)] = c22[i][j]
        return C

size = int(input("Masukkan ukuran matriks nxn : "))

print("Masukkan elemen matriks A :")
A=inputMatriks(size)

print("Masukkan elemen matriks B :")     
B=inputMatriks(size)

C = strassen(A,B,size)
print("="*30+"\n"+
      "Matriks C : ")
for i in range(len(C)):
    print(C[i])
    
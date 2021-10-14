# Python program for Bubble Sort

number = int(input("Please Enter the Total Number of Elements : ")) # number yang perlu idiisi
a = [int(input("Please enter the %d Element of List1 : " %i)) for i in range(number)]
# masukkan data sesuai elemen list1

i = 0 # lakukan perulangan while
while(i < number -1):
    j = 0
    while(j < number - i - 1):
        if(a[j] > a[j + 1]):
             temp = a[j]
             a[j] = a[j + 1]
             a[j + 1] = temp
        j = j + 1
    i = i + 1

print("The Sorted List in Ascending Order : ", a)

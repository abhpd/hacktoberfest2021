a=list(map(int,input().split()))
z=max(a)
l=[0 for i in range(z+1)]
for i in range(len(a)):
	l[a[i]]=l[i]+1
k=[]
for i in range(len(l)):
	if(l[i]>0):
		for j in range(l[i]):
			k.append(i)
print(k)

# Complexity : O(n+max(l))

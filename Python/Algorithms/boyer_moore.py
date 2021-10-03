def pattern_array(pattern):
    d=dict()
    m=len(pattern)
    for i in range(m-1):
        d[pattern[i]]=m-i-1
    d[pattern[-1]]=1
    d['*']=m
    return d

pattern ='AABA'
d=pattern_array(pattern)
print(d)

def boyer_moore(text,pattern,d):
    n=len(text)
    m=len(pattern)
    if m==0:
        return 'pattern found'
    if m>n:
        return 'pattern not found'

    i=0
    j=m-1
    ans=[]
    while i<n and j<n:
        print(str(i)+"   "+str(j))
        while j>=i and text[j]==pattern[j-i]:
            j-=1
        if j==i-1:
            ans.append(i) 
            i+=1
            j=i+m-1
            continue
        if text[j] in d:
            i+=d[text[j]]
            j=i-1+m
        else:
            i+=d['*']-1
            j=i+m-1
    return ans


pattern ='AABA'
text="AABAACAADAABAABA"
d=pattern_array(pattern)
print(d)
print(boyer_moore(text,pattern,d))


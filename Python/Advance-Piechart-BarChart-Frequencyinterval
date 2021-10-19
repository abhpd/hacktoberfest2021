Trafic_Incident_Data=[748,829,700,584,814,750,835,906,961,1020,855,830,18,22,12,8,6,11,9,19,21,26,14,16,354,339,
317,259,336,334,378,407,431,445,406,349,90,104,75,43,50,68,57,54,92,96,81,71,257,327,268,242,369,301,355,390,375,
397,314,351,29,37,28,32,53,36,36,36,42,56,40,43,935,945,881,924,880,848,972,431,379,311,324,297,342,315,357,401,
496,409,201,256,216,244,226,259,238,444,382,374]

Trafic_Incident_Data.sort()
print("Sorted list : ",Trafic_Incident_Data)

N=len(Trafic_Incident_Data)
l=log(N,(10))
#Number of classes is denoted by k
k=1+3.22*l
print("Number of Classes in this data = ",k)

#width of class is denoted by h
h=(max(Trafic_Incident_Data)-min(Trafic_Incident_Data))/7
print("Width of class = ",h)

# we take width of class = 145
print("Minimum Value in this list is = ",min(Trafic_Incident_Data))
print("Maximum Value in this list is = ",max(Trafic_Incident_Data))

print("Classes in this data are = ")
m=min(Trafic_Incident_Data)
for c in range(0,7):
    d=m+144
    print(m,"--",d)
    m=d+1

count1 = 0
for a in Trafic_Incident_Data:
    if a>=6 and a<=150:
        count1=count1+1
print("Values in range 6--150 are = ", count1)
count2 = 0
for a in Trafic_Incident_Data:
    if a>=151 and a<=295:
        count2=count2+1
print("Values in range 151--295 are = ", count2)
count3 = 0
for a in Trafic_Incident_Data:
    if a>=296 and a<=440:
        count3=count3+1
print("Values in range 296--440 are = ", count3)
count4 = 0
for a in Trafic_Incident_Data:
    if a>=441 and a<=585:
        count4=count4+1
print("Values in range 441--585 are = ", count4)
count5 = 0
for a in Trafic_Incident_Data:
    if a>=586 and a<=730:
        count5=count5+1
print("Values in range 586--730 are = ",count5)
count6 = 0
for a in Trafic_Incident_Data:
    if a>=731 and a<=875:
        count6=count6+1
print("Values in range 731--875 are = ",count6)
count7 = 0
for a in Trafic_Incident_Data:
    if a>=876 and a<=1020:
        count7=count7+1

print("\nValues in range 876--1020 are = ",count7)
cf1=count1
print("Commulative Frequency of class 1 is = ",cf1)
cf2=count1+count2
print("Commulative Frequency of class 2 is = ",cf2)
cf3=count2+count3
print("Commulative Frequency of class 3 is = ",cf3)
cf4=count3+count4
print("Commulative Frequency of class 4 is = ",cf4)
cf5=count4+count5
print("Commulative Frequency of class 5 is = ",cf5)
cf6=count5+count6
print("Commulative Frequency of class 6 is = ",cf6)
cf7=count6+count7
print("Commulative Frequency of class 7 is = ",cf7)

r_f1=count1/N
print("\nRelativive frequency of Class 1 = ",r_f1)
r_f2=count2/N
print("Relativive frequency of Class 2 = ",r_f2)
r_f3=count3/N
print("Relativive frequency of Class 3 = ",r_f3)
r_f4=count4/N
print("Relativive frequency of Class 4 = ",r_f4)
r_f5=count5/N
print("Relativive frequency of Class 5 = ",r_f5)
r_f6=count6/N
print("Relativive frequency of Class 6 = ",r_f6)
r_f7=count7/N
print("Relativive frequency of Class 7 = ",r_f7)
t1=r_f1+r_f2+r_f3+r_f4+r_f5+r_f6+r_f7
print("Total Relative Frequency = ",t1)

p_f1=r_f1*100
print("\nPercentage Frequency of Class 1 = ",p_f1)
p_f2=r_f2*100
print("Percentage Frequency of Class 1 = ",p_f2)
p_f3=r_f3*100
print("Percentage Frequency of Class 1 = ",p_f3)
p_f4=r_f4*100
print("Percentage Frequency of Class 1 = ",p_f4)
p_f5=r_f5*100
print("Percentage Frequency of Class 1 = ",p_f5)
p_f6=r_f6*100
print("Percentage Frequency of Class 1 = ",p_f6)
p_f7=r_f7*100
print("Percentage Frequency of Class 1 = ",p_f7)
t2=p_f1+p_f2+p_f3+p_f4+p_f5+p_f6+p_f7
print("Total Percentage Frequency = ",t2)
classes_list = [5.5,150.5,295.5,440.5,585.5,730.5,875.5,1020.5]
sns.set()
plt.hist(Trafic_Incident_Data, bins = classes_list )
plt.xlabel("CB")
plt.ylabel("Frequency")
plt.legend(["Traffic_data","Frequency"])
plt.title("HISTORAM")
plt.show()



p = np.array([5.5,150.5,295.5,440.5,585.5,730.5,875.5,1020.5])
q = np.array([36,11,31,4,1,8,9,0])
X_Y_Spline = make_interp_spline(p , q)
X_ = np.linspace(p.min(), p.max(), 500)
Y_ = X_Y_Spline(X_)
plt.xlabel("CB")
plt.ylabel("Frequency")
plt.legend(["Traffic_data","Frequency"])
plt.title("FREQUENCY CURVE")
plt.plot(X_,Y_)
plt.show()


intervals = [0,5.5,150.5,295.5,440.5,585.5,730.5,875.5,1020.5,1020.5]
plt.xticks(intervals)
frequency,edges,_ = plt.hist(Trafic_Incident_Data , histtype='step' , bins=intervals)
midpoints = 0.5*(edges[1:]+edges[:-1])
plt.plot(midpoints , frequency , 'go--' )
plt.title("FREQUENCY POLYGON")
plt.xlabel("CB")
plt.ylabel("FD")
plt.show()


mylables = ["Class_1","Class_2","Class_3","Class_4","Class_5","Class_6","Class_7"]
plt.pie(frequency )
plt.legend(mylables )
plt.title("PIE CHART")
plt.show()

Provinces = ["ICT", "PUNJAB","SINDH","KPK","BALOCHISTAN","G_B","AJK"]
Accidents =[182,4355,881,3946,468, 8127 , 3722]
sns.barplot(x=Provinces, y=Accidents )
plt.title("ACCIDENTS STATS OF PAKISTAN IN 2020")
plt.show()


plt.pie(Accidents)
plt.legend(Provinces)
plt.title("ACCIDENTS STATS OF PAKISTAN IN 2020")
plt.show()

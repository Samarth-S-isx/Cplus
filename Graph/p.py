test=int(input(""))
ans=[]
for i in range(test):
    n=int(input(""))
    cord=[]
    for j in range(n):
        t=[int(x) for x in input("").split()]
        cord.append(t)
    q=int(input(""))
    well=[]
    for j in range(q):
        t1 = [int(x) for x in input("").split()]
        well.append(t1)
    ans1=0
    for j in range(len(well)):
        for k in range(len(cord)):
            ans1+=((well[j][0]-cord[k][0])**2+(well[j][1]-cord[k][1])**2)%1000000007
    ans.append(ans1%1000000007)
for j in range(len(ans)):
    string = "Case #" + str(j + 1) + ": "+str(ans[j])
    print(string)
# prints dotty o/p for dominators for given cfg in a.txt 
from itertools import islice
f = open("a.txt","r")
node = f.readline()
node =int(node)
node =node+1
a = [[0 for x in range(node)] for x in range(node)] 
for l in f:
	r=l.split()
	a[int(r[0])][int(r[1])]=1
doms = [set() for _ in xrange(node)]
D = [set() for _ in xrange(node)]

for i in range(node):
	for j in range(i):
		doms[i].add(j)
for i in range(node):
	if(i!=0):
		tmp1=set()
		l=[]
		for j in range(node):
			if(a[j][i]==1):
				l.append(j)
	
		
		T = []
		for k in l:
			T.append(doms[k])
		p = set()
		if(len(T)>0):
			p = set.intersection(*T)
		doms[i] = set()
		doms[i].add(i)
		doms[i] =set.union(p,doms[i])
print "digraph struct{"	
pre = "start"
DD = set()
for j in range(node):
	for i in sorted(doms[j]):
		if(i in DD):
			pre = i
			DD.add(i)
		else:
			print pre,"->",i,";"
			DD.add(i);
			pre=i
print "}"


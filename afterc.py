f = open("cout.txt","r")
DD = set()
print "digraph struct{"	
pre = "start"
for i in f:
	i.split()
	p= int(i)
	if p in DD:
		pre = p
		DD.add(p)
	else:
			print pre,"->",p,";"
			DD.add(p);
			pre=p
print "}"

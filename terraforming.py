a=open(0).read().split();t=-30;o=c=0
for b,v in zip(a[1::2],map(int,a[2::2])):t+=v*(b[0]=='t');o+=v*(b[1]=='x');c+=v*(b[1]=='c')
print(('not ','')[c>8and o>13and t>7]+'liveable')
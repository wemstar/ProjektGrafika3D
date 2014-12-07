
from random import *

x=128;
y=128;




def generateMap():
	fp=open("test.csv","w");
	for i in range(x):
		for j in range(y):
			if(random()<0.25):
				fp.write("{0};{1};{2};{3}\n".format(float(i),float(j),random()*5.0+1.0,random()*10.0))
generateMap()
	
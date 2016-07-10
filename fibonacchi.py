# your code goes here
n= input()
a=0;
b=1;
if(n==1):
	print 0
elif(n==2):
	print 0;
	print 1
else:
	print 0;
	print 1;
	for i in range(0,n-2):
		sum =a+b;
		a=b;
		b=sum;
		print sum


#Check whether the entered number is odd or even. 
#Rayyan Shaikh
#!/bin/bash

echo "enter a number:"
read n

if [ `expr $n % 2` -eq 0 ]
 then
	echo "number $n is even"
else
	echo "number $n is odd"
fi

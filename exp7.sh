#To reverse a number.
#Rayyan Shaikh
#!/bin/bash

echo "Enter a number: "
read n
rv=0

while [ $n -gt 0 ]
 do
 	temp=`expr $rv \* 10`
	rv=`expr $temp + $n % 10`
	n=`expr $n / 10`
done

echo "Reverse of entered number: " $rv
	

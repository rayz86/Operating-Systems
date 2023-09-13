#To print all the prime numbers less than 20.
#Rayyan Shaikh
#!/bin/bash

for ((i=2;i<=20;i++))
do
	f=0
	for((j=2;j<=i/2;j++))
	do
		if [ `expr $i % $j` -eq 0 ]
		then
			f=1
		fi
	done
	if [ $f -eq 0 ]
	then
		echo $i" is a prime no"
	fi
done

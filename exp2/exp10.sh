#Check Whether given year is leap year or not. 
#Rayyan Shaikh
#!/bin/bash

echo "enter a year:"
read yr

if [ `expr $yr % 400` -eq 0 ]
then 
	echo "leap year"
elif [ `expr $yr % 4` -eq 0 ]
then
	echo "leap year"
else
	echo "not a leap year"
fi

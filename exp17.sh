#Write a shell script to prompt user to enter 2 numbers and perform #various arithmetic  operations using switch statement.
#Rayyan Shaikh
#!/bin/bash

echo "CALCULATOR "
echo "Enter the First Number : "
read a
echo "Enter the Second Number : "
read b

echo "1]ADDITION : +"
echo "2]SUBTRACTION : -"
echo "3]MULTIPLICATION : *"
echo "4]DIVISION : /"
echo "Enter  Your Choice : "
read n
case $n in
	1) echo $a+$b=`expr $a + $b `;;
	2) echo $a-$b=`expr $a - $b `;;
	3) echo $a*$b=`expr $a \* $b `;;
	4) echo $a/$b=`expr $a / $b `;;
	*) echo "ERROR" ;;
esac


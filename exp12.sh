#To check if the entered string is palindrome or not.
#Rayyan Shaikh
#!/bin/bash

echo "Enter the string : "
read n
len=${#n}
for ((i=$len-1;i>=0;i--))
do
    reverse="$reverse${n:$i:1}"
done
if [ $n == $reverse ]
then
	echo $reverse "is a pallindrome string"
else
	echo $n "is not a pallindrome string"
fi

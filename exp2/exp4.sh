#To print the number table.
#Rayyan Shaikh
#!/bin/bash

echo "enter a number:"
read n

num=0
for((i=0;i<=10;i++))
 do
	num=`expr $n \* $i`
	echo "$n x $i = $num"
done

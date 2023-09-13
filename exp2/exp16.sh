#Generate the series: 1, 3, 2, 4, 3, 5, 4, 6, ..... 
#Rayyan Shaikh
#!/bin/bash

echo "Enter the no.  of terms to display:"
read a
n=1
echo -n "SERIES : "
for((i=1;i<=a;i++))
do 
	echo -n "$n,"
	if [ `expr $i % 2` -ne 0  ]
	then
		n=`expr $n + 2`
		 
	else 
		n=`expr $n - 1` 
	fi
done 
echo ""

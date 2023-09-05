#Write shell script to generate following series: 20, 22, 18, 20, 16, 18, 14, 16.
#Rayyan Shaikh
#!/bin/bash
 
n=20
echo -n "SERIES : $n"
for((i=1;i<8;i++))
do 
	if [ `expr $i % 2` -ne 0  ]
	then
		n=`expr $n + 2`
		echo -n ",$n" 
	else 
		n=`expr $n - 4`
		echo -n ",$n"	
	fi
done 
echo ""


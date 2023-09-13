#To display square of first 20 numbers.
#Rayyan Shaikh
#!/bin/bash

for((i=0;i<=20;i++))
{
	num=`expr $i \* $i`
	echo "$i x $i= $num"
}

#To reverse a string. 
#Rayyan Shaikh
#!/bin/bash

echo "Enter the string : "
read n
len=${#n}
for ((i=$len-1;i>=0;i--))
do
    reverse="$reverse${n:$i:1}"
done
echo $reverse

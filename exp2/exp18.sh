#!/bin/bash
#Rayyan Shaikh
#To sort given numbers in descending order.

echo "Enter the size of array :"
read n

echo "Enter the array elements :"
for (( i=0; i<$n; i++ ))
    do
     read nos[$i]
done

echo "Numbers in an array are:"
for (( i = 0; i < $n; i++ ))
    do
     echo -n " "${nos[$i]}
done

for (( i=0; i<$n ; i++ ))
    do
     for (( j=$i; j<$n; j++ ))
      do
      if [ ${nos[$i]} -lt ${nos[$j]} ]
       then
        t=${nos[$i]}
        nos[$i]=${nos[$j]}
        nos[$j]=$t
     fi
    done
done

echo -e "\nSorted Numbers "
for (( i=0; i<$n; i++ ))
    do
     echo -n " "${nos[$i]}
done

echo ""

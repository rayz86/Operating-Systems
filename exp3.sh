#fibonacci of a number
#rayyan shaikh
#!/bin/bash
echo "enter a number:"
read n
next=0
first=0
second=1

echo "Fibonacci Series: "
for((i=1;i<=n;i++))
 do
	echo "$first"
	next=$((first + second))
	first=$second
	second=$next
done

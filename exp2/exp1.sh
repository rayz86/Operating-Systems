#greeting msg according to time
#Rayyan Shaikh
#!/bin/bash
d=`date +"%H"`
echo $d

if [ $d -gt 00 -o $d -lt 12 ]
 then
	echo "Good Morning"
elif [ $d -gt 12 -o $d -lt 16 ]
 then
	echo "Good Afternoon"
elif [ $d -gt 16 -o $d -lt 19 ]
 then
	echo "Good Evening"
elif [ $d -gt 19 -o $d -lt 00 ]
 then
	echo "Good Night"
fi


#Using switch case print the capitals given the state name.
#Rayyan Shaikh
#!/bin/bash

echo "enter a state:"
echo "Goa, Maharashtra, Gujrat, Kelara, Karnataka"
read str
case $str in
	Goa) echo "Panaji";;
	Maharashtra) echo "Mumbai";;
	Gujrat) echo "Gandhinagar";;
	Kelara) echo "Thiruvananthapuram";;
	Karnataka) echo "Bengaluru";;
	*) echo "error";;
esac

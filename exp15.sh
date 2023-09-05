#!/bin/bash
#Rayyan Shaikh
#Append content to a file provided file name exists and it has write permission.
echo "Enter the File name : "
read filename

if [ -f  "$filename" ]
then
if [ -w  "$filename" ]
then
 echo "Enter the text (Press ctrl+z to exist):"]
 cat "$filename"
 cat >> "$filename"
else
   echo "No Write permission for  $filename "
 echo ""
fi
else
  echo "No $filename Exists"
  echo ""
fi


#!/bin/sh

echo "Enter the name of the file to be copied"
read file

cp "$file" "duplicate_$file"
echo "File duplicated"


#!bin/bash

touch ex2.txt
if [ -z "$(grep -Eo '^[0-9]+$' ex2.txt | tail -1)" ]
then
	echo "0" >> ex2.txt
fi

for i in {1..1000}
do
	num=$(($(grep -Eo '^[0-9]+$' ex2.txt | tail -1)+1))
	echo "$num" >> ex2.txt
done

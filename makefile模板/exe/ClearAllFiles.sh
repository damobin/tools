#!/bin/sh
echo "rm All files yes or no?"
read Args
if [ "$Args" = "yes"  ]; then 
	echo "delete working"
	for file in $(ls .)
	do
		if [ -d $file"/" ]
		then
			echo $file
			cd $file
			rm *
			ls .
			cd ..
		fi
	done
else 
	echo "cancle delete"	
fi

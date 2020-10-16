!/bin/sh
#function ArgsJudge()
#{
#	echo "Enter Fun"
#	if [ $# -ge 2 ]
#		then
#			j=0
#			for i in $*
#			do
#				value="$value $i"
#			done
#			echo "Value is $value"
#			cd ./target
#			./AES.exe $*
#			cd ..
#				
#		else
#			cd ./target
#			./AES.exe
#			cd ..
#	fi	
#}
make clean
make
if [ $? -ne 0 ]
	then
		echo "make error"
	else
		echo "success!"
		if [ $# -ge 1 ]
			then		
				cd ./target
				du -h *
				./* $*
				cd ..
			else
				cd ./target				
				du -h *				
				./*
				cd ..
		fi
fi 

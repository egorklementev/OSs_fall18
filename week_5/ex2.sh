write_file () 
{
	ln ex2.txt ex2.lock
	n=$(tail -1 ex2.txt)
	for i in 1 2 3 4 5 6 7 8 9 10
	do
		n=$(tail -1 ex2.txt)
		res=$((n+1))
		echo $res >> ex2.txt
		sleep 1
	done
	rm ex2.lock
}

if [ ! -f ./ex2.lock ]; then
	write_file
else
	while [ -f ./ex2.lock ] 
	do
		sleep 1	
	done
	write_file	
fi

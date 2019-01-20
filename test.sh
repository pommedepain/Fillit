cp fillit grids/nok
cd grids/nok
for i in $(ls -v)
	do	
		#echo $i;
		./fillit $i;
		#valgrind --leak-check=full ./fillit $i;
	done

expresion:fonction_Fonayen.c fonction_Fonayen.h main_Fonayen.c
	gcc -o expresion fonction_Fonayen.c main_Fonayen.c -g -O0 -lm -lpthread -fopenmp 
run_expresion:expresion
	./expresion 
run_valgrind:expresion
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./expresion
clean:
	rm  expresion

profile:
	gcc -Wall -pg fonction_Fonayen.c main_Fonayen.c -lm -lpthread -o expresion
	


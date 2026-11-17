snake:fonction_Fonayen.c fonction_Fonayen.h main_Fonayen.c
	gcc -o snake fonction_Fonayen.c main_Fonayen.c -g -O0 -lm -lpthread -fopenmp -lncurses 
run_snake:snake
	./snake 
run_valgrind:snake
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./snake
clean:
	rm  snake

profile:
	gcc -Wall -pg fonction_Fonayen.c main_Fonayen.c -lm -lpthread -o snake
	


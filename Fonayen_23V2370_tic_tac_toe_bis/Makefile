tictato:fonction_Fonayen.c fonction_Fonayen.h main_Fonayen.c
	gcc -o tictato fonction_Fonayen.c main_Fonayen.c -g -O0 -lm -lpthread -fopenmp 

run_tictato:tictato
	./tictato 
run_valgrind:tictato
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./tictato
clean:
	rm  tictato

profile:
	gcc -Wall -pg fonction_Fonayen.c main_Fonayen.c -lm -lpthread -o tictato

ludo:fonction_Fonayen.c fonction_Fonayen.h main_Fonayen.c
	gcc -o ludo fonction_Fonayen.c main_Fonayen.c -g -O0 -lm -lpthread -fopenmp 
run_ludo:ludo
	./ludo 
run_valgrind:ludo
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./ludo
clean:
	rm  ludo

profile:
	gcc -Wall -pg fonction_Fonayen.c main_Fonayen.c -lm -lpthread -o ludo
	


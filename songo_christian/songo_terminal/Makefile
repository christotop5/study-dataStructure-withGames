songo: main_Fonayen.c fonction_Fonayen.c fonction_Fonayen.h
	gcc -o songo main_Fonayen.c fonction_Fonayen.c
run: songo
	./songo
run_valgrind:songo
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./songo

clean:
	rm -f songo

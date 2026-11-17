songo:fonction_Fonayen.c fonction_Fonayen.h main_Fonayen.c
	gcc -o songo fonction_Fonayen.c main_Fonayen.c -g -O0 -lm -lpthread -fopenmp -lSDL2 -lSDL2_image -lSDL2_gfx -lSDL2_ttf

run_songo:songo
	./songo 
run_valgrind:songo
	valgrind  --tool=memcheck --leak-check=yes --leak-resolution=low --show-reachable=yes  ./songo
clean:
	rm  songo

download_Essentials:
	sudo apt-get update
	sudo apt-get install -y libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-gfx-dev build-essential

profile:
	gcc -Wall -pg fonction_Fonayen.c main_Fonayen.c -lm -lpthread -o songo


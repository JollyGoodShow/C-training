connectn.out: win.o move.o game.o connectn.o
	gcc -g -Wall -o connectn.out win.o move.o game.o connectn.o
	
win.o: win.c win.h
	gcc -g -Wall -c -o win.o win.c
	
move.o: move.c move.h
	gcc -g -Wall -c -o move.o move.c
	
game.o: game.c game.h win.h move.h
	gcc -g -Wall -c -o game.o game.c
	
connectn.o: connectn.c game.h
	-gcc -g -Wall -c -o connectn.o connectn.c
	
clean:
	rm -f *.o *.out

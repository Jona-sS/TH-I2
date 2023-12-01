# Aufruf linux: make -f makefilename
# Aufruf win:   mingw32-make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen
#
run:
	.\josephus.exe
josephus.exe: queue.o josephus.o
	gcc -o josephus.exe queue.o josephus.o
queue.o: queue.c queue.h
	gcc -c -Wall queue.c
josephus.o: josephus.c
	gcc -c -Wall josephus.c

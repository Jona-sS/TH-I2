# Aufruf linux: make -f makefilename
# Aufruf win:   mingw32-make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen
#
automat.exe: automat.o checker.o view.o io.o main.o
	gcc -o automat.exe automat.o checker.o view.o io.o main.o
	.\automat.exe
automat.o: automat.c automat.h
	gcc -c -Wall automat.c

checker.o: checker.c checker.h automat.h s_transaction_list.h
	gcc -c -Wall checker.c

view.o: view.c view.h automat.h io.h
	gcc -c -Wall view.c

io.o: io.c io.h
	gcc -c -Wall io.c

main.o: main.c view.h automat.h checker.h
	gcc -c -Wall main.c

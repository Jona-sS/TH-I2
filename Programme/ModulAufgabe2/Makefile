# Aufruf linux: make -f makefilename
# Aufruf win:   mingw32-make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen
#
TestMatrix.exe: matrixOp.o TestMatrix.o
	gcc -o TestMatrix.exe matrixOp.o TestMatrix.o
	.\TestMatrix.exe
matrixOp.o: matrixOp.c matrixOp.h
	gcc -c -Wall matrixOp.c

TestMatrix.o: TestMatrix.c
	gcc -c -Wall TestMatrix.c

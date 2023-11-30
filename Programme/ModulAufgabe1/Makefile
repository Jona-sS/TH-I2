# Aufruf linux: make -f makefilename
# Aufruf win:   mingw32-make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen
#
TestComplex.exe: TestComplex.o complex.o
	gcc -o TestComplex.exe complex.o TestComplex.o

complex.o: complex.c complex.h
	gcc -c -Wall complex.c

TestComplex.o: TestComplex.c
	gcc -c -Wall TestComplex.c

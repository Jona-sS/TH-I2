# makefile fuer GNU make zur Erstellung eines Test-Programmes 
# fuer Test einer Bibliothek 
# fuer GCC unter Windows falls noetig Pfad setzen:
# "C:\Program Files (x86)\CodeBlocks\MinGW\mingwvars.bat" 
# Aufruf: make <makefile> oder : make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen


Test_all: TestBruchrech

# Erstellung der Library

libbruchrech.a: bruchrech.o
	ar cr libbruchrech.a bruchrech.o

bruchrech.o: bruchrech.c bruchrech.h
	gcc -Wall -c bruchrech.c


# Erstellung des Test-Programmes 

TestBruchrech: TestBruchrech.o libbruchrech.a
	gcc -Wall -o TestBruchrech TestBruchrech.o libbruchrech.a

TestBruchrech.o: TestBruchrech.c bruchrech.h
	gcc -Wall -c TestBruchrech.c




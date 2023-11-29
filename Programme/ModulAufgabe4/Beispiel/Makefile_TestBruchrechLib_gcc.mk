# makefile fuer GCC / GNU make zur Erstellung einer Library und 
# eines Test-Programmes fuer Test der Bibliothek 
# Fuer GCC unter Windows, falls noetig Pfad setzen, z.B.:
# "C:\Program Files (x86)\CodeBlocks\MinGW\mingwvars.bat" 
# Falls make fehlt, ist es ggf. noch zu installieren
# und Pfad für make zu setzen, z.B.:
# set path=%path%;C:\Program Files (x86)\GnuWin32\bin\
# Aufruf: make <makefile> oder : make -f makefilename
# -B: Build all; Alle Ziele ohne Bedingungen erstellen


Test_all: TestBruchrech


# Erstellung der Library name.a

libbruchrech.a: bruchrech.o
	ar cr libbruchrech.a bruchrech.o

bruchrech.o: bruchrech.c bruchrech.h
	gcc -Wall -c bruchrech.c


# Erstellung des Test-Programmes fuer / mit der Lib name.a

TestBruchrech: TestBruchrech.o libbruchrech.a
	gcc -Wall -o TestBruchrech TestBruchrech.o libbruchrech.a

TestBruchrech.o: TestBruchrech.c bruchrech.h
	gcc -Wall -c TestBruchrech.c




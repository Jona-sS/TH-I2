# makefile fuer VC++ / nmake zur Erstellung einer Library und 
# eines Test-Programmes fuer Test der Bibliothek 
# Falls noetig, Pfad setzen, z.B.:
# "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
# Aufruf: nmake <makefile> oder: nmake -f makefilename
# -A: Build All; Alle Ziele ohne Bedingungen erstellen


Test_all: TestBruchrech.exe


# Erstellung der Library name.lib

bruchrech.lib: bruchrech.obj
	lib bruchrech.obj

bruchrech.obj: bruchrech.c bruchrech.h
	cl -Wall -c bruchrech.c


# Erstellung des Test-Programmes fuer / mit der Lib name.lib

TestBruchrech.exe: TestBruchrech.obj bruchrech.lib
	cl -Wall TestBruchrech.obj bruchrech.lib

TestBruchrech.obj: TestBruchrech.c bruchrech.h 
	cl -Wall -c TestBruchrech.c 




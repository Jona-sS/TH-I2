# makefile fuer VC++ / nmake zur Erstellung eines Programmes 
# fuer Test einer Bibliothek  
# falls noetig Pfad setzen:
# "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
# Aufruf: nmake <makefile> oder: nmake -f makefilename
# -A: Build All; Alle Ziele ohne Bedingungen erstellen


Test_all: TestBruchrech.exe

# Erstellung der Library

bruchrech.lib: bruchrech.obj
	lib bruchrech.obj

bruchrech.obj: bruchrech.c bruchrech.h
	cl -Wall -c bruchrech.c


# Erstellung des Test-Programmes 

TestBruchrech.exe: TestBruchrech.obj bruchrech.lib
	cl -Wall TestBruchrech.obj bruchrech.lib

TestBruchrech.obj: TestBruchrech.c bruchrech.h 
	cl -Wall -c TestBruchrech.c 




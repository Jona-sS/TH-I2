# makefile fuer VC++ / nmake zur Erstellung einer Library 
# Falls noetig, Pfad setzen, z.B.:
# "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat"
# Aufruf: nmake <makefile> oder: nmake -f makefilename
# -A: Build All; Alle Ziele ohne Bedingungen erstellen


Test_all: bruchrech.lib


# Erstellung der Library name.lib

bruchrech.lib: bruchrech.obj
	lib bruchrech.obj

bruchrech.obj: bruchrech.c bruchrech.h
	cl -Wall -c bruchrech.c





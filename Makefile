FILES = common.h debug.c debug.h main.c scanner.c scanner.h 
COMPILEDHEADERS = scanner.h.gch common.h.gch debug.h.gch

all:
	gcc $(FILES)
	del $(COMPILEDHEADERS)

clean:
	del a.exe
	del $(COMPILEDHEADERS)
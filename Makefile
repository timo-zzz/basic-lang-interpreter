FILES = scanner.c scanner.h
COMPILEDHEADERS = scanner.h.gch

all:
	gcc $(FILES)
	del $(COMPILEDHEADERS)

clean:
	del a.exe
	del $(COMPILEDHEADERS)
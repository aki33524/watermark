CFLAGS = -std=c++14 -O3 -Wall

all: extract embed

extract: extract.cpp misc.o watermark.o ARC4.o
	g++ $(CFLAGS) extract.cpp misc.o watermark.o ARC4.o -o $@

embed: embed.cpp misc.o watermark.o ARC4.o
	g++ $(CFLAGS) embed.cpp misc.o watermark.o ARC4.o -o $@

misc.o: misc.cpp misc.h
	g++ $(CFLAGS) -c misc.cpp -o $@

watermark.o: watermark.cpp watermark.h
	g++ $(CFLAGS) -c watermark.cpp -o $@

ARC4.o: ARC4.cpp ARC4.h
	g++ $(CFLAGS) -c ARC4.cpp -o $@


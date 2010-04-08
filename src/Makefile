CC = g++
CFLAGS = -lSDL -lGL -lGLU -lSDLmain
LDFLAGS =
SOURCES = *.cpp
HEADERS = *.h

all: main
	
main: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SOURCES) -o $@
	
clean:
	-rm -f main *~

CC=g++
CFLAGS=-Wall -g 
LDFLAGS=
SOURCES=src/main.cpp src/Publication.cpp src/Author.cpp src/InstituteAuthor.cpp src/NonInstituteAuthor.cpp src/PublicationManager.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/publication_tracker

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	- del /Q src\*.o
	- del /Q bin\publication_tracker.exe
CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = bibtex_processor

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	del /f $(OBJ) $(EXEC)
	del bibtex_processor.exe

run: $(EXEC)
	./$(EXEC)

.PHONY: all clean run

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Project files
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = bibtex_processor

# Targets

# The default target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to build object files from C++ source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and the executable (Windows version using del)
clean:
	del /f $(OBJ) $(EXEC)
	del $(EXEC).exe

# Optional: A target to run the program (assuming you want to run it after building)
run: $(EXEC)
	./$(EXEC)

# Phony targets (non-file targets)
.PHONY: all clean run

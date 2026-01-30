# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SANITIZE = -fsanitize=address

# Target executable
TARGET = whatever
# Source files
SOURCES = main.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = whatever.hpp

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJECTS) Makefile
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)
	@echo "✓ Executable '$(TARGET)' created successfully"

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJECTS)
	@echo "✓ Object files removed"

# Clean executable
fclean: clean
	rm -f $(TARGET)
	@echo "✓ Executable removed"

# Rebuild everything
re: fclean all

# Build with sanitizer (for debugging)
debug: CXXFLAGS += $(SANITIZE)
debug: re
	@echo "✓ Built with address sanitizer"

# Phony targets
.PHONY: all clean fclean re debug

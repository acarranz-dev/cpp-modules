CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

TARGET = polyset_test

HEADERS = bag.hpp \
          searchable_bag.hpp \
          array_bag.hpp \
          tree_bag.hpp \
          searchable_array_bag.hpp \
          searchable_tree_bag.hpp \
          set.hpp

SRCS = main.cpp

all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)

re: clean all

.PHONY: all clean re

#################################################
# MAKEFILE
#################################################

CXX		 := g++
CXXFLAGS := -std=c++11

BIN     := bin
SRC     := src
BUILD	:= build
INCLUDE := include
LIB     := lib
LIBRARIES   := nfa.fa lib/input.txt
EXECUTABLE  := Program

SOURCES := $(wildcard $(SRC)/*.cc)
OBJS	:= $(patsubst $(SRC)/%.cc,$(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src lib

run:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(LIB)/$(LIBRARIES)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*
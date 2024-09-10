MAIN := src/main.cpp
OUTPUT_DIR := output
INCLUDE_DIR := include

all: clean build run

build:
	mkdir -p $(OUTPUT_DIR)
	g++ $(MAIN) -o $(OUTPUT_DIR)/main -I $(INCLUDE_DIR)/

run:
	./$(OUTPUT_DIR)/main

clean:
	rm -rf $(OUTPUT_DIR)

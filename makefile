OUTPUT_DIR := output
INCLUDE_DIR := include

universe: u_build u_run

u_build:
	mkdir -p $(OUTPUT_DIR)
	g++ src/universe.cpp -o $(OUTPUT_DIR)/universe -I $(INCLUDE_DIR)/

u_run:
	./$(OUTPUT_DIR)/universe

clean:
	rm -rf $(OUTPUT_DIR)

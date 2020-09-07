.PHONY: all clean run
.DEFAULT_GOAL := run

OUTPUT = cmdCalc.out
CXXFLAGS = -O3 -std=c++17 -Wall -Wextra -o $(OUTPUT)
FILES =  calc.cpp
HEADERS = 

$(OUTPUT): $(FILES) $(HEADERS)
	$(CXX) $(FILES) $(CXXFLAGS)

run: $(OUTPUT)
	./$(OUTPUT)

clean:
	@$(RM) *.out
	@$(RM) calc

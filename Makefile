CXX := clang++
CXX_FLAGS := -std=c++14 -Weverything -fno-rtti -Wno-c++98-compat-pedantic -g -O3 -fsanitize=undefined -fsanitize=address

LINKER_EXE := clang
LINKER_EXE_FLAGS := -g -O3 -fsanitize=undefined -fsanitize=address

-include tmp/check.o.d
tmp/check.o: check.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/check.o -MF tmp/check.o.d -c check.cpp -o tmp/check.o

-include tmp/check_benchmark.o.d
tmp/check_benchmark.o: check_benchmark.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/check_benchmark.o -MF tmp/check_benchmark.o.d -c check_benchmark.cpp -o tmp/check_benchmark.o

-include tmp/check_blockhash.o.d
tmp/check_blockhash.o: check_blockhash.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/check_blockhash.o -MF tmp/check_blockhash.o.d -c check_blockhash.cpp -o tmp/check_blockhash.o

-include tmp/check_comparison.o.d
tmp/check_comparison.o: check_comparison.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/check_comparison.o -MF tmp/check_comparison.o.d -c check_comparison.cpp -o tmp/check_comparison.o

-include tmp/check_parse_stringify.o.d
tmp/check_parse_stringify.o: check_parse_stringify.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/check_parse_stringify.o -MF tmp/check_parse_stringify.o.d -c check_parse_stringify.cpp -o tmp/check_parse_stringify.o

-include tmp/check_reference.o.d
tmp/check_reference.o: check_reference.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/check_reference.o -MF tmp/check_reference.o.d -c check_reference.cpp -o tmp/check_reference.o

check.bin: tmp/check.o tmp/check_benchmark.o tmp/check_blockhash.o tmp/check_comparison.o tmp/check_parse_stringify.o tmp/check_reference.o
	$(LINKER_EXE) $(LINKER_EXE_FLAGS) -lstdc++ -lm -o check.bin tmp/check.o tmp/check_benchmark.o tmp/check_blockhash.o tmp/check_comparison.o tmp/check_parse_stringify.o tmp/check_reference.o

-include tmp/example.o.d
tmp/example.o: example.cpp
	$(CXX) $(CXX_FLAGS) ${opts} -MMD -MT tmp/example.o -MF tmp/example.o.d -c example.cpp -o tmp/example.o

example.bin: tmp/example.o
	$(LINKER_EXE) $(LINKER_EXE_FLAGS) -lstdc++ -lm -o example.bin tmp/example.o

all: check.bin example.bin
.PHONY: all
clean:
	@rm -f tmp/check.o tmp/check_benchmark.o tmp/check_blockhash.o tmp/check_comparison.o tmp/check_parse_stringify.o tmp/check_reference.o check.bin tmp/example.o example.bin
.DEFAULT_GOAL := all

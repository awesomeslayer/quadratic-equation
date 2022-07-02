QE: ./source/qe_functions.h ./source/qe_functions.cpp ./source/qe_main.cpp ./tests/qe_tests.h ./tests/qe_tests.cpp
	g++ -o $@ $^

%.o:%.c
	g++ -c -o $@ $<
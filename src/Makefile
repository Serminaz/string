CC=gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra
SOURCES= s21_string.c s21_sprintf.c s21_sscanf.c
OBJECTS=$(SOURCES:.c=.o)
GCOVFLAGS=-L. --coverage
HTML=lcov -t "test" -o rep.info -c -d .
OS := $(shell uname)

ifeq ($(OS), Darwin)
	CHECK_H=-lcheck
else
	CHECK_H=-lcheck -pthread -lrt -lm
	# CHECK_H=-lcheck -lm -lrt -lpthread -D_GNU_SOURCE
endif

all: gcov_report

s21_string.a: clean $(OBJECTS)
	ar rcs s21_string.a $(OBJECTS)
	# ranlib s21_string.a

test: s21_string.a
	$(CC) $(CFLAGS) s21_unit_test.c $(SOURCES) -o test $(CHECK_H) $(GCOVFLAGS)
	-./test

gcov_report: test
	$(HTML)
	genhtml -o report rep.info

open:
	open ./report/index.html # DELETE BEFORE FINISH PROJECT

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css test report

linter:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck *.h *.c

vc:
	CK_FORK=no valgrind --tool=memcheck ./test
	 
lik: 
	CK_FORK=no leaks -atExit -- ./test


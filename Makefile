CC = /usr/bin/g++
CC_OPTIONS = -Wall -Wextra -Werror
INCS = -I/usr/local/include/ -I./include
OPTIONS = $(CC_OPTIONS)  $(INCS)

test: test.cc
	$(CC) test.cc $(OPTIONS) -o test
clean:
	rm -f test

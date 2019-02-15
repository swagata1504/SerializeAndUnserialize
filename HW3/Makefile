CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment=hw3

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -o $@ $^
tar:
	tar -cv $(MAKEFILE_LIST) *.cc >$(assignment).tar

clean:
	rm -f $(assignment) $(assignment).tar *.o *.gch
hw4.o: hw4.cc functions.h

CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment=hw4

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -c $(assignment).cc
	ar rsc $(assignment).a $(assignment).o
# test: 
# 	g++ $(CPPFLAGS) -o tst test.cc hw4.a
# 	./tst

tar:
	tar -cv $(MAKEFILE_LIST) *.h hw4.cc >$(assignment).tar

clean:
	rm -f $(assignment) $(assignment).tar *.o *.gch tst $(assignment).a


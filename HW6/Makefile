CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment=Serial

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -c $(assignment).cc
	ar rsc hw6.a $(assignment).o
test: 
	g++ $(CPPFLAGS) -o tst test.cc hw6.a
	./tst

tar:
	tar -cv $(MAKEFILE_LIST) Serial.cc Serial.h >hw6.tar


clean:
	rm -f $(assignment) hw6.tar *.o *.gch tst hw6.a


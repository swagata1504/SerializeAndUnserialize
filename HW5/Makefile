CPPFLAGS=-Wall -Werror -Wextra -Wfatal-errors
assignment=Serial

$(assignment): $(assignment).o
	g++ $(CPPFLAGS) -c $(assignment).cc
	ar rsc hw5.a $(assignment).o
test: 
	g++ $(CPPFLAGS) -o tst test.cc hw5.a
	./tst

tar:
	tar -cv $(MAKEFILE_LIST) Serial.cc Serial.h >hw5.tar


clean:
	rm -f $(assignment) hw5.tar *.o *.gch tst hw5.a


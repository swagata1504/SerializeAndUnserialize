CXXFLAGS:=-Wall -Wextra -Wpedantic -Werror -Wfatal-errors 

assignment=hw7

$(assignment).a: OFSerial.o IFSerial.o
	ar rcs $@ $^

OFSerial.o:: FSerial.h
IFSerial.o:: FSerial.h
testprog.o:: FSerial.h

test: testprog
	./testprog

testprog: testprog.o $(assignment).a
	$(CXX) $(CXXFLAGS) -o $@ $^

tar:
	tar -cv $(MAKEFILE_LIST) IFSerial.cc OFSerial.cc FSerial.h >$(assignment).tar

clean:
	rm -f a.out testprog *.a *.tar *.o

CS253 HW5: Time to get classy!                

Description                
For this assignment, you will write a class called Serial (that’s a capital letter S) which builds upon your previous work. Specifically, you will provide Serial.h (capital S), which will contain the interface of class Serial, and hw5.a, which will contain the implementation of class Serial.                 

The class will, conceptually, contain a serialized string. You can add values to the back of the string, and retrieve values from the front of the string. Adding values makes the string longer, and retrieving values makes the string shorter. In addition, you can set and retrieve the accumuated serialized string.                 

Values can only be added to the back of the string, and can only be removed from the front of the string. That is, if you add, in order, the int 3, the char 'x', and the short 5, then the first thing removed must be an int, which will be 3, followed by a char, followed by a short. It’s a FIFO queue.                 

In the previous paragraphs, the string is merely for exposition. How you actually store the data in this class is up to you.                 

Methods                
Your class must have the following public methods:                 

Default constructor
Accumulated string is initially empty.
Copy constructor
Takes another Serial, and copies the information.
Assignment operator
Takes another Serial, and copies the information.
Destructor
Destroys.
put(bool)
put(short)
put(int)
put(long)
put(char)
put(string)
Add the datum to the back of the serialized string.
get(bool &)
get(short &)
get(int &)
get(long &)
get(char &)
get(string &)
Remove the datum from the front of the serialized string, and unserialize it into the variable, replacing any previous value. throw a descriptive std::string upon any problem.
str()
Retrieve the accumulated serialized string, without changing the object.
str(string)
Set the accumulated serialized string.
size()
Returns a int that is the size, in bytes, of the accumulated serialized string.
empty()
Returns true if the accumulated serialized string is empty, false if not.
Const-correctness, both arguments & methods, is your job. For example, it must be possible to call .size() on a const Serial, or to pass a const string to .put().                 

You may define other methods or data, public or private, as you see fit.                 

It is highly recommended that you override << to display the contents of a Serial.       

CS253 HW6: Operators!                

Description                
For this assignment, you will enhance class Serial by adding a few operators.                 

Methods                
Your class must have the same methods and operators described in HW5. You must also create the following operators:                 

Serial += bool
Serial += int
Serial += short
Serial += long
Serial += char
Serial += std::string
Serial += Serial
Serial + bool
Serial + int
Serial + short
Serial + long
Serial + char
Serial + std::string
bool + Serial
int + Serial
short + Serial
long + Serial
char + Serial
std::string + Serial
Serial + Serial
bool <<= Serial
int <<= Serial
short <<= Serial
long <<= Serial
char <<= Serial
std::string <<= Serial
Serial == Serial
Serial != Serial
Of course, you can’t write code that literally says bool + Serial. That means a bool expression on the left, and a Serial expression (perhaps a variable) on the right.                 

The above operators may be methods, or free functions, as you wish.                 

Const-correctness, both arguments & methods, is your job. For example, it must be possible to concatenate two const Serial objects, or compare a const Serial with a non-const Serial.                 

Appending via +=                
Adding to a Serial via += is the same as calling .put.                 

Serial += Serial is a bit different. It appends the string from the right-hand-side to the left-hand-side object, altering the left-hand-side object. The right-hand-side object is unchanged.                 

Concatenation via +                
Concatenating two Serial objects, or a Serial and a bool / int / short / long / char / std::string and a Serial, produces a new Serial object, which contains the serialized data from the left-hand-side object, followed by the serialized data from the right-hand-side object. Neither operand is modified.                 

Extraction via <<=                
Extraction via <<= is similar to the .get method. It removes the next datum from the front of the Serial, assigns it to the given variable, and throws a descriptive std::string if something goes wrong for the same reasons as .get.                 

I agree that this use of the operator is completely bizarre. We live in crazy times, don’t we?                 

Comparison via == and !=                
When comparing two Serial objects, just compare the accumulated strings. Compare them in the normal way that std::string objects are usually compared.                 


In this code I am implementing MyArray template class, which can store any data type. The class is not intended to substitute std::vector container but it shows some of the C++ features.
NumericArray is a template class derived from MyArray and can be used with datatypes which support basic arithmetic operations (for example multiplying the element of an array by a factor). Memory is managed by MyArray base class.
The Stack class “has a” MyArray class and mimics some of the stack functionalities (for example the pop and push functions). 

All three classes (MyArray, NumericArray and Stack) can throw exceptions in case an out of bound entry is requested. The classes that implement the exceptions are ArrayException and StackException. Exceptions are caught in main.
The class shape is an abstract class that it is used as a base class for other classes (line and point). The base class methods ToString() and Draw() are overloaded in the derived classes. Specifying a base class for all shapes allows us to use polymorphism.  

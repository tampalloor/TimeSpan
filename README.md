# TimeSpan
Designed and implemented a TimeSpan class which represents a duration of time in hours, minutes,
and seconds. The order hours, minutes, and seconds should be respected in the constructor.

As an example:
TimeSpan duration(1, 2, 3);
is a duration of time of 1 hour, 2 minutes and 3 seconds.

In the instances of the TimeSpan class you should store the values as integers in a normalized
way. The number of seconds should be between -60 and 60 when stored; number of minutes
should be between -60 and 60 when stored. That is, a user can create a TimeSpan object of 90
seconds, but it should be stored as 1 minute, 30 seconds. See example below.

Accessor functions 
The TimeSpan class implement the following member functions:
int hours() const; return the number of hours as an int
int minutes() const; return the number of minutes as an int
int seconds() const: return the number of Seconds as an int
void set_time(int hours, int minutes, int seconds): set the number of hours, minutes,
seconds.

Constructors
The class  define constructor(s) that receive various primitive types (specifically
int, float, and double) and store them as integers. The constructor should take one, two or
three arguments. If only one parameter is passed during initialization assume it is seconds. If
there are two assume minutes and seconds (in that order).

Perform appropriate rounding to maintain as much accuracy as possible down to the
second as the smallest granularity. You should not keep fraction of seconds.

Here are some examples:
TimeSpan(1.5, 4, -10) represents 1 hour, 33 minutes, 50 seconds.
TimeSpan(7, -3) represents 6 minutes, 57 seconds.
TimeSpan(-190) represents -3 minutes, -10 seconds.
TimeSpan(3, -90, 120) represents 1 hour, 32 minutes.

Operators
The class overload and implement the following math operators: addition,
subtraction, and Unary Negation.
The class must overload and implement the following comparison operators: ==, !=, <,
<=, >, >=
The class must implement += and -= assignment statements as well.

Stream I/O
The class will also implement the input / output operators: >> and << :
Input: >>
Take as input three values: hour, minutes, seconds and create appropriate class. Assume
that these will be integers.
Output: <<
Output the values in the following format: Hours: value, Minutes: value, Seconds: value
As an example, this code:
TimeSpan duration1(1, 2, 3);
std::cout << duration1;
Will output:
Hours: 1, Minutes: 2, Seconds: 3

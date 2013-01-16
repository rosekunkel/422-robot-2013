# Coding Style Guide #
These rules are meant as guidelines for writing C++ for Team 422 for the 2013
season. These are not hard-and-fast rules, and most may be broken with good
reason. Code should first and foremost be designed in a logical manner. However,
these guidelines allow consistency and readability to be maintained across all
of the robot's code. Do not break them without good reason.

This document is modeled after the [Google Code C++ style
guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml).

## Header Files ##

### Guards ###
Every header file **must** be wrapped in a `#define` guard. These guards ought
to be named after the file they represent, e.g. a file named
"articulated_arm.hpp" should have a `#define` guard like this:

    #ifndef ARTICULATED_ARM_HPP
	#define ARTICULATED_ARM_HPP
	//Body of function
	#endif //ARTICULATED_ARM_HPP

Trailing comments, like the one in the example above, are recommended.

### "using namespace" Statements ###
Statements beginning with `using namespace` should never be used in header
files, as they pollute the global namespace. Instead, names should be referenced
by their full name, e.g. `std::vector`, or, if used extensively, single `using`
statements are acceptable, such as `using std::vector`.

## Scoping ##

### Global Variables ###
Avoid using global variables and/or functions. Use methods and member variables
of classes when possible.

### Local Variables ###
Declare local variables at the top of their enclosing scope, that is, at the top
of the block in which they are declared. Initialize variables on declaration,
like this:

    int i = 0;

Rather than this:

    int i;
	i = 0;

## Classes ##

### Constructors ###

#### Initialization Lists ####
When assigning values to member variables in a constructor, use the
initialization list rather than the body of the constructor when possible. That
is, do this:

    Foo::Foo() :
	bar(0),
	baz(1) {
		//Initialize
	}

Rather than this:

    Foo::Foo() {
		bar = 0;
		baz = 1;
		//Initialize
	}

This method is both more efficient and the only valid method to initialize
constant member variables, so using it consistently helps prevent errors.

#### Default Constructors ####
Default constructors must be defined for all classes.

### Structs vs. Classes ###
Structs should be used only for containers for data, they must not have
methods. When in doubt, use a class.

### Encapsulation ###
Class members should be declared as `private` unless absolutely
necessary. Getters and setters should be used for changing member variables of
classes, rather than making the variables public. Getters and setters should be
named `getVariableName()` and `setVariableName( variableType newVariableName )`
respectively.

### Order of Declaration ###
`public` class members should be declared before `private` class members, and
variables should be declared before methods, e.g.

    class Foo {
    	public:
    		int i;
    		bar();
    	private:
    		int j;
    		baz();
    }

## Functions and Methods ##
Functions should be short if possible. Functions ought to accomplish one task,
and be descriptively named to fit that task, e.g. `raiseArm()`.

## Exceptions ##
Do not use exceptions in C++, as they make control flow difficult to understand
and require extremely safe coding to avoid memory leaks.

## Casting ##
Use C++ style casting, i.e. `static_cast<int>(i)`, rather than C-style casting,
i.e. `(int)i`.

## Increment and Decrement ##
Use the prefix form of `++` and `--` whenever either form would be acceptable,
e.g. `++i;` rather than `i++;`

## Integer Types ##
Use only `int`, not `long`, `short`, or `unsigned`. If other integer types are
needed, use the consistent types from `<stdint.h>`, such as `int_32_t` or
`uint_64_t`.

## Preprocessor Macros ##
Avoid using preprocessor macros when possible, and exercise caution when using
them.

## Values of Zero ##
Use 0 for integers, 0.0 for reals, nullptr for pointers, and '\0' for chars.

## Constant Values ##
Constants should be declared as `const type name = value;`, rather than using
`#define`. This prevents unexpected behavior, especially when subtracting
negative constants.

## Naming ##
Use descriptive names, avoid unclear abbreviation.

### File Names ###
File names should be in TitleCase.

### Type Names ###
Type names are in TitleCase. This applies to classes, structs, enums, and all
other user-defined types.

### Variable Names ###
Variable names are in camelCase. Additionally, boolean variables should imply
their type by beginning with "is", such as `isRobotMoving`.

### Constant Names ###
Constants should be named in UPPERCASE\_WITH\_UNDERSCORES.

### Function Names ###
Functions should be in camelCase, and usually should contain a verb in their
name, e.g. `moveForward()` not just `forward()`.

### Enums ###
Enums should be named in TitleCase, where enum values should be named in
UPPERCASE\_WITH\_UNDERSCORES.

### Macro Names ###
Macros should be named in UPPERCASE\_WITH\_UNDERSCORES.

## Comments ##

### Multi-line Comments ###
Comments within the body of a method, function, and/or class should avoid using
the multi-line form. Instead, multiple-line comments should simply have `//` at
the beginning of each line.

### Doxygen ###
Implementational comments, that is, describing how code works, should be written
as normal comments. Descriptive comments, i.e. describing what code is meant to
achieve, should be Doxygen comments. Doxygen comments within methods, functions,
and/or classes should use the `///` or `///<` forms, comments outside of these
may use the multi line `/** ... */` form.

Additional documentation on Doxygen may be found
[here](http://www.stack.nl/~dimitri/doxygen/manual/index.html).

### TODO Comments ###
Incomplete or poorly-implemented sections of code should be marked with a
ccomment formatted as `//TODO: An explanation of the problem`. If documentation
is incomplete, instead use `/// @todo An explanation of what's missing`.

## Formatting ##

### Line Length ###
Every line must be no more than 80 characters long.

### Whitespace ###
Tabs should be used for logical indentation, and spaces for alignment. This
prevents alignment from being distorted by different tab sizes.

### Curly Braces ###
Curly braces should open on the same line as the expression that requires a new
block. For example:

    int foo() {
		//function body
	}

Rather than:

    int foo()
	{
	//function body
	}

A closing curly brace should be alone on its line, do not, for example, open an
else statement on the same line as the end of an if statement, i.e.

    if(condition) {
		//do something
	} else {
		//do something
	}

Instead prefer:

    if(condition) {
		//do something
	}
	else {
		//do something
	}

Conditional statements must always use curly braces, even when they only span
one line.

### Boolean Expressions ###
Boolean expressions spanning more than one line must have the joining operator
(either `||`or `&&`) at the beginning of each line, not the end.

### Parentheses ###
Parenthesis should indicate order of operations in all expressions containing
more than one operator, even when unnecessary, e.g. `1 + ( 1 * 2 )`.

Parentheses should have a space before and after their contents, unless they are
part of a function call, loop, or conditional statement.

### Classes ###
Access specifiers should not be indented with the body of the class.

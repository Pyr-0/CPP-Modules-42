# C++ Casting

## Table of Contents

- [About](#about)
- [Keywords](#keywords)
- [Previous Notions](#previous-notions)
- [Exercise 00: Conversion of scalar types](#ex00)
- [Exercise 01: Serialization](#ex01)
- [Exercise 02: Identify Real Type](#ex02)
- [Summary](#summary)

## About <a name = "about"></a>

In this set of exercises we will learn about the different types of casting in C++, in the [Ex00](#Ex00) exercise we will be making a "Converter" for casting multiple types onto one another using ```static_cast```, on the [Ex01](#Ex01) exercise we will learn about ```reinterpret_cast``` and lastly we will dive into the topic of ```dynamic_cast``` in the [Ex02](#Ex02).

_DISCLAIMER_ \
It is worth noting that this guide is simply my own review on the topics in base of what the tasks for each exercises lead me to do research on, that means this are  over simplified notions of the topics and by no means a complete lecture on Type casting.


## Key Words <a name = "Key Notions"></a>

- [Static Cast](#static-cast)
- [Reinterpret Cast](#reinterpreted-cast)
- [Dynamic](#dynamic-cast)

## Previous Notions <a name = "Previous notions"></a>


- Typecasting is also called as type conversion
- It means converting one data type into another.
- Converting smaller data type into a larger one is also called as type promotion.
- There are two type of type conversion: implicit and explicit type conversion in C.
- Implicit type conversion operates automatically when the compatible data type is found.
- Explicit type conversion requires a type casting operator.
- Downcast: From a generic type to a more specific type
- Upcast: From a more specific type to a generic type

C offers 2 types of casts (don't use them for C++):

    implicit cast
    explicit cast

C++ offers 5 types of casts:

- ```implicit cast```: only conversion of simple values and upcast

- ```static_cast```: with downcast and upcast, we know what we want and where we are going from the inheritance tree. This will not prevent cross-cast, but gives issues at run time. But it will prevent cast from classes of two different inheritance trees.

- ```dynamic_cast```: only cast that happens at runtime. It adds certain performance overheads to your program. It takes advantage of rtti(run-time type information). The class must have one virtual member function. It will check if the transform from one form to another is realistic base on the hierarchy. It is one of the base principles, hidden behind the notion of plugin

- ```const_cast```: will not be used often. Consider if it's a design flaw when you need to use this cast

- ```reinterpret_cast```: the most open cast. No semantics check. The most suitable case is to change the type of some raw data, or you want to convert the type of one data to another type that is usable by your program.


## Exercise 00: Conversion of scalar types <a name = "Ex00"></a>

This first exercise was developed using the concept of ```static_cast```, and this method of casting was chosen due to the implicit type conversion that is required throughout each of the required tasks.

```static_cast``` is the first cast you should attempt to use. It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones).

Here is the syntax used in c++ to conjure a [Static cast](#static-cast):

```c++
	//this will be the Library needed to use the multiple casting methods
	#include <iostream>

	//Here we asume of x to be a different data type from where we want to cast
	std::static_cast<char>(x);

	std::static_cast<int>(x);

	std::static_cast<float>(x);

	std::static_cast<double>(x);
```

## Exercise 01: Serialization <a name = "Ex01"></a>

This second exercise uses the  ```reinterpret_cast```. This cast will allow you to do reinterpretation, as well as [__Downcast__](#downcast) and [__Upcast__](#upcast). It's a very open form of casting. Being the earlier a conversion of something broad into something specific, and the latter makes out of something specific something broader.

It is used primarily for particularly weird conversions and bit manipulations, like turning a raw data stream into actual data, or storing data in the low bits of a pointer to aligned data.

Here is the syntax used in c++ to conjure a [Reinterpret cast](#reinterpret-cast):

```c++
	//this will be the Library needed to use the multiple casting methods
	#include <iostream>

	//Here we asume of x to be a different data type from where we want to cast
	std::reinterpret_cast<char>(x);

	std::reinterpret_cast<int>(x);

	std::reinterpret_cast<float>(x);

	std::reinterpret_cast<double>(x);
```
![alt text](https://imgflip.com/i/6uk77j)

## Exercise 02: Identify real type <a name = "Ex02"></a>

In this last exercise ```dynamic_cast``` is used in order to up/down cast along the hierarchy of the inheritance tree.

This Cast form safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.

```dynamic_cast```  means that the cast is checked dynamically (when the program is executing / at run time). So the dynamic cast may fail at run time, so you have to handle the potential failures within your code. All other casts are made during compilation and it's done in a static way.

You can only apply this operator to pointers and references to ```polymorphic class``` types, which are class types that contain at least one virtual function. The reason is that only pointers to polymorphic class types contain the information that the ```dynamic_cast<>()``` operator needs to check the validity of the conversion.

Here is the syntax used in c++ to conjure a [Dynamic cast](#dynamic-cast):

```c++
	//this will be the Library needed to use the multiple casting methods
	#include <iostream>

	//Here we asume of x to be a different data type from where we want to cast
	std::dynamic_cast<char>(x);

	std::dynamic_cast<int>(x);

	std::dynamic_cast<float>(x);

	std::dynamic_cast<double>(x);
```

### Summary

- Use ```static_cast``` for ordinary type conversions.

- Use ```reinterpret_cast``` for low-level reinterpreting of bit patterns. Use with extreme caution.

- Use ```dynamic_cast``` for converting pointers/references within an inheritance hierarchy  with polymorphic classes.


## Resources <a name = "usage"></a>

Here's a list of useful links for further information about Type Casting in C++

- https://github.com/qingqingqingli/CPP/wiki/Module06#2nd-c-cast-dynamic_cast

- https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

- https://www.youtube.com/watch?v=HlNVgmvX1EI

- https://www.youtube.com/watch?v=pWZS1MtxI-A


## License <a name = "usage"></a>

[![License: WTFPL](https://img.shields.io/badge/License-WTFPL-brightgreen.svg)](http://www.wtfpl.net/about/) [![License: CC0-1.0](https://licensebuttons.net/l/zero/1.0/80x15.png)](http://creativecommons.org/publicdomain/zero/1.0/)

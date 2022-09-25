<p align="center">
  <a href="" rel="noopener">
 <img width=200px height=200px src="https://raw.githubusercontent.com/isocpp/logos/master/cpp_logo.png" alt="Project logo"></a>
</p>

<h3 align="center">CPP06 - Module 7</h3>
<p align="center"> C++ Templates
   <br>
</p>
<div align="center">

[![License: WTFPL](https://img.shields.io/badge/License-WTFPL-brightgreen.svg)](http://www.wtfpl.net/about/)
<!--[![License: CC0-1.0](https://licensebuttons.net/l/zero/1.0/80x15.png)](http://creativecommons.org/publicdomain/zero/1.0/)-->
</div>

---
<br />

## 📝 Table of Contents

- [About](#about)
- [Keywords](#keywords)
- [Previous Notions](#previous-notions)
- [Exercise 00: Conversion of scalar types](#ex00)
- [Exercise 01: Serialization](#ex01)
- [Exercise 02: Identify Real Type](#ex02)
- [Summary](#summary)

_DISCLAIMER_ ❗️<br />
_It is worth noting that this guide is simply my own review on the topics in base of what the tasks for each exercises lead me to do research on, that means this are over simplified notions of the topics and by no means a complete lecture on C++ Templates._

---

## About <a name = "about"></a>

In this set of exercises we will learn about Templates and their basic uses in C++, in the [Ex00](#Ex00) exercise we will create simple Template functions in order to get use to the syntax and the way to call our templates in a program , on the [Ex01](#Ex01) exercise we will learn about ```reinterpret_cast``` and lastly we will dive into the topic of ```dynamic_cast``` in the [Ex02](#Ex02).



## Key Words <a name = "Key Notions"></a>

- [Templates](#templates)

## Previous Notions <a name = "Previous notions"></a>


- Templates enable you to define the operations of a class or function, and let the user specify what concrete types those operations should work on.

C++ has 2 main uses of templates:
<br /><br /> ![alt text](https://d1m75rqqgidzqn.cloudfront.net/wp-data/2022/09/15170233/image-8.png)


- ```Function Templates```:

- ```Classes Templates```: 

## Exercise 00: Start with a few functions <a name = "Ex00"></a>

This first exercise introduces us to the concept of ```Function Templates```, and the use and call of custom templates in our programs.

```static_cast``` is the first cast you should attempt to use. It does things like implicit conversions between types (such as int to float, or pointer to void*), and it can also call explicit conversion functions (or implicit ones).

Here is the syntax used in c++ to conjure a [Static cast](#static-cast):

```c++
	template<class type>ret-type func-name(parameter list)
	{
	//body of the function
	}
	//Here we asume of x to be a different data type from where we want to cast
	std::static_cast<char>(x);

```

## Exercise 01: Serialization <a name = "Ex01"></a>

This second exercise uses the  ```reinterpret_cast```. This cast will allow you to do reinterpretation, as well as [__Downcast__](#downcast) and [__Upcast__](#upcast). It's a very open form of casting. Being the earlier a conversion of something broad into something specific, and the latter makes out of something specific something broader.

It is used primarily for particularly weird conversions and bit manipulations, like turning a raw data stream into actual data, or storing data in the low bits of a pointer to aligned data.

Here is the syntax used in c++ to conjure a [Reinterpret cast](#reinterpret-cast):

```c++
	//this will be the Library needed to use the multiple casting methods
	#include <iostream>

	//Here we asume of x to be a different data type from where we want to cast
	std::reinterpret_cast<uintptr_t>(*x);

```
![alt text](https://i.imgflip.com/6uk77j.jpg)

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

#

## 📚 Resources <a name = "usage"></a>

Here's a list of useful links for further information about Type Casting in C++

- https://github.com/qingqingqingli/CPP/wiki/Module06#2nd-c-cast-dynamic_cast

- https://stackoverflow.com/questions/332030/when-should-static-cast-dynamic-cast-const-cast-and-reinterpret-cast-be-used

- https://www.youtube.com/watch?v=HlNVgmvX1EI

- https://www.youtube.com/watch?v=pWZS1MtxI-A

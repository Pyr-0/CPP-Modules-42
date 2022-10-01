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

In this set of exercises we will learn about Templates and their basic uses in C++, in the [Ex00](#Ex00) exercise we will create simple ```Function Templates``` in order to get use to the syntax and the way to call our templates in a program, on the [Ex01](#Ex01) exercise we will impelement function templates to data type arrays, in order to serialize processes and apply actions (like printing the elements of an array) and lastly we will create a ```Class Template Array``` that creates an array of any data type in  [Ex02](#Ex02).



## Key Words <a name = "Key Notions"></a>

- [Function Templates](#templates)
- [Class Templates](#templates)

## Previous Notions <a name = "Previous notions"></a>

- C++ templates is a programming model that allows plugging-in of any data-type to the code (templated code). Without template, you would need to replicate same code all over again and again, for all required data-types. And obviously, as said before, it requires code maintenance. 
- Templates enable you to define the operations of a class or function, and let the user specify what concrete types those operations should work on.
- Templates create "Placeholders" for generic types, allowing serialization of code , flexibility and reusability.


C++ has 2 main uses of templates:
<br /><br /> ![alt text](https://d1m75rqqgidzqn.cloudfront.net/wp-data/2022/09/15170233/image-8.png)


## Exercise 00: Start with a few functions <a name = "Ex00"></a>

This first exercise introduces us to the concept of ```Function Templates```, and the use and call of custom templates in our programs. So here is a short introduction and exemplification on how they work.

### ```Function Templates:```

Here is how the syntax of a [Function Template](#functiontemplate) is constructed:

1. We need to define our ```< Content >``` 

Where Content can be:
- class T / typename T. \
The use of ```<class TYPE>``` and ```<typename TYPE>``` for creating templates works the same way (so no need of getting confused like i did when i first saw it ;)).

- A data type, which maps to T\
The symbol T is nothing but some data-type, which can be any data-type, a basic datatype ```(int, double etc)```
- An integral specification
- An integral constant/pointer/reference which maps to specification mentioned above. 

2. Under our template declaration we write our Function as we normally would, like follows:
```c++
	template<class type>
	ret-type func-name(parameter list)
	{
		//body of the function
	}
```

## Syntax Example and usage
```c++
	//	We can the use our template with any data type we want 
	//	and the compiler will identify our input

	template<typename TYPE>
	void	printstuff(TYPE data)
	{
		std::cout << data<<std::endl;
	}

	int main(){
		printstuff(42);				//int
		printstuff(21.21);			//double
		printstuff('a');			// char
		printstuff("Hello World");	//string
	}
```
The first line of code ```template<class TYPE>```
tells the compiler that this is a function-template. The actual meaning of ```TYPE``` would be deduced by compiler depending on the argument passed to this function. Here, the name, ```TYPE``` is known as template type parameter.


## Exercise 01: Iter <a name = "Ex01"></a>
Now in this exercise lets use the learned concepts into iterating the work of a function and implementing it into an array of elements.

For this we can implement as before a template over a function and pass a function as a parameter and the rest of the elements requested by the task (the address and length of the array)

```c++
	template< typename T>
	void	iter(T *array, int arrayLength, void myFunction(T const &ref)){

		// for every element in the array apply your custom function
		for(int i = 0; i < arrayLength; i++)
			myFunc(array[i]);
	}
```

## Exercise 02: Identify real type <a name = "Ex02"></a>

Now we can implement the concept of Templates into a Class, and that is what the exercise is about, to create a class array that creates and initializes an array using templates in order to create arrays of any type.

for a better understanding this is a short view on how ```Class Templates``` work.

### ```Classes Templates:```

More often, you would design and use class templates, than function templates. In general, you use a class template to define an abstract type whose behavior is generic and is reusable, adaptable.

## Syntax Example and usage

```c++
	#include <iostream> 
	using namespace std; 
	
	template <class T> 
	class Test{ 
	// Data memnbers of test 
		public: 
		   Test() 
		   { 
		       // Initialization of data members 
		       cout << "General template  \n"; 
		   } 
		   // Other methods of Test 
	}; 
	
	template <class T> 
	class Test <int> 
	{ 
	public: 
	   Test() 
	   { 
	       // Initialization of data members 
	       cout << "Specialized template \n"; 
	   } 
	}; 
	
	int main() 
	{ 
	    Test<int> a; 
	    Test<char> b; 
	    Test<float> c; 
	    return 0; 
	} 

// and the class template declaration starts with same syntax as function templates:

	template<class T>
	class Item
```
Note that the keyword ```class``` is used two times - firstly to specify template type specification (T), and secondly to specify that this is a C++ class declaration.

### Summary
#

## 📚 Resources <a name = "usage"></a>

Here's a list of useful links for further information about Type Casting in C++

- https://www.codeproject.com/Articles/257589/An-Idiots-Guide-to-Cplusplus-Templates-Part-1

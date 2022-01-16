/** @file castingDemo.cpp

*  @brief Explicit type conversion (casting)

*  Explicit type conversion (casting) is the use of direct and specific notation in the source code

 *  to request a conversion or to specify a member from an overloaded class.

 *  There are cases where no automatic type conversion can occur or

 *  where the compiler is unsure about what type to convert to, those cases require explicit instructions

 *  from the programmer or will result in error.

*  @author Hooman Salamat

*  @bug No known bugs.

*/

#include <iostream>

using namespace std;



void do_something(short arg)

{

    cout << "Doing something with a short" << endl;

}



void do_something(int arg)

{

    cout << "Doing something with an int" << endl;

}



class A

{

public:

    virtual void func() {}

};



class B : public A

{

public:

    void func() {}

};



class C

{



public:

    void func() {} // a non-const member function

};



void someFunction(const C& f)

{

    //f.func();      // compile error: cannot call a non-const

    // function on a const reference

    C& fRef = const_cast<C&>(f);

    fRef.func(); // okay

}



//! The dynamic_cast keyword is used to casts a datum from one pointer or reference of a polymorphic type to another, similar to static_cast but performing a type safety check at runtime to ensure the validity of the cast. Generally for the purpose of casting a pointer or reference up the inheritance chain (inheritance hierarchy) in a safe way, including performing so-called cross casts.

//! Syntax: TYPE& dynamic_cast<TYPE&> (object);

void f()

{

    A a;

    B b;



    A* ap = &b;

    B* b1 = dynamic_cast<B*>(&b); // NULL, because 'a' is not a 'B'

    B* b2 = dynamic_cast<B*>(ap); // 'b'

    C* c = dynamic_cast<C*> (ap);   // NULL.



    A& ar = dynamic_cast<A&>(*ap); // Ok.

    B& br = dynamic_cast<B&>(*ap); // not Ok.

    C& cr = dynamic_cast<C&> (*ap); // std::bad_cast



    A* base = new A();

    B* child = new B();

    //B* child = dynamic_cast<B*>(base);

    A* myBase = dynamic_cast<A*>(child);

}



int main()

{



    short val = 12;



    do_something(val);       // Prints "Doing something with a short"

    do_something(val * val); // Prints "Doing something with an int"



    //!The reinterpret_cast keyword is used to simply cast one type bitwise to another. Any pointer or integral type can be cast to any other with reinterpret cast, easily allowing for misuse. For instance, with reinterpret cast one might, unsafely, cast an integer pointer to a string pointer. It should be used to cast between incompatible pointer types.

    //! int is 4 bytes

    int a = 0x0fe38024;

   // int b = reinterpret_cast<int>(a);  //reinterpret_cast cannot convert from 'int' to 'int'

    int* c = reinterpret_cast<int*>(a);



    cout << "a= " << a << endl; //a=0x0fe38024

    //cout << "b= " << b << endl; //b=266567716

    cout << "c= " << c << endl; //c=0x0fe38024



    //!double can be converted to int

    double d = 12.5;

    int i = d;

    cout << i; //i=12



    //! The static_cast keyword can be used for any normal conversion between types. Conversions that rely on static (compile-time) type information. This includes any casts between numeric types, casts of pointers and references up the hierarchy, conversions with unary constructor, and conversions with conversion operator. For conversions between numeric types no runtime checks are performed if the current content fits the new type. Conversion with unary constructor will be performed even if it is declared as explicit.

    int as = static_cast<int>(7.5);



    //! It can also cast pointers or references down and across the hierarchy as long as such conversion is available and unambiguous. For example, it can cast void* to the appropriate pointer type or vice-versa. No runtime checks are performed.

    A* baseClass = new B();

    static_cast<B*>(baseClass)->func();



    //! The const_cast keyword can be used to remove the const or volatile property from an object. The target data type must be the same as the source type, except (of course) that the target type doesn't have to have the same const qualifier. The type TYPE must be a pointer or reference type.

    //! Syntax: TYPE* const_cast<TYPE*> (object);

    const int myConst = 5;

    int* nonConst = const_cast<int*>(&myConst);

    cout << "nonConst = " << *nonConst << endl;

}


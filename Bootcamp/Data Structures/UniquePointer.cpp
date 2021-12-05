/** @file UniquePointer.cpp
 *  @brief Unique Pointer
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <memory>

struct Foo
{
    Foo(std::string v) : value(v) {}
    void Bar() { std::cout << "Hello, " << value << "!" << std::endl; }
    std::string value;
};

int main() {

    std::unique_ptr<Foo> FooPtr = std::make_unique<Foo>("World");

    FooPtr->Bar();
    FooPtr.get()->Bar();
    (*FooPtr).Bar();

    return 0;
}
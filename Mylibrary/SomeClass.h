#pragma once   // Prevent multiple inclusions of this header

#include <iostream>

class SomeClass {
public:
    // Virtual destructor: required if the class will be inherited or mocked
    virtual ~SomeClass() = default;

    // Virtual method: required so Google Mock can override it
    virtual void SomeMethod();
};


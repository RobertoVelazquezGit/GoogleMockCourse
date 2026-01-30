#include <gmock/gmock.h> 
#include <gtest/gtest.h> 


#include "SomeClass.h"

class SomeMockedClass : public SomeClass {
public:
	MOCK_METHOD0(SomeMethod, void());
    // Commented out MOCK_METHOD(void, SomeMethod, (), (override)); not available with nuggets
};

TEST(SomeClassTest, CallsSomeMethodOnce) {
    SomeMockedClass mock;
    EXPECT_CALL(mock, SomeMethod()).Times(1);
    mock.SomeMethod();
}

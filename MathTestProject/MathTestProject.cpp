#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class SomeClass {
public:
	SomeClass() = default;
	virtual void SomeMethod() {
		// Implementation goes here
		std::cout << "SomeMethod called" << std::endl;	
	}	
};

class SomeMockedClass : public SomeClass {		
	public:
	//MOCK_METHOD0(SomeMethod, void());
	MOCK_METHOD(void, SomeMethod, (), (override));
};	

TEST(MockTest, MethodCallTest) {
	SomeMockedClass mockObj;
	EXPECT_CALL(mockObj, SomeMethod())
		.Times(1);

	mockObj.SomeMethod();
}

TEST(SampleTest, BasicTest) {
	ASSERT_EQ(1 + 1, 2);
}

int main(int argc, char **argv)
{
    std::cout << "Hello World!\n";
	testing::InitGoogleMock(&argc, argv);
	return RUN_ALL_TESTS();
}


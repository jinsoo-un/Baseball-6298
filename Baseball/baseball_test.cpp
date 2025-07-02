#include "gmock/gmock.h"
#include "baseball.cpp"
#include "baseball_test.h"

class BaseballFixture : public ::testing::Test {
public:
	Baseball game;
	void assertIlligalArgument(string guessNumber) {
		try {
			game.guess(string("guessNumber"));
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIlligalArgument("12");
	assertIlligalArgument("12a");
}

#include "pch.h"
#include "../TDD_BaseBall/baseball.cpp"

#include <stdexcept>
using namespace std;

class BaseballFixture : public testing::Test
{
public:
	Baseball game{ "123" };

	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(result.strikes, 3);
	EXPECT_EQ(result.balls, 0);
}

TEST_F(BaseballFixture, ReturnUnSolvedResult2Strikes0BallsCase1) {
	GuessResult result = game.guess("125");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
}

TEST_F(BaseballFixture, ReturnUnSolvedResult2Strikes0BallsCase2) {
	GuessResult result = game.guess("143");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
}

TEST_F(BaseballFixture, ReturnUnSolvedResult2Strikes0BallsCase3) {
	GuessResult result = game.guess("523");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
}

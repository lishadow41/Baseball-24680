#include "pch.h"
#include "../TDD_BaseBall/baseball.cpp"

#include <stdexcept>
using namespace std;

class BaseballFixture : public testing::TestWithParam<string>
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

class Baseball2Strikes0BallFixture : public BaseballFixture {};

TEST_P(Baseball2Strikes0BallFixture, ReturnUnSolvedResult2Strikes0Balls) {
	string guessNumber = GetParam();
	GuessResult result = game.guess(guessNumber);

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 2);
	EXPECT_EQ(result.balls, 0);
}

INSTANTIATE_TEST_CASE_P(
	Baseball2Strikes0BallFixtures,
	Baseball2Strikes0BallFixture,
	::testing::Values(
		"125", "143", "523"
	)
);

class Baseball1Strikes2BallFixture : public BaseballFixture {};

TEST_P(Baseball1Strikes2BallFixture, ReturnUnSolvedResult1Strikes2Balls) {
	string guessNumber = GetParam();
	GuessResult result = game.guess(guessNumber);

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(result.strikes, 1);
	EXPECT_EQ(result.balls, 2);
}

INSTANTIATE_TEST_CASE_P(
	Baseball1Strikes2BallFixtures,
	Baseball1Strikes2BallFixture,
	::testing::Values(
		"132", "321", "213"
	)
);

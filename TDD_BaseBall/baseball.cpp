#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	explicit Baseball(const string& question)
		: _question(question)
	{
	}

private:
	string _question;

public:
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == _question) {
			return { true, 3, 0 };
		}

		GuessResult result{ false, 0, 0 };
		for (int idx = 0; idx < 3; idx++) {
			char guessChar = guessNumber[idx];
			if (isInQuestion(guessChar) == false) continue;
			if (isStrike(guessChar, idx)) result.strikes++;
			else result.balls++;
		}
		return result;
	}

	bool isInQuestion(const char guessChar) {
		return _question.find(guessChar) != string::npos;
	}

	bool isStrike(const char guessChar, int index) {
		return _question[index] == guessChar;
	}

	void assertIllegalArgument(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}

	bool isDuplicatedNumber(const std::string& guessNumber) {
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
};

#include <stdexcept>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const std::string& question) : question(question) {}

	bool isDuplicatedNumber(const std::string& guessNumber) {
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const std::string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Input length must be 3 characters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Input must contain only digits.");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Input must not contain duplicate digits.");
		}
	}

	void countStrikes(const std::string& guessNumber) {
		for (int i = 0; i < 3; ++i) {
			if (guessNumber[i] == question[i]) {
				result.strikes++;
			}
		}
	}

	void countBalls(const std::string& guessNumber) {
		for (int i = 0; i < 3; ++i) {
			if (guessNumber[i] == question[(i + 1) % 3] || guessNumber[i] == question[(i + 2) % 3]) {
				result.balls++;
			}
		}
	}

	void checkResult() {
		if (result.strikes < 3)	result.solved = false;
		else result.solved = true;
	}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		countStrikes(guessNumber);
		countBalls(guessNumber);
		checkResult();
		return result;
	}

private:
	string question;
	GuessResult result{ false, 0, 0 };
};
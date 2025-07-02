#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if (guessNumber.length() !=  3) {
			throw length_error("Input length must be 3 characters.");
		}

		for (char ch : guessNumber) {
			if (ch < '0' || ch > '9') {
				throw invalid_argument("Input must contain only digits.");
			}
		}

		if (guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2]) {
			throw invalid_argument("Input must not contain duplicate digits.");
		}
	}
};
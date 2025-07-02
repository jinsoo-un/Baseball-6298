#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& string) {
		if (string.length() !=  3) {
			throw length_error("Input length must be 3 characters.");
		}
	}
};
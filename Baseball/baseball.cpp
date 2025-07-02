#include <stdexcept>
using namespace std;

class Baseball {
public:
	void guess(const string& string) {
		throw length_error("Input length must be 3 characters.");
	}
};
#include <iostream>
#include <string>
using namespace std;

struct Ladder {
	Ladder() { cout << "Empty"; };
	explicit Ladder(double l) : length(l) { cout << "length = " << l << "\n"; }
	// virtual void fold() = 0;
	double length;
	// virtual ~Ladder() = default;
};

struct StepLadder : Ladder {
	using Ladder::Ladder;
	// void fold() override { length /= sections; };
	double sections = 3;
};

int main() {
	StepLadder stepladder(4);
	// stepladder.fold();
	cout << stepladder.length;

	return 0;
}
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int diamondSize;
	int numColumns;
	cout << "Please enter a positive integer!:" << endl;
	cin >> diamondSize;
	if (diamondSize <= 0 || diamondSize)
	numColumns = (diamondSize * 2) - 1;
	for (int i = -(diamondSize - 1); i < diamondSize; i++) {
		for (int j = 0; j < abs(i); j++) {
			cout << " ";
		}
		for (int k = 0; k < numColumns - (2*abs(i)); k++) {
			cout << "#";
		}
		cout << endl;
	}
	return 0;
}

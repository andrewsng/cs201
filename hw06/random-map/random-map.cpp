#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>


using std::cout;
using std::endl;


int main()
{
	std::random_device rd;

	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	cout << "Randomly-chosen mean is " << mean << endl;

	std::seed_seq seed2{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
	std::mt19937 e2(seed2);
	std::normal_distribution<> normal_dist(mean, 2);

	std::map<int, int> hist;
	for (int i = 0; i < 10000; ++i) {
		++hist[std::round(normal_dist(e2))];
	}
	for (auto p : hist) {
		std::cout << std::setw(2)
			<< p.first << ' ' << std::string(p.second / 200, '*') << '\n';
	}
}
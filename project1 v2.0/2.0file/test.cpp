#include <utility>
#include <iostream>
using namespace std;

int main () {
	map<int, double> map;
	map.insert(make_pair(4, 5.3));
	map.insert(make_pair(6, 6));
	map.insert(make_pair(5, 8.0));
	map.insert(make_pair(9, 1.1));
	map.insert(make_pair(1, 3.4));
	for (const auto &i : map) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <utility>
#include <cmath>
#include <map>
#include "polynomial.h"
#include "func.h"
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;
extern int count;
extern map<string, polynomial> m0;
extern polynomial temp1;
extern polynomial temp2;



ostream& operator<<(ostream& out, const polynomial &a) {
	if (!a.map0.size()) {
		return out;
	}
	auto i = a.map0.crbegin();
	if (i->second != 0) {
		if ((i->second != 1 && i->second != -1) || i->first == 0) {
			out << i->second;
		}
		if (i->second == -1 && i->first != 0) {
			out << "-";
		}
		if (i->first != 0) {
			out << "x^" << i->first;
		}
	}
	i++;
	for (; i != a.map0.crend(); i++) {
		if (i->second == 0) {
			continue;
		}
		if (i->second > 0) {
			out << "+";
		}
		if ((i->second != 1 && i->second != -1) || i->first == 0) {
			out << i->second;
		}
		if (i->second == -1 && i->first != 0) {
			out << "-";
		}
		if (i->first != 0) {
			out << "x^" << i->first;
		}
	}
	return out;
}
//friend string insert(const string s);

polynomial polynomial::operator+(const polynomial &other)const {

	// for (int i = -100; i < 100; i++) {
	// 	if (map0.find(i) != map0.cend() && map0.find(i)->second != 0) {
	// 		a.map0[i] += map0.find(i)->second;
	// 	}
	// 	if (other.map0.find(i) != other.map0.cend() && other.map0.find(i)->second != 0) {
	// 		a.map0[i] += other.map0.find(i)->second;
	// 	}
	// }


	polynomial a;
	for (auto i : map0) {
		if (i.second != 0) {
			a.map0[i.first] += i.second;
		}		
	}
	for (auto i : other.map0) {
		if (i.second != 0) {
			a.map0[i.first] += i.second;
		}		
	}
	for (auto i : a.map0) {
		if (i.second == 0) {
			a.map0.erase(i.first);
		}
	}
	return a;
	//the polynomial zhishu is on more than 100
}

polynomial polynomial::operator-(const polynomial &other)const {
	// polynomial a;
	// for (int i = -100; i < 100; i++) {
	// 	if (map0.find(i) != map0.cend() && map0.find(i)->second != 0) {
	// 		a.map0[i] += map0.find(i)->second;
	// 	}
	// 	if (other.map0.find(i) != other.map0.cend() && other.map0.find(i)->second != 0) {
	// 		a.map0[i] -= other.map0.find(i)->second;
	// 	}
	// }

	polynomial a;
	for (auto i : map0) {
		if (i.second != 0) {
			a.map0[i.first] += i.second;
		}		
	}
	for (auto i : other.map0) {
		if (i.second != 0) {
			a.map0[i.first] -= i.second;
		}		
	}
	for (auto i : a.map0) {
		if (i.second == 0) {
			a.map0.erase(i.first);
		}
	}
	return a;
}

polynomial polynomial::operator*(const polynomial &other)const {
	polynomial a;
	for (auto i : map0) {
		for (auto j : other.map0) {
			a.map0[i.first + j.first] += i.second*j.second;
		}
	}
	for (auto i : a.map0) {
		if (i.second == 0) {
			a.map0.erase(i.first);
		}
	}
	return a;
}

bool polynomial::operator==(const polynomial &other)const {
	for (int i = -100; i < 100; i++) {
		if (map0.find(i) == map0.cend() && other.map0.find(i) != other.map0.end()) {
			if (other.map0.find(i)->second) {
				return 0;
			}
		} else if (map0.find(i) != map0.cend() && other.map0.find(i) == other.map0.end()) {
			if (map0.find(i)->second) {
				return 0;
			}
		} else if (map0.find(i) != map0.cend() && other.map0.find(i) != other.map0.end()) {
			if (map0.find(i)->second - other.map0.find(i)->second != 0) {
				return 0;
			}
		}
	}
	return 1;
}

polynomial polynomial::derivative()const {
	polynomial a;
	for (auto i : map0) {
		if (i.first) {
			a.map0[i.first-1] += i.first*i.second;
		}
	}
	for (auto i : a.map0) {
		if (i.second == 0) {
			a.map0.erase(i.first);
		}
	}
	return a;
}

double polynomial::evaluate(const double number)const {
	double count = 0;
	long long int bet = 0;
	for (auto i : map0) {
		bet = pow(number,i.first);
		count += i.second*bet;
	}
	return count;
}



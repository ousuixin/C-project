#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <utility>
#include <cmath>
#include <map>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;
extern int count;

class polynomial {
	friend ostream& operator<<(ostream& out, const polynomial &a);
	friend void insert0(const string s1, const string s2);
	friend void write_in(void);
	friend void place_in_file(void);
private:
	map<double, double> map0;
	//the first double is zhishu the double is xishu
public:
	polynomial() {};
	polynomial(map<double, double> map0) {
		this->map0 = map0;
	};
	polynomial(const polynomial &other) {
		this->map0 = other.map0;
	};
	void operator=(const polynomial &other) {
		this->map0 = other.map0;
	};
	polynomial operator+(const polynomial &other)const;
	polynomial operator-(const polynomial &other)const;
	polynomial operator*(const polynomial &other)const;
	bool operator==(const polynomial &other)const;
	polynomial derivative()const;
	double evaluate(double number) const;
};

extern map<string, polynomial> m0;
extern polynomial temp1;
extern polynomial temp2;

ostream& operator<<(ostream& out, const polynomial &a);
void insert0(const string s1, const string s2);
void write_in(void);
void place_in_file(void);
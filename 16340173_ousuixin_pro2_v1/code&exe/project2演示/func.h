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
extern map<string, polynomial> m0;
extern polynomial temp1;
extern polynomial temp2;
//---------------------------------------------
int choose_function(void);

void print_function(void);
//---------------------------------------------


//---------------------------------------------
bool is_name(const string name);
bool is_formula(const string formula);
bool is_name1(const string name);
bool is_formula1(const string formula);
string input_and_check(const int num);

string insert1(string s);
//----------------------------
int input_polynomial(void);

int add(void);

int subtract(void);

int multiply(void);

int take_derivative(void);

int evaluate_polynomial(void);

int judge_two_polynomial(void);

void show_polynomial(void);

int find_polynomial(void);

//-------------------------------------------


//-------------------------------------------
void write_in(void);

void place_in_file(void);
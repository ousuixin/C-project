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
#include "polynomial.h"
#include "func.h"
using namespace std;
extern int count;
extern map<string, polynomial> m0;
extern polynomial temp1;
extern polynomial temp2;

//--------------------------------------------------------------------------------------------------------------------
int choose_function(void) {
	string s = input_and_check(1); 	
	if (s == "Q")
		return 1;
	//choose function
	if (s[0] == '0') {
		return 0;
//(0)exit programe;
	} else if (s[0] == '1') {
		cout << "~~ How many polynomials do you want to input ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input one polynomial everytime with the form like 'name = (1,2)(1,0)'" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			if (input_polynomial()) {
				return 1;
			}
		}
//(1)input polynomials;
	} else if (s[0] == '2') {		
		cout << "~~ How many sets of polynomials do you want to add ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input two polynomials, and one polynomial everyline!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			if (add()) {
				return 1;
			}
		}
//(2)add;
	} else if (s[0] == '3') {		
		cout << "~~ How many sets of polynomials do you want to subtract ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input two polynomials, and one polynomial everyline!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			if (subtract()) {
				return 1;
			}
		}
//(3)sub;
	} else if (s[0] == '4') {
		cout << "~~ How many sets of polynomials do you want to multiply ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input two polynomials, and one polynomial everyline!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			if (multiply()) {
				return 1;
			}
		}
//(4)multiple;
	} else if (s[0] == '5') {		
		cout << "~~ How many polynomials do you want to take derivative ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input one polynomial everytime!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			if (take_derivative()) {
				return 1;
			}
		}
//(5)take derivative;
	} else if (s[0] == '6') {	
		cout << "~~ How many polynomials do you want to evaluate ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input one polynomial and one number in two line everytime!" << endl;
			cout << "~~ The form of polynomial should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			if (evaluate_polynomial()) {
				return 1;
			}
		}
//(6)evaluate polynomial;
	} else if (s[0] == '7') {
		cout << "~~ How many sets of polynomials do you want to judge ?" << endl;
		int number = 0;
		string s = input_and_check(2); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		for (int i = 0; i < number; i++) {
			cout << "~~ Please input two polynomials, and one polynomial everyline!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			if (judge_two_polynomial()) {
				return 1;
			}
		}
//(7)judge_two_polynomial;
	} else if (s[0] == '8') {
		cout << "~~ How many polynomials do you want to see ?" << endl;
		cout << "~~ And you can input '-1' to show all polynomials stored." << endl;
		int number = 0;
		string s = input_and_check(3); 
		if (s == "Q")
			return 1;
		stringstream ss;
		ss << s;
		ss >> number;	
		if (number == -1) {
			if (m0.size() <= 2) {
				cout << "~~ There is no polynomial yet." << endl;
			} else {
				show_polynomial();
			}
		} else {
			for (int i = 0; i < number; i++) {
				cout << "~~ Please input the name of polynomial you want to see." << endl;
				if (find_polynomial()) {
					return 1;
				}
			}
		}
//(8)show_polynomial;
	}
	return 1;
}


void print_function(void) {
	cout << "#####" << "#####" << "####################"
		 << "#####" << "#####" << "####################" << endl;
	cout << "##   " << "     " << "(0).Exit The Calculator       " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(1).Input Polynomial(s)       " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(2).Add Two Polynomials       " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(3).Subtract Two Polynomials  " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(4).Multiply Two Polynomials  " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(5).Take The Derivative       " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(6).Evaluate The Polynomial   " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(7).Judge Two Polynomials     " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(8).Show Polynomial(s) Filed  " 
		 << "     " << "     " << "     " << "   ##" << endl;
	cout << "#####" << "#####" << "####################"
		 << "#####" << "#####" << "####################" << endl;
}
//--------------------------------------------------------------------------------------------------------------------




//--------------------------------------------------------------------------------------------------------------------
string input_and_check(const int num) {
	while (1) {
		//input
        cout << "$$ ";
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        if (ss.str() == "") {
            continue;
        } else if (ss.str() == "Q") {
	        cout << "~~ Go back to the menu!" << endl;
        	return s;
        }
        //check the input acccording to the case
        if (num == 1) {
        	ss >> s;
			if (!(s[0] >= '0'&&s[0] <= '8'&&s.size()==1) || ss >> s) {
				cout << "~~ Your input is error, please only input a right number from 0 to 8!"
			     	 << endl;
			} else {
				return s;
			}
//(1)when num == 1, we check whether the num between 0-8 is right
        } else if (num == 2) {
        	int number = 0;
    	    if (ss >> number) {
	    	    if (ss >> s || number < 0) {
    		        cout << "~~ Your input is error, please only input a right number >= 0!"
    		             << endl;
    	    	} else {
    	    		ss << number;
    	    		ss >> s;
    	    		return s;
    	    	}
    	    } else {
    	    	cout << "~~ Your input is error, please input a number!" << endl;
    	    }
//(2)when num == 2, we check whether the num>=0 is right
        } else if (num == 3) {
        	int number = 0;
    	    if (ss >> number) {
	    	    if (ss >> s || number < -1) {
    		        cout << "~~ Your input is error, please only input a right number >= -1!"
    		             << endl;
    	    	} else {
    	    		ss << number;
    	    		ss >> s;
    	    		return s;
    	    	}
    	    } else {
    	    	cout << "~~ Your input is error, please input a number!" << endl;
    	    }
//(3)when num == 3, we check whether the num(num>=-1) is right
        } else if (num == 4) {
        	string s0 = s;
			string name;
        	ss >> name;
        	if (ss >> s) {
        		if (is_name(name)) {
        			if (s == "="&&ss >> s) {
        				if (is_formula(s)) {
        					return s0;
        				}
        			} else {
						cout << "~~ Please input a right polynomial in a line!" << endl;
						cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
						cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
						cout << "~~ Or you can just input the name of a polynomial stored." << endl;
						cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;       				
        			}
        		}
        	} else if (name[0] != '(') {
        		if (is_name(name)) {
        			return s0;
        		}
        	} else if (name[0] == '(') {
				if (is_formula(name)) {
					return s0;
				}
        	}
//(4)when num == 4, we check whether the input is like p = (2.4,1)(1,0) or (2,1)(1,0)
        } else if (num == 5) {
        	string s0 = s;
			string name;
        	ss >> name;
        	if (ss >> s) {
        		if (is_name1(name)) {
        			if (s == "="&&ss >> s) {
        				if (is_formula1(s)) {
        					return s0;
        				}
        			} else {
						cout << "~~ Please input a right polynomial in a line!" << endl;
						cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
						cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;  				
        			}
        		}
        	} else {
				cout << "~~ Please input a right polynomial in a line in the right form!" << endl;
				cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
				cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl; 
        	}
//(5)when num == 5, we check whether the input is like p = (2.4,1)(1,0)
        } else if (num == 6) {
        	double number = 0;
    	    if (ss >> number) {
	    	    if (ss >> s) {
    		        cout << "~~ Your input is error, please only input a right number(the type could be double)!"
    		             << endl;
    	    	} else {
    	    		ss << number;
    	    		ss >> s;
    	    		return s;
    	    	}
    	    } else {
    	    	cout << "~~ Your input is error, please input a number(the type could be double)!" << endl;
    	    }        	
//(6)when num == 6, we check whether the double num(num is any thing) is right
        } else if (num == 7) {
            ss >> s;
            if (s[1] || ss >> s || (s[0] != 'y'&&s[0] != 'n')) {
                cout << "~~ Your input is error, please only input y/n!"
                     << endl;
            } else {
            	return s;
            }
//(6)when num == 7, we check whether the input is y/n;
        } else if (num == 8) {
        	string name;
        	ss >> name;
        	if (ss >> s) {
 				cout << "~~ Your input is error, Please enter only one name in a line!" << endl;
        	} else {
        		int ret = 0;
				for (int i = 0; i < name.size(); ++i) {  
					if (i == 1&&name.size() >= 10) {
						cout << "~~ Your input is error, the name'letter should be no more than 10!" << endl;
						ret = 1;
						break;
					}
					if (name[i] > 'z' || name[i] < 'a') {
						cout << "~~ Your input is error, a name should only have lower-case letter." << endl; 
						ret = 1;
						break;
					}
				}
				if (!ret) {
					return name;
				}
        	}
        }
//(6)when num == 6, we check whether string is right
    } 
}

bool is_name(const string name) {
	for (int i = 0; i < name.size(); ++i) {  
		if (i == 1&&name.size() >= 10) {
			cout << "~~ Your input is error, the name'letter should be no more than 10!" << endl;
			cout << "~~ Please input a right polynomial in a line!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			return 0;
		}
		if (name[i] > 'z' || name[i] < 'a') {
			cout << "~~ Your input is error, a name should only have lower-case letter." << endl; 
			cout << "~~ Please input a right polynomial in a line!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			cout << "~~ Or you can just input the name of a polynomial stored." << endl;
			cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
			return 0;
		}
	}
	return 1;
}

bool is_formula(const string formula) {
	stringstream ss;
	ss << formula;
	int ret = 0;
	char c = 0;
	double number = 0;
	while (ss >> c) {
		if (!(c == '('&&ss >> number&&ss >> c && c == ','&&ss >> number&&ss >> c&&c == ')')) {
			ret = 1;
			break;
		}
	}
	if (ret) {
		cout << "~~ Your input is error, please input the right one!" << endl;
		cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
		cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
		cout << "~~ Or you can just input the name of a polynomial stored." << endl;
		cout << "~~ You can also just input the formula of a polynomial in the form like (1,2)(1,0)" << endl;
		return 0;
	} else {
		return 1;
	}
}


bool is_name1(const string name) {
	for (int i = 0; i < name.size(); ++i) {  
		if (i == 1&&name.size() >= 10) {
			cout << "~~ Your input is error, the name'letter should be no more than 10!" << endl;
			cout << "~~ Please input a right polynomial in a line!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			return 0;
		}
		if (name[i] > 'z' || name[i] < 'a') {
			cout << "~~ Your input is error, a name should only have lower-case letter." << endl; 
			cout << "~~ Please input a right polynomial in a line!" << endl;
			cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
			cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
			return 0;
		}
	}
	return 1;
}

bool is_formula1(const string formula) {
	stringstream ss;
	ss << formula;
	int ret = 0;
	char c = 0;
	double number = 0;
	while (ss >> c) {
		if (!(c == '('&&ss >> number&&ss >> c && c == ','&&ss >> number&&ss >> c&&c == ')')) {
			ret = 1;
			break;
		}
	}
	if (ret) {
		cout << "~~ Your input is error, please input the right one!" << endl;
		cout << "~~ The form should be like 'name = (1,2)(1,0)'," << endl;
		cout << "~~ the 'name', the '=' and the formula are separated by space, and there are no space in other place." << endl;
		return 0;
	} else {
		return 1;
	}
}

void insert0(const string name, const string formula) {
	polynomial temp;
	stringstream ss;
	ss << formula;
	char c = 0;
	double number1 = 0, number2 = 0;
	while (ss >> c) {
		ss >> number1;
		ss >> c;
		ss >> number2;
		ss >> c;
		temp.map0[number2] += number1;
	}
	m0[name] = temp;
}

string insert1(string s) {
	stringstream ss;
	ss << s;
	string name;
	ss >> name;
	string formula;
	if (ss >> s) {
		ss >> formula;
		if (m0.find(name) != m0.cend()) {
			cout << "~~ There is a polynomial named " << name << " before, do you want to cover it ?" << endl;
			cout << "~~ Please input y/n to represent yes/no." << endl;
			string s = input_and_check(7);  
			if (s == "Q")
				return s;
			if (s == "y") {
				insert0(name, formula);
			} else if (s == "n") {
				cout << "~~ Please input a new polynomial." << endl;
				s = "";
				return s;
			}
		} else {
			insert0(name, formula);
		}
//the style like p = (2,1)(1,0)
	} else if (name[0]=='(') {
//cout << "cuo" << endl;
		formula = name;
		if (count % 2) {
			name = "TEMP1";
			insert0("TEMP1", formula);
		} else {
			name = "TEMP2";
			insert0("TEMP2", formula);
		}
		count++;
		return name;
//the style like (2,1)(1,0)
	} else {
		if (m0.find(name) == m0.cend()) {
			cout << "~~ There is no such polynomial named " << name << "." << endl;
			cout << "~~ Please input a right one!" << endl;
			s = "";
			return s;
		}
	}
	return name;
}


//void insert0(const string name, const string formula)

//--------------------------------------------------------------------------------------------------------------------




//--------------------------------------------------------------------------------------------------------------------



int input_polynomial(void) {
	string s = input_and_check(5);
	if (s == "Q")
		return 1;
	string s0 = insert1(s);
	if (s0 == "Q")
		return 1;
	while (s0 == "") {
		s = input_and_check(5);
		if (s == "Q")
			return 1;
		s0 = insert1(s);
		if (s0 == "Q")
			return 1;
	}
	cout << "~~ Store successfully!" << endl;

	return 0;
}

int add(void) {
	string s = input_and_check(4);
	if (s == "Q")
		return 1;
//cout << s << endl;
	string name1 = insert1(s);
	if (name1 == "Q")
		return 1;
	while (name1 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name1 = insert1(s);
		if (name1 == "Q")
			return 1;
	}

//cout << m0[name1] << endl;

	s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name2 = insert1(s);
	if (name2 == "Q")
		return 1;
	while (name2 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name2 = insert1(s);
		if (name2 == "Q")
			return 1;
	}
	cout << "~~ "<< name1 << " + " << name2 << " = " << m0[name1]+m0[name2] << endl;
	cout << "~~ Do you want to store it ? Please input y/n to represent yes/no." << endl;
	s = input_and_check(7);
	if (s == "Q")
		return 1;
	if (s == "y") {
		cout << "~~ Please input the name of it, the name should be consist of lower-case letter, and the size is under 10." << endl;
		while (1) {
			string name = input_and_check(8);
			if (name == "Q")
				return 1;
			if (m0.find(name) != m0.cend()) {
				cout << "~~ There is a polynomial named " << name << " before, do you want to cover it ?" << endl;
				cout << "~~ Please input y/n to represent yes/no." << endl;
				string s = input_and_check(7); 
				if (s == "Q")
					return 1;
				if (s == "y") {
					m0[name] = m0[name1]+m0[name2];
					break;
				} else if (s == "n") {
					cout << "~~ Please input a new polynomial." << endl;
					continue;
				}
			} else {
				m0[name] = m0[name1]+m0[name2];
				break;
			}
		}
	} 
	return 0;
}

int subtract(void) {
	string s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name1 = insert1(s);
	if (name1 == "Q")
		return 1;
	while (name1 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name1 = insert1(s);
		if (name1 == "Q")
			return 1;
	}
	s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name2 = insert1(s);
	if (name2 == "Q")
		return 1;
	while (name2 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name2 = insert1(s);
		if (name2 == "Q")
			return 1;
	}
	cout << "~~ " << name1 << " - " << name2 << " = " << m0[name1]-m0[name2] << endl;
	cout << "~~ Do you want to store it ? Please input y/n to represent yes/no." << endl;
	s = input_and_check(7);
	if (s == "Q")
		return 1;
	if (s == "y") {
		cout << "~~ Please input the name of it, the name should be consist of lower-case letter, and the size is under 10." << endl;
		while (1) {
			string name = input_and_check(8);
			if (name == "Q")
				return 1;
			if (m0.find(name) != m0.cend()) {
				cout << "~~ There is a polynomial named " << name << " before, do you want to cover it ?" << endl;
				cout << "~~ Please input y/n to represent yes/no." << endl;
				string s = input_and_check(7);  
				if (s == "Q")
					return 1;
				if (s == "y") {
					m0[name] = m0[name1]-m0[name2];
					break;
				} else if (s == "n") {
					cout << "~~ Please input a new polynomial." << endl;
					continue;
				}
			} else {
				m0[name] = m0[name1]-m0[name2];
				break;
			}
		}
	} 
	return 0;
}

int multiply(void) {
	string s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name1 = insert1(s);
	if (name1 == "Q")
		return 1;
	while (name1 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name1 = insert1(s);
		if (name1 == "Q")
			return 1;
	}
	s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name2 = insert1(s);
	if (name2 == "Q")
		return 1;
	while (name2 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name2 = insert1(s);
		if (name2 == "Q")
			return 1;
	}
	cout << "~~ " << name1 << " * " << name2 << " = " << m0[name1]*m0[name2] << endl;
	cout << "~~ Do you want to store it ? Please input y/n to represent yes/no." << endl;
	s = input_and_check(7);
	if (s == "Q")
		return 1;
	if (s == "y") {
		cout << "~~ Please input the name of it, the name should be consist of lower-case letter, and the size is under 10." << endl;
		while (1) {
			string name = input_and_check(8);
			if (name == "Q")
				return 1;
			if (m0.find(name) != m0.cend()) {
				cout << "~~ There is a polynomial named " << name << " before, do you want to cover it ?" << endl;
				cout << "~~ Please input y/n to represent yes/no." << endl;
				string s = input_and_check(7);  
				if (s == "Q")
					return 1;
				if (s == "y") {
					m0[name] = m0[name1]*m0[name2];
					break;
				} else if (s == "n") {
					cout << "~~ Please input a new polynomial." << endl;
					continue;
				}
			} else {
				m0[name] = m0[name1]*m0[name2];
				break;
			}
		}
	} 
	return 0;
}

int take_derivative(void) {
	string s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name = insert1(s);
	if (name == "Q")
		return 1;
	while (name == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name = insert1(s);
		if (name == "Q")
			return 1;
	}
	string name0 = name;
	cout << "~~ (" << m0[name] << ")' = " << m0[name].derivative() << endl;//i dont know whether the polyniimial will be destructed already
	cout << "~~ Do you want to store it ? Please input y/n to represent yes/no." << endl;
	s = input_and_check(7);
	if (s == "Q")
		return 1;
	if (s == "y") {
		cout << "~~ Please input the name of it, the name should be consist of lower-case letter, and the size is under 10." << endl;
		while (1) {
			string name = input_and_check(8);
			if (name == "Q")
				return 1;
			if (m0.find(name) != m0.cend()) {
				cout << "~~ There is a polynomial named " << name << " before, do you want to cover it ?" << endl;
				cout << "~~ Please input y/n to represent yes/no." << endl;
				string s = input_and_check(7);  
				if (s == "Q")
					return 1;
				if (s == "y") {
					m0[name] = m0[name0].derivative();
					break;
				} else if (s == "n") {
					cout << "~~ Please input a new polynomial." << endl;
					continue;
				}
			} else {
				m0[name] = m0[name0].derivative();
				break;
			}
		}
	} 
	return 0;
}

int evaluate_polynomial(void) {
	string s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name = insert1(s);
	if (name == "Q")
		return 1;
	while (name == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name = insert1(s);
		if (name == "Q")
			return 1;
	}
	s = input_and_check(6); 
	if (s == "Q")
		return 1;
	double number;
	stringstream ss;
	ss << s;
	ss >> number;	
	cout << "~~ " << m0[name] << " = " << m0[name].evaluate(number) << " when x = " << number << "." << endl;
	return 0;
}

int judge_two_polynomial(void) {
	string s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name1 = insert1(s);
	if (name1 == "Q")
		return 1;
	while (name1 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name1 = insert1(s);
		if (name1 == "Q")
			return 1;
	}
	s = input_and_check(4);
	if (s == "Q")
		return 1;
	string name2 = insert1(s);
	if (name2 == "Q")
		return 1;
	while (name2 == "") {
		s = input_and_check(4);
		if (s == "Q")
			return 1;
		name2 = insert1(s);
		if (name2 == "Q")
			return 1;
	}
	if (m0[name1]==m0[name2]) {
		cout << "~~ The two polynomials are equal." << endl;
	} else {
		cout << "~~ The two polynomials are different." << endl;
	}
	return 0;
}

void show_polynomial(void) {
	cout << "~~ All the polynomial stored are as follow :" << endl;
	for (const auto &i : m0) {
		if (i.first != "TEMP1" && i.first != "TEMP2") {
			cout << "~~ " << i.first << " = " << i.second << endl;
		}
	}
//the polynomial should not has more than 10 xiang
}

int find_polynomial(void) {
	string s = input_and_check(8);
	if (s == "Q")
		return 1;
	if (m0.find(s) == m0.end()) {
		cout << "~~ There is no such polynomials!" << endl;
	} else {
		cout << "~~ " << m0.find(s)->first << " = " << m0.find(s)->second << endl;
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------------------





// //--------------------------------------------------------------------------------------------------------------------
// void write_in(void) {
// 	ifstream fin;
// 	fin.open("Storehouse");
// 	string s;
// 	while (!fin.eof()) {
// 		getline(fin, s);
// 		if (s == "") {
// 			continue;
// 		}
// 		string name;
// 		polynomial a;
// 		double first = 0, second = 0;
// 		stringstream ss;
// 		ss << s;
// 		ss >> name;
// 		while (ss >> first >> second) {
// 			a.map0[first] += second;
// 		}
// 		m0[name] = a;
// 	}
// 	fin.close();
// }

// void place_in_file(void) {
// 	ofstream fout;
// 	fout.open("Storehouse");
// 	if (m0.size() > 2) {
// 		for (auto i : m0) {
// 			if (i.first != "TEMP1" && i.first != "TEMP2" && i.second.map0.size()) {
// 			 	fout << i.first << " ";
// 				for (auto j = i.second.map0.crbegin(); j != i.second.map0.crend(); j++) {
// 					if (j->second == 0) {
// 						continue;
// 					}
// 					fout << j->first << " " << j->second << " ";
// 				}
// 				fout << endl;
// 			}
// 		}
// 	}
// 	fout.close();
// } 
// //--------------------------------------------------------------------------------------------------------------------


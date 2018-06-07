#ifndef A_H
#define A_H
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
using namespace std;

#define MAX 12//表示一天最多十二节课

class Class;
class person;
class student;
class teacher;
class edu_administrator;

extern int staff_num;
extern int teacher_num;
extern int stu_num;
extern string staff_prove;
extern string teacher_prove;
extern string stu_prove;

string input_check(int n);
int is_conflict(string time, vector<Class> v);

class system
{
    friend class person;
    friend class student;
    friend class teacher;
    friend class edu_administrator;
public:
    void print_func();
    string login();
    string register0();
    person& load(string s1);
    void add_member(int num);
    void write_in();
    void place_in_file();
private:
    vector<class Class> c_all;
    vector<class student> s_all;
    vector<class teacher> t_all;
    vector<class edu_administrator> e_all;
};

extern class system sysu;

struct Class
{
    string name;
    string time;
    string place;
    int score;//每个学期的
    string teacher_name;
    int max_capacity;
    int stu_num;
    string statu;
};

class person
{
    friend class system;
public:
    virtual void print_func() {};
    virtual int select_func() {};
    void change_password(string s);
    void change_username(string s);
    void list_all();
    void find_by_classname(string name);
    void find_by_tchname(string name);
protected:
    string idname;
    string username;
    string password;
    string identity;
};

class student : public person
{
    friend class system;
    friend class teacher;
    friend class edu_administrator;
public:
    void print_func ();
    int select_func();
    void list_myclass();
    void shield_conflict();
    void shield_full();
    void select_class(string name);
    void delete_class(string name);
private:
    vector <class Class> myclass;
};

class teacher : public person
{
    friend class system;
    friend class student;
    friend class edu_administrator;
public:
    void print_func ();
    int select_func();
    void list_myclass();
    void open_class(Class a);
    void delete_class(Class a);
private:
    vector <class Class> have_opened;
    vector <class Class> to_be_review;
};

class edu_administrator : public person
{
    friend class system;
    friend class student;
    friend class teacher;
public:
    void print_func ();
    int select_func();
    void show_need_review();
    void approve_class(Class a);
    void disapprove_class(Class a);
public:
    vector <class Class> to_be_review;
};

#endif


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "system.h"
using namespace std;

void system::print_func() {
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
    cout << "##   " << "     " << "(0).Exit The System           " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(1).Login The System          " << "     " << "     " << "     " << "   ##" << endl;
    cout << "##   " << "     " << "(2).Register The System       " << "     " << "     " << "     " << "   ##" << endl;
    cout << "#####" << "#####" << "####################" << "#####" << "#####" << "####################" << endl;
}

void system::write_in() {
//写入所有课程信息：
    ifstream fin("../data/class_data");
    while (!fin.eof()) {
        Class a;
        if (fin >> a.teacher_name >> a.name >> a.time >> a.place >> a.score >> a.max_capacity >> a.stu_num) {
            a.statu = "approved";
            c_all.push_back(a);  
        }
    }
    fin.close();
//写入系统信息：
    fin.open("../data/system_data");
    fin >> staff_num >> teacher_num >> stu_num >> staff_prove >> teacher_prove >> stu_prove;
    fin.close();
//以下是分别写入教务员，老师，学生的信息：
{
    stringstream ss;  int num;
//教务员
    ss << staff_num;  ss >> num;
    for (int i = num; i > 100; --i)
    {
        edu_administrator temp; Class a;
        string s;   
        ss.clear(); ss.str("");
        ss << "../data/person_data/";
        ss << i;    ss >> s; 
        fin.open(s);
        fin >> temp.idname >> temp.password >> temp.username >> temp.identity;
        while (!fin.eof()) {
            if (fin >> a.teacher_name >> a.name >> a.time >> a.place >> a.score >> a.statu >> a.max_capacity >> a.stu_num) {
                temp.to_be_review.push_back(a);
            }
        }
        e_all.push_back(temp);
        fin.close();
    }
//老师
    ss.clear(); ss.str("");
    ss << teacher_num;  ss >> num;
    for (int i = num; i > 200; --i)
    {
        teacher temp; Class a;
        string s;   
        ss.clear(); ss.str("");
        ss << "../data/person_data/";
        ss << i;    ss >> s; 
        fin.open(s);
        fin >> temp.idname >> temp.password >> temp.username >> temp.identity;
        while (!fin.eof()) {
            if (fin >> a.name >> a.time >> a.place >> a.score >> a.statu >> a.max_capacity >> a.stu_num) {
                a.teacher_name = temp.username;
                if (a.statu == "approved")
                {
                    temp.have_opened.push_back(a);
                } else {
                    temp.to_be_review.push_back(a);
                }
            }
        }
        t_all.push_back(temp);
        fin.close();
    }
//学生
    ss.clear(); ss.str("");
    ss << stu_num;  ss >> num;
    for (int i = num; i > 300; --i)
    {
        student temp; Class a;
        string s;   
        ss.clear(); ss.str("");
        ss << "../data/person_data/";
        ss << i;    ss >> s; 
        fin.open(s);
        fin >> temp.idname >> temp.password >> temp.username >> temp.identity;
        while (!fin.eof()) {
            if (fin >> a.teacher_name >> a.name >> a.time >> a.place >> a.score >> a.max_capacity >> a.stu_num) {
                temp.myclass.push_back(a);
            }
        }
        s_all.push_back(temp);
        fin.close();
    }
}
};


string system::login() {
    cout << "## Please input your id." << endl;
    string s = input_check(4);  
    stringstream ss;
    if (s == "Q") return s;
    ss << "../data/person_data/" << s;
    ss >> s;
    fstream _file;     
    _file.open(s, ios::in);  
    if (!_file) {
        _file.close();
        cout << "## You are not a user before!" << endl;
        return "Q";
    }

    string idname, password, username, identity;
    _file >> idname >> password >> username >> identity;
    _file.close();
    cout << "## Please input your password." << endl;
    s = input_check(4);  
    if (s == "Q") return s;
    if (s == password) {
        cout << "## Login successfully!" << endl;
    } else {
        cout << "## Your password is wrong! So let's go to the start." << endl;
        return "Q";
    }
    return idname;
};

person& system::load(string s1) {
    vector<person>::iterator a;
    for (auto temp0 = s_all.begin(); temp0 != s_all.end(); temp0++) {
        if (temp0->idname == s1) {
            return *temp0;
        }
    }

    for (auto temp0 = t_all.begin(); temp0 != t_all.end(); temp0++) {
        if (temp0->idname == s1) {
            cout << "## As a teacher, I suggest you changing your username after you register,(at least before you open any class)," << endl;
            cout << "## Or there will be some bad things to happen!" << endl;
            cout << "## And you should not change your username after the first changing as a teacher!" << endl;
            return *temp0;
        }
    }

    for (auto temp0 = e_all.begin(); temp0 != e_all.end(); temp0++) {
        if (temp0->idname == s1) {
            return *temp0;
        }
    }        
    return *a;
};

string system::register0() {
    cout << "## Please input the code to prove your identity." << endl;
    stringstream ss;
    string s = input_check(4);
    if (s == "Q") return s;
    if (s == staff_prove) {
        ++staff_num;    ss << staff_num;
        add_member(staff_num);
    } else if (s == teacher_prove) {
        ++teacher_num;  ss << teacher_num;
        add_member(teacher_num);
    } else if (s == stu_prove) {
        ++stu_num;  ss << stu_num;
        add_member(stu_num);
    } else {
        cout << "## Your code are wrong. So let's go to the start." << endl;
        return "Q";
    }
    ss >> s;
    return s;
};

void system::add_member(int num) {
    fstream _file;
    cout << "## Register successfully!" << endl;
    cout << "## All of your id, password and username is " << num << endl;
    cout << "## Please remember them, and you can change your username and password later." << endl;
    stringstream ss;    string s;
    ss << "../data/person_data/" << num;
    ss >> s;   
    ss.clear(); ss.str("");
    _file.open(s.c_str(), ios::out);
    _file << num << " " << num << " " << num << " ";
    ss << num << " " << num << " " << num << " ";
    if (num > 300) {
        _file << "student" << endl;
        student temp;
        ss >> temp.idname >> temp.password >> temp.username;
        temp.identity = "student"; 
        s_all.push_back(temp);
    } else if (num > 200) {
        _file << "teacher" << endl;
        teacher temp;
        ss >> temp.idname >> temp.password >> temp.username;
        temp.identity = "teacher"; 
        t_all.push_back(temp);
    } else {
        _file << "staff" << endl;
        edu_administrator temp;
        ss >> temp.idname >> temp.password >> temp.username;
        temp.identity = "staff"; 
        e_all.push_back(temp);
    }
}

void system::place_in_file() {
//保存所有课程信息：
    ofstream fout("../data/class_data");
    for (auto a = c_all.begin(); a != c_all.end(); a++) {
        fout << a->teacher_name << " " << a->name << " " << a->time << " "
             << a->place << " " << a->score << " " << a->max_capacity << " " << a->stu_num << endl;
    }
    fout.close();

//保存系统信息：
    fout.open("../data/system_data");
    fout << staff_num << " " << teacher_num << " " << stu_num << "\n"
         << staff_prove << " " << teacher_prove << " " << stu_prove << endl;
    fout.close();

//以下是分别保存教务员，老师，学生的信息：
{
    stringstream ss;    string s;
//教务员
    for (auto temp = e_all.begin(); temp != e_all.end(); ++temp) {
        ss.clear(); ss.str("");
        ss << "../data/person_data/" << temp->idname;
        ss >> s;
        fout.open(s);
        fout << temp->idname << " " << temp->password << " " << temp->username << " " << temp->identity << endl;
        for (auto a = temp->to_be_review.begin(); a != temp->to_be_review.end(); a++) {
            fout << a->teacher_name << " " << a->name << " " << a->time << " "
                 << a->place << " " << a->score << " " << a->statu << " " << a->max_capacity << " "
                 << a->stu_num << endl;
        }
        fout.close();
    }
//老师
    for (auto temp = t_all.begin(); temp != t_all.end(); ++temp) {
        ss.clear(); ss.str("");
        ss << "../data/person_data/" << temp->idname;
        ss >> s;
        fout.open(s);
        fout << temp->idname << " " << temp->password << " " << temp->username << " " << temp->identity << endl;
        for (auto a = temp->have_opened.begin(); a != temp->have_opened.end(); a++) {
            fout << a->name << " " << a->time << " " << a->place << " "
                 << a->score << " " << a->statu << " " << a->max_capacity << " " << a->stu_num << endl;
        }
        for (auto a = temp->to_be_review.begin(); a != temp->to_be_review.end(); a++) {
            fout << a->name << " " << a->time << " " << a->place << " "
                 << a->score << " " << a->statu << " " << a->max_capacity << " " << a->stu_num << endl;
        }        
        fout.close();
    }
//学生
    for (auto temp = s_all.begin(); temp != s_all.end(); ++temp) {
        ss.clear(); ss.str("");
        ss << "../data/person_data/" << temp->idname;
        ss >> s;
        fout.open(s);
        fout << temp->idname << " " << temp->password << " " << temp->username << " " << temp->identity << endl;
        for (auto a = temp->myclass.begin(); a != temp->myclass.end(); a++) {
            fout << a->teacher_name << " " << a->name << " " << a->time << " "
                 << a->place << " " << a->score << " " << a->max_capacity << " " << a->stu_num << endl;
        }
        fout.close();
    }
}
};


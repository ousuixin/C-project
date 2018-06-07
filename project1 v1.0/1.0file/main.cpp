#include <iostream>
#include <fstream> 
#include "func.h" 
using namespace std; 


//一些说明：
//-----------------------------------------------------------------------------------------------------
//在所有的程序打印的交互语句前都有“~~ ”表示这一句是程序打印；
//在所有的用户输入前都"$$ "表示这是用户输入的；
//-----------------------------------------------------------------------------------------------------



//以下全局变量都是因为在多个函数中反复出现，所以为了方便定义了全局变量.
//---------------------------------------------------------------------------------------------------- 
//用来表示现在已经有的用户数目 
int txt_num = 0;
//这是用于串联整个仓库里面的货物的头指针； 
Goods *head = NULL;
//这个变量用于辅助判断，当从仓库中查找货物失败，函数返回这个默认构造的变量表示货物查找失败； 
Goods empty;
//这个密码是出厂设置，一开始就有，管理员注册以后，可以进行更改； 
string Password;
//用于判断用户是不是manager，以此判断用户可以进行哪些操作；
int ret = 0; 
//作为记录当前用户操作的文件，向这个文件流输入用户操作可以把用户操作保存到一个文件；
fstream _FILE;
//这个是用户ID 
string id;
//----------------------------------------------------------------------------------------------------




int main () {
    //(1)读档处理环节
    //文件00是用来保存仓库库存的，每次运行程序都要重新将内容写入程序，每次退出程序都需要将内写回文，
    //故在开始将内容写入程序
    //文件0是用来保存密码和总用户数的，每次运行程序都要重新将内容写入程序，每次更改密码都需要将内写回文件
    //故在开始将密码和总用户数重置
    write_back();


    //(2)程序运行环节
    //用于存储输入的用户选项
    char key = 0;
    //（2.1）登陆或注册环节
    //一开始需要登陆,如果之前已经是用户，可以直接输入ID使用仓库功能.
    //如果是管理员，可以追加输入密码来进行管理员操作；如果之前不是用户或忘记ID，则可以进行注册； 
    cout << "~~ Did you have an ID before?" << endl;
    cout << "~~ Input y/n to represent yes/no, "
         << "or input q to quit." << endl;
    while (1) {
        //之所以会有一句cout<<"$$ ";是为了表示这后面是用户输入内容，每个cin前都有，后续的不予以说明了；
        cout << "$$ ";
        cin >> key;
        while (cin.fail()) {
            cout << "~~ Your input is error, please enter the right one!"
                 << endl;
            cin.clear();
            cin.ignore(100,'\n');
            cout << "$$ ";
            cin >> key;
        }
        //如果之前已经是用户:
        if (key == 'y') {
        //首先输入ID 
            cout << "~~ Please enter your id." << endl;
            cout << "$$ ";
            cin >> id;
            //这个变量用于判断该用户是否是用户并且已经有过相关操作并存档，是存储该用户操作记录的文件的文件名； 
            fstream _file;     
            _file.open(id, ios::in);  
            if (!_file) {
                cout << "~~ You are not the user before!"
                     << " So let' go to the start!" << endl;
                cout << "~~ Did you have an ID before?" << endl;
                cout << "~~ Input y/n to represent yes/no, "
                     << "or input q to quit." << endl;
                _file.close();
                continue;
            }
            // 无论是不是manager都打开记录该用户操作的文件（没有就创建，有就打开
            //注意这个函数与前一个open函数的区别，这个函数：如果没有该文件，则创建，前一个函数不会创建一个新文件，据说是因为这个函数接受const char*，前一个接受string，是不同的
            //这里_FILE全局文件流用来写入用户操作历史记录
            _FILE.open(id.c_str(), ios::app);
            //如果是manager，再输入密码，是manager，ret记为1，返回真，如果不是manager，也返回真，但ret记为0，进入操作环节；
            //(ret是用来表示用户是不是manager的全局变量)
            if (is_manager()) {
                break;
            }
        } else if (key == 'n') {
            //如果之前不是用户或忘记ID，则可以进行注册:
            cout << "~~ Do you want to register ?" << endl;
            cout << "~~ Input y/n to represent yes/no, "
                 << "or input q to quit." << endl;
            int rem = 0;//用来记录manager的跳出循环
            while (1) {
                cout << "$$ ";
                cin >> key;
                while (cin.fail()) {
                    cout << "~~ Your input is error, please enter the right one!"
                         << endl;
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout << "$$ ";
                    cin >> key;
                }            
                if (key == 'y') {
                    cout << "~~ Register seccessfully!" << "\n"
                         << "~~ Now, you are one of the user!"
                         << " Your id is " << ++txt_num << "."
                         << endl;
                    //这里的txtnum是表示用户总数的全局变量，根据这个来产生某一用户专有的文件名
                    stringstream ss;
                    ss << txt_num;
                    id = ss.str();
                    // 无论是不是manager都打开记录该用户操作的文件（_FILE全局文件流用）
                    _FILE.open(id.c_str(), ios::out);
                    if (is_manager()) {
                        rem = 1;
                        break;
                    }
                } else if (key == 'n'||'q') {
                    cout << "Bye!" << endl;
                    return 0;
                } else {
                    cout << "~~ Your input is error! Please enter the right one!" << endl;
               }
            }
            if (rem)
                break;
        } else if (key == 'q'){
            cout << "~~ Bye!" << endl;
            return 0;
        } else {
            cout << "~~ Your input is error! Please enter the right one!" << endl;
        }
    }


    //(2.2)操作环节
    //登陆成功以后，用户可以进行操作： 
    cout << "~~ Dear number(" << id << ')' << ", what do you want to do ?" 
         << "In this storehouse, you can :" << endl;
    //打印仓库功能
    print_function();
    cout << "~~ Please enter the numbers to perform "
            "the corresponding operations." << endl;
    //用户输入在choose函数里面选择0时返回0，表示退出,之后存档，结束程序，正常执行功能返回1，继续选择
    while (choose_function()) {
        cout << "~~ What else do you want to do?" << endl;
        print_function();
    }


    //（3）程序即将结束，存档环节
    //更改密码和总用户数都需要将内写回文件
    //保存关闭程序时仓库的存储情况，以免退出程序后数据丢失
    Place_on_file();

    return 0;
}




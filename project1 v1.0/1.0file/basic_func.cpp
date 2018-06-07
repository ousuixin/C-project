#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream> 
#include "func.h"
using namespace std;




//关于交互信息的函数：
//-----------------------------------------------------------------------------------------------------

//询问用户是不是管理员并审核，如果是manager，返回真且ret全局变量置为1，表示表示manager，不是manager返回真且ret=0，否则输入错误，返回假，要求重新输入
//不管是不是manager都可以成功登陆，并且打开一个名为ID的文件（如果之前没有这个文件就新建一个）
bool is_manager(void) {
	char key = 0;
	//不是那个全局变量Password!!!（首字母大写了）,用来存储用户输入的密码
	string password;
    cout << "~~ Are you the managers ?" << "\n"
    	 << "~~ Input y/n to represent yes/no, " << endl;
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
		cout << "~~ Please enter the password:" << endl;
		for (int i = 2; i >= 0; --i) {
			cout << "$$ ";
			cin >> password;
			//这里Password是全局变量，与用户输入的password比较
			if (password != Password) {
				cout << "~~ Your password is wrong, you have " << i
					 << " chance(s) left." << endl;;
			} else {
				break;
			}
		}
		cout << "~~ Login seccessfully!" << endl;
		if (password != Password) {
			cout << "~~ But your password is wrong, so maybe you are not the manager." << endl;
		} else {
			cout << "~~ Now you are a manager!" << endl;
			ret = 1;
		}
		return 1;
	} else if (key == 'n') {
		ret = 0;
		cout << "~~ Login seccessfully!" << endl;
		return 1;
	} else {
		cout << "~~ Your input is error! Please enter the right one ."  
			 << endl;
		continue;
	}
}
}


//这个函数可以打印该仓库系统的功能
int print_function() {
	cout << "#####" << "#####" << "###############"
		 << "#####" << "#####" << "###############" << endl;
	cout << "##   " << "     " << "(0).Exit the program          " 
		 << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(1).Show The Goods List       " 
		 << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(2).Search For Specific Goods " 
		 << "     " << "   ##" << endl;
	if (!ret) {
		cout << "#####" << "#####" << "###############"
			 << "#####" << "#####" << "###############" << endl;
		return 0; 
	}
	cout << "##   " << "     " << "(3).Add Some Goods            " 
		 << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(4).Take Out Specific Goods   " 
		 << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(5).Change Price Of Goods     " 
		 << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(6).Change Password           " 
		 << "     " << "   ##" << endl;
	cout << "##   " << "     " << "(7).Open A User's _FILE       " 
		 << "     " << "   ##" << endl;
	cout << "#####" << "#####" << "###############"
		 << "#####" << "#####" << "###############" << endl;
}






//根据用户所选数字确定对应的用户想要的功能
int choose_function() {

	string name;
	int count = 0, number = 0;
	double prime_costs = 0, selling_price = 0;

	cout << "$$ ";
	//根据数字选择功能
	cin >> number;
	//首先检查输入流是否正常（防止非法输入字符串之类）,正常则继续，否则重新输入
	while (cin.fail()) {
		cout << "~~ Your input is error, please enter the right one!"
		     << endl;
		cin.clear();
		cin.ignore(100,'\n');
		cout << "$$ ";
		cin >> number;
	}
	cin.ignore(100,'\n');

	//此处表示如果用户不是管理员（！ret）且输入了除了前两个操作以外的操作对应的数字，则报错
	if (number != 1 && number != 2 && number != 0 && !ret) {
		cout << "~~ Your input is error, please enter the right one!"
		     << endl;
		choose_function();
		return 1;
	}//不知道我这里是复制上面的检测流代码还是应该用递归调用？

	//根据数字选择对应操作
//(1)
	if (number == 0) {
		return 0;
		//表示整个程序结束，之后存档，结束
	} else if (number == 1) {
		show_goods();
		//_FILE为全局文件流，打开该用户专属文件，此处向其中输入用户进行操作的时间,该用户执行的操作(后续不再说明——FILE)
		_FILE << "~~ " << get_time() << endl;
		_FILE << "Ask for list all goods." << endl;
//(2)
	} else if (number == 2) {
		cout << "~~ How many Goods do you want to find?" << endl;
		cout << "$$ ";
		int num = 0;
		cin >> num;
		while (cin.fail()) {
			cout << "~~ Your input is error, please enter the right one!"
			     << endl;
			cin.clear();
			cin.ignore(100,'\n');
			cout << "$$ ";
			cin >> num;
		}
		if (num) {
			cout << "~~ Please input names of the goods. "
				 << endl;
		}
		for (int i = 0; i < num; i++) {
			cout << "$$ ";
			cin >> name;
			//这个ptr记录根据名字找到的商品（指针）
			Goods *ptr = find_goods(name);
			if (ptr->count != 0) {
				cout << "~~ There are " << ptr->count << " " 
					 << ptr->name << " left in the storehouse."
				 	 << endl;
				cout << "~~ The selling price of it is " << ptr->selling_price << '.'
					 << endl;
				_FILE << "~~ " << get_time() << endl;
				_FILE << "Ask for find goods named " << name 
				     << ", there are " << ptr->count << " " 
					 << ptr->name << " left in the storehouse." << "\n"
					 << "The selling price of it is " << ptr->selling_price << '.'
					 << endl;
				if (ret) {
					cout << "~~ The prinme price of it is " << ptr->prime_costs << '.'
						 << endl;	
					_FILE << "~~ " << get_time() << endl;
					_FILE << "The prinme price of it is " << ptr->prime_costs << '.'
						  << endl;	
				} 
				ptr = NULL;
			} else {
				cout << "~~ There is no such goods named " << name << "."
			    	 << endl;
				_FILE << "~~ " << get_time() << endl;
				_FILE << "Ask for find goods named " << name 
					 << ", but there is no such goods."
					 << endl;		    
			}
		}
		//这里可以清除缓冲区多余的东西，防止过度输入导致后续错误
		//***重要：所以，每次要求输入，都只允许输入那么多，多余的忽略
//(3)
	} else if (number == 3) {
		cout << "~~ How many Goods do you want to add?" << endl;
		cout << "$$ ";
		int num = 0;
		cin >> num;
		while (cin.fail()) {
			cout << "~~ Your input is error, please enter the right one!"
			     << endl;
			cin.clear();
			cin.ignore(100,'\n');
			cout << "$$ ";
			cin >> num;
		}
		for (int i = 0; i < num; ++i) {
			cout << "~~ Please input name numbers, prime_costs, and selling_price of the goods."
				 << endl;
			cout << "$$ ";
			cin >> name >> count >> prime_costs >> selling_price;
			//检测输入流
			while (cin.fail()) {
				cout << "~~ Your input is error, please enter the right one!"
				     << endl;
				cin.clear();
				cin.ignore(100,'\n');
				cout << "$$ ";
				cin >> name >> count >> prime_costs >> selling_price;
			}
			add_goods(name, count, prime_costs, selling_price);
			cout << "~~ Add goods seccessfully!" << endl;
			_FILE << "~~ " << get_time() << endl;
			_FILE << "Add "<< count << " goods named " << name 
				 << ", the prime_costs of one is " << prime_costs 
				 << ", the prime_costs of one is set to " << selling_price 
				 << '.' << endl; 
		}
//(4)
	} else if (number == 4) {
		cout << "~~ How many Goods do you want to take out?" << endl;
		cout << "$$ ";
		int num = 0;
		cin >> num;
		while (cin.fail()) {
			cout << "~~ Your input is error, please enter the right one!"
			     << endl;
			cin.clear();
			cin.ignore(100,'\n');
			cout << "$$ ";
			cin >> num;
			cin.ignore(100,'\n');
		}
		for (int i = 0; i < num; i++) {
			cout << "~~ Please input name and numbers of the goods."
				 << endl;
			cout << "$$ ";
			cin >> name >> count;
			//检测输入流
			while (cin.fail()) {
				cout << "~~ Your input is error, please enter the right one!"
				     << endl;
				cout << "$$ ";
				cin.clear();
				cin.ignore(100,'\n');
				cin >> name >> count;
				cin.ignore(100,'\n');
			}
			int count0 = delete_goods(name, count);
			if (!count0) {
				cout << "~~ There is no goods named " << name << '.'
					 << endl;
				_FILE << "~~ " << get_time() << endl;
				_FILE << "Ask for take out the goods named " << name
					 << ", but there is no such goods." << endl;
			} else if (count0 == 2) {
				cout << "~~ The number of goods named " << name << " is not enough ,"
					 << "so you can not take them out" << endl;
				_FILE << "~~ " << get_time() << endl;
				_FILE << "Ask for take out " << count << " goods named " << name
					 << ", but there is no enough such goods." << endl;
			} else {
				cout << "~~ Take goods seccessfully!" << endl;
				_FILE << "~~ " << get_time() << endl;
				_FILE << "Take out " << count << " goods named " << name
					 << '.' << endl;
			}
		}
//(5)
	} else if (number == 5) {
		cout << "~~ How many Goods do you want to set price?" << endl;
		cout << "$$ ";
		int num = 0;
		cin >> num;
		while (cin.fail()) {
			cout << "~~ Your input is error, please enter the right one!"
			     << endl;
			cin.clear();
			cin.ignore(100,'\n');
			cout << "$$ ";
			cin >> num;
			cin.ignore(100,'\n');
		}
		for (int i = 0; i < num; i++) {
			double price = 0;
			cout << "~~ Please enter the name of the goods and the price you want to set."
				 << endl;
			cout << "$$ ";
			cin >> name >> price;
			//检测输入流
			while (cin.fail()) {
				cout << "~~ Your input is error, please enter the right one!"
				     << endl;
				cout << "$$ ";
				cin.clear();
				cin.ignore(100,'\n');
				cin >> name >> price;
			}
			if (change_price(name, price)) {
				cout << "~~ Set price seccessfully!" << endl;
				_FILE << "~~ " << get_time() << endl;
				_FILE << "Set the price of " << name << " to " << price << '.' << endl;
			} else {
				cout << "~~ Set fail! There is no goods named " << name << '.'
					 << endl;
			}
		}
//(6)
	} else if (number == 6) {
		cout << "~~ Please enter the password you want." << endl;
		cout << "$$ ";
		string s;
		cin >> s; 
		change_password(s);
		cout << "~~ Set password seccessfully!" << endl;
		_FILE << "~~ " << get_time() << endl;
		_FILE << "Set the password to " << s << '.' << endl;		
//(7)
	} else if (number == 7) {
		cout << "~~ Please enter the id of the user whose operations history you want to see."
			 << endl;
		cout << "$$ ";
		string s;
		cin >> s;
		if (open_file(s)) {
			_FILE << "~~ " << get_time() << endl;
			_FILE << "Watch the operations history of " << s << '.' << endl;	
		} else {
			cout << "~~ There is no one whose id is " << s << '.' << endl;
		}
	} else {
		cout << "~~ Your input is error, please enter the right one!"
		     << endl;
		choose_function();
	}
	return 1;
	//选择程序正常退出，return0为退出整个程序
}






//基本函数
//我的仓库是通过链表实现添加，删除，查找，打印等一系列操作的，所以后面用到了全局变量头指针head，在此处说明后不再重申
//**重要：本来我想将find—goods返回的指针传进add，delete等函数，可以提高效率？但是考虑到给出的模板没有这样做，就算了
//-----------------------------------------------------------------------------------------------------
//进货，对应进货模块，表示当前进货一批数量为count的name商品
void add_goods(string name, int count, double prime_costs, double selling_price) {
	if ((find_goods(name))->count)
	{
		increase_count(name, count);
	} else {
		add_to_list(name, count, prime_costs, selling_price);
	}
}


//更新库存信息，对应增加库存子功能，对name商品新增count数量
void increase_count (string name, int count) {
	int count_before = (find_goods(name))->count;
	(find_goods(name))->count = count + count_before;
}


//更新库存列表，对应新增商品子功能，新增name商品且初始数量为count
void add_to_list(string name, int count, double prime_costs, double selling_price) {
	Goods *ptr = (Goods *)calloc(1,sizeof(Goods));
	ptr->next = NULL;
	ptr->count = count;
	ptr->name = name;
	ptr->prime_costs = prime_costs;
	ptr->selling_price = selling_price;
	if (head == NULL) {
		head = ptr;
	} else if (head->name > ptr->name) {		
		ptr->next = head;
		head = ptr;
	} else {
		Goods *current = head;
		while (current->next != NULL) {
			if (current->next->name > ptr->name) {
				ptr->next = current->next;
				current->next = ptr;
				break;
			}
			current = current->next;
		}
		if (current->next == NULL)
		{
			current->next = ptr;
		}
		current = NULL;
	}
	ptr = NULL;
}
	

//出货，对应出货模块，表示当前出货一批数量为count的name商品,返回真值表示成功取货，反之不成功
int delete_goods(string name, int count) {
	int count_before = find_goods(name)->count;
	if (count_before) {
		if (count_before > count) {
			decrease_count(name, count);
		} else if (count_before == count) {
			delete_from_list(name);
		} else {
			return 2;
		}
		return 1;
	} else {
		return 0;
	}
}


//更新库存信息，对应减少库存子功能，对name商品减少count数量
bool decrease_count(string name, int count) {
	int count_before = (find_goods(name))->count;
	((find_goods(name))->count) = count_before - count;
	return 1;
}


//更新库存列表，对应删除商品子功能，删除商品列表中name商品
bool delete_from_list(string name) {
	Goods *ptr = head;
	//这里find用于记录指向要删除的货物的指针，要将其中内容free；
	Goods *find = NULL;
	if (ptr->name == name) {
		head = ptr->next;
		free(ptr);
		ptr = NULL;
		return 1;
	}
	while (ptr->next != NULL) {
		if (ptr->next->name == name) {
			find = ptr->next;
			ptr->next = ptr->next->next;
			break;
		}
		ptr = ptr->next;
	}
	free(find);
	find = NULL;
	ptr = NULL;
	return 1;
}


//显示当前库存列表，包括商品名及其库存量
void show_goods() {
	Goods *current = head;
	int i = 1;
	if (ret) {
		cout << "#### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #####" << endl;
		cout << "##  GOODS_ID   GOODS_NAME        GOODS_NUMBERS   PRIME_COSTS   SELLING_PRICE  ##" << endl;
		for (; current != NULL; i++) {
			cout << "##  " << "(" << i << ")"
				 << "        " << left << setw(18) << current->name 
				 << setw(16) << current->count 
				 << setw(14) << current->prime_costs
				 << setw(15) << current->selling_price
				 << "##" << endl;
			current = current->next;
		}
		cout << "#### #### #### #### #### #### #### #### #### #### #### #### #### #### #### #####" << endl;
	} else {
		cout << "#### #### #### #### #### #### #### #### #### #### #### #### #####" << endl;
		cout << "##  GOODS_ID   GOODS_NAME        GOODS_NUMBERS   GOODS_PRICE   ##" << endl;
		for (; current != NULL; i++) {
			cout << "##  " << "(" << i << ")"
				 << "        " << left << setw(18) << current->name 
				 << setw(16) << current->count 
				 << setw(14) << current->selling_price
				 << "##" << endl;
			current = current->next;
		}
		cout << "#### #### #### #### #### #### #### #### #### #### #### #### #####" << endl;
	}
	cout << endl;
	cout << "~~ There are " << i-1 << " goods now." << "\n" << endl;
	current = NULL;
}


//查看仓库中的name商品的一系列参数，普通成员不可以看到成本价
Goods* find_goods(string name) {
	Goods *current = head;
	for (int i = 1; current != NULL; i++) {
		if (current->name == name) {
			return current;
		}
		current = current->next;
	}
	//这里的empty是用来表示没有查到这个商品，所以返回全局变量Goods empty，通过判断返回变量的count是否为零判断是否找到
	if (current == NULL)
	{
		if (empty.count)
		{
			empty.count = 0;
		}
		return &empty;
	}
}
//-----------------------------------------------------------------------------------------------------






//新增的用户操作函数：
//-----------------------------------------------------------------------------------------------------
//更改使用管理员权限的密码
void change_password(string password) {
	Password = password;
}


//管理员可以使用这个操作查看某一个用户的操作历史记录
int open_file(string id) {
	fstream fin;
	string s;
	fin.open(id, ios::in);
	if (fin) {
		while (getline(fin, s)) {
			cout << s << endl;
		}
		return 1;
	} else {
		return 0;
	}
}


//管理员可以根据商品名称进行修改商品售价:
int change_price(string name, double price) {
	Goods *ptr = find_goods(name);
	if (ptr->count != 0) {
		ptr->selling_price = price;
		ptr = NULL;
		return 1;
	}
	else {
		ptr == NULL;
		return 0; 
	}
}
//-----------------------------------------------------------------------------------------------------






//存档所有信心函数，包括密码信息，仓库信息，用户操作信息等等 
//-----------------------------------------------------------------------------------------------------
//每次运行程序都要重新将内容写入程序(包括密码信息，总用户数，仓库信息)
void write_back(void){
	
	ifstream fin("0");
    fin >> Password >> txt_num;
    fin.close();
	
	string name;
	int count = 0;
	double prime_costs = 0, selling_price = 0;
	fin.open("00");
	while (!fin.eof()) {
		fin >> name >> count >> prime_costs >> selling_price;
		if (count == 0)
			break;
		add_goods(name, count, prime_costs, selling_price);
		count = 0;
	}
	fin.close();
}


//保存密码，用户数。
//保存关闭程序时仓库的存储情况，以免退出程序后数据丢失
void Place_on_file(void){
	//保存密码，用户数。
	ofstream fout("0");
    fout << Password << "\n" << txt_num;
    fout.close();
    //保存关闭程序时仓库的存储情况
	Goods *current = head;
	fout.open("00");
	int i = 1;
	for (; current != NULL; i++) {
		fout << left << setw(18) << current->name 
			 << setw(16) << current->count 
			 << setw(14) << current->prime_costs
			 << setw(15) << current->selling_price << endl;
		current = current->next;
	} 
	current = NULL;
}


//这个函数可以向存储用户信息的文件写入时间信息,从而记录用户进行某一个操作的时间，，返回操作具体时间
string  get_time(void) {
	//查了一下，好像因为这里用的函数在是c++03的库，所以string不可以转char*，所以用了char*不用string
	time_t now_time= time(NULL);;
	char tmp[40];  
    strftime(tmp, sizeof(tmp), "%Y/%m/%d %X %A", localtime(&now_time));
    return tmp;
}
//-----------------------------------------------------------------------------------------------------

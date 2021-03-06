#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
//我尽量保存了模板的内容
//只是在类里面新增了几个变量，函数名，类名都没有改



//货物类----------------------------------------------------------------------------------- 
//name表示名称，count表示数量，prime_cost表示进价，selling_cost表示售价,count表示货物数量
//其中，管理员可以访问所有变量，并赋予所有变量初始值，并且可以在之后更改售价
//用户只能读取除了进价以外的数据，不能进行写操作
struct Goods {
	string name;
	int count = 0;
	double prime_costs = 0;
	double selling_price = 0;
	Goods *next = NULL;
};
//----------------------------------------------------------------------------------------- 





//全局变量的声明--------------------------------------------------------------------------- 
//用来表示现在已经有的用户数目 
extern int txt_num;
//用于判断用户是不是manager；
extern int ret;
//作为记录当前用户操作的文件
extern fstream _FILE;
//这个是用户ID 
extern string id;
//这个密码是出厂设置，一开始就有，管理员注册以后，可以进行更改； 
extern string Password;
//这是用于串联整个仓库里面的货物的头指针； 
extern Goods *head;
//这个变量用于辅助判断，当从仓库中查找货物失败，函数返回这个默认构造的变量表示货物查找失败； 
extern Goods empty;
//------------------------------------------------------------------------------------------ 




//关于交互信息的函数声明:
//------------------------------------------------------------------------------------------
//询问用户是不是管理员并审核，如果是manager，返回真且ret全局变量置为1，表示表示manager，不是manager返回真且ret=0，否则输入错误，返回假，要求重新输入
bool is_manager(void);

//打印该仓库系统的功能:
int print_function();

//根据用户所选数字确定对应的用户想要的功能
int choose_function();
//------------------------------------------------------------------------------------------






//基本函数声明
//------------------------------------------------------------------------------------------

//进货，对应进货模块，表示当前进货一批数量为count的name商品
void add_goods(string name, int count, double prime_costs, double selling_price);

//更新库存信息，对应增加库存子功能，对name商品新增count数量
void increase_count (string name, int count); 

//更新库存列表，对应新增商品子功能，新增name商品且初始数量为count
void add_to_list(string name, int count, double prime_costs, double selling_price); 
	
//出货，对应出货模块，表示当前出货一批数量为count的name商品，如果该货物不存在，返回0
//否则，返回1，表示成功取出
int delete_goods(string name, int count);

//更新库存信息，对应减少库存子功能，对name商品减少count数量
bool decrease_count(string name, int count);

//更新库存列表，对应删除商品子功能，删除商品列表中name商品，
bool delete_from_list(string name);

//显示当前库存列表，包括商品名及其库存量，成本价，售价；普通成员不可以看到成本价
void show_goods(); 

//查看仓库中的name商品的一系列参数，普通成员不可以看到成本价
Goods* find_goods(string name);
//-----------------------------------------------------------------------------------------






//新增的功能,总共有管理者函数和用户函数两部分:
//----------------------------------------------------------------------------------------

//管理者函数:
//-----------------------------------------------
//首先应该包括所有的basicfunction里面的函数:
//即add_goods,increase_count,add_to_list;
//和delete_goods,decrease_count,delete_from_list
//和show_goods,find_goods

//然后是新增的函数:
//修改仓库访问密码:
void change_password(string password);

//修改售价:根据商品名称进行修改:
int change_price(string name, double price);

//管理员查看所有用户操作（包括普通用户和管理员）
int open_file(string id);
//----------------------------------------------


//用户函数:
//----------------------------------------------
//首先应该包括:show_goods(),Goods* find_goods(string name);
//注意这个功能不同于管理者的查询函数,不可以看到进货价格
//----------------------------------------------------------------------------------------







//存档所有信息函数，包括密码信息，仓库信息，用户操作信息等等 
//----------------------------------------------------------------------------------------
//每次运行程序将之前保存的仓库信息，密码信息，用户数目写入程序
void write_back(void);

//这个函数用来保存关闭程序时仓库的存储情况，以免退出程序后数据丢失
//而对应的文件“00”，就是专门用来保存仓库信息的. 
void Place_on_file(void);

//这个函数可以向存储用户信息的文件写入时间信息,从而记录用户进行某一个操作的时间，返回操作具体时间
string get_time(void);

//本来应该有一个专们（不是我写错别字，是因为‘门’长得像‘内’了）根据用户的选择，向文件输出，记录用户操作的函数
//但是用户每个不同的操作，有不同的输入，而每个操作用户只输出一次，所以不适合把‘写向屏幕’和‘写向文件’的操作分成两个函数
//如果非要这么做，要么（1）要么需要传递很多变量，多分很多情况，要么（2）需要定义很多全局变量，
//所以干脆统一写在choose_function()里面了
//----------------------------------------------------------------------------------------







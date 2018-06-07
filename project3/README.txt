零、（一定要看我后面划重点的部分啊！！！！）
一、首先说明项目文件“code&exe”和“data”文件内容：
（0）所有文件最好在sublime编辑器下打开，否则可能有乱码（虽然我觉得，即使不看注解，我写的代码也能看懂）
（1）“data”文件夹的内容用于保存程序信息，必须和“code&exe”放在同一文件夹下编译运行，否则无法正常运行程序
（2）“code&exe”文件夹中，“a.out”是编译通过产生的可运行的程序；“main.cpp”是主函数文件；“system.h”是各种函数，
    全局变量声明；“system.cpp”是system类的实现；“person.cpp”是person类的实现；“edu_administrator.cpp”是教务员类的实现；
    “teacher.cpp”是teacher类的实现；“student.cpp”是student类的实现。
（3）“data”文件夹中，“class_data”文件保存了所有对学生开放的课程；
“system_data”文件夹中是系统信息，
！！！！！！！！！
		划重点：
		具体来讲，102，204，305分别表示
		从101到102是管理员id，当前一共两个管理员；从201到204是教师id，当前一共四个教师注册了；
		从301到305是学生id，当前一共有5个学生注册了；
		随着后续注册，对应点数据会增加，比如，一个管理员注册了，102会变成103；

		划重点：
		后面三个字符串分别代表：
		证明用户是教务员身份的“123456”；
		证明用户是老师身份的“223344”；
		证明用户是学生身份的“000000”
		这个东西是注册必须要用的“the code to prove your identity”，没有的话不能注册！
		（当然，这个东西可以手动更改）

		划重点：
		“person_data”文件夹下，是所有用户的信息，这个文件夹的文件名字都是id，比如，文件“101”表示id是101的教务员的文件信息；
		文件“201”表示id是201的老师的文件信息；文件“301”表示id是301的学生的文件信息；
		至于文件里面的具体信息：第一行数过来分别是person类的成员idname，password，username，identity；
		所以一开始登陆要输入的id和password就是这里的idname和password，也就是文件夹第一行的前两个数据；
		后续的每一行都是一个课程信息，组成person的子类的vecvtor<Class>成员的信息；

		划重点：
		关于使用：我已经事先载入了一些信息，所以可以不需要注册就可以使用，但是注册功能其实是可以用的。
！！！！！！！！!
二、代码运行环境：Linux下（g++编译）
三、功能：
将所有代码及程序文件和数据保存文件分别放在两个不同的文件夹中 
1. 文件存储功能：
当程序打开时， write_in （）打开数据文件并把文档中成员信息写入程序 （被写入程序的有：所有课程信息，所有用户信息） 
当程序结束的时候place_in_file（）把信息写回文件
 
2. 登陆 / 注册功能：
登陆：核对用户的id与密码是否相符合 
注册：需要用户提供相应的代码来确定用户的身份（是学生还是老师还是教务员） 审核通过以后注册成功 
（这里的代码就是前面说的system_data中的字符串）
  
3.person及其子类功能：
公共操作： 
更改用户名、密码（这个直接改，很简单） 
列出所有课程（这个直接遍历vector<Class> c_all 打印即可） 
查找相应课程（遍历vector，如果该课程name与输入相符，打印即可） 

差别操作： 
---------------------------------------------------------------------------------------------------------------------------------------
学生的： 
void list_myclass();列出自己的课程，遍历vector<Class>myclass 即可 
a．隐藏冲突课程---- void shield_conflict();这个函数通过比较class类的time信息来判断具体课程是否 与该学生的课程（myclass）的 time冲突，
如果冲突，就不打印该课程； 
b．隐藏满员课程---- void shield_full();如果某课程的最大容量等于当前学生人数（即 Class 类的 capacity==stu_num），就不打印该课程； 
c．选择课程void select_class(string name);即在该学生的vector<Class>myclass中加入这个课程并且 
所有相应的存有stu_num的数据都惊醒stu_num++的操作 
d．退课void delete_class(string name);即在该学生的vector<Class>myclass中删除（erase）这个课 程，
并且所有相应的存有stu_num的数据都惊醒stu_num--的操作 
---------------------------------------------------------------------------------------------------------------------------------------
老师的： 
a．列出课程void list_myclass(); 遍历vector <Class>have_opened和 vector <Class>to_be_review  即可 
b．开课void open_class(Class a); 定义一个Class对象，要求老师输入课程名称并且完善相应课程信息
到该对象，并且判断老师的课程是否存在重名、时间，地点冲突等问题。完成以后，将该对象插入到该老 师的vector <Class>to_be_review当中，
并且插入所有教务员的vector <Class>to_be_review中
c．删除课程void delete_class(Class a);  遍历vector <Class>have_opened和 vector <Class>to_be_review找到名字和对象a的名字相同的成 员，
删除该成员， 然后遍历所有教务员e_all的vector <Class>to_be_review和所有学生s_all的vector<Class>myclass， 找到同名的对象并删除；
--------------------------------------------------------------------------------------------------------------------------------------- 
教务员的： a．展示所有待审核课程void show_need_review(); 遍历该教务员的vector <Class>to_be_review 
b．通过某一课程的审核void approve_class(Class a); 遍历该教务员的vector <Class>to_be_review， 删除名字与对象相同的成员；
在全局的 c_all 中加入这个对象；遍历所有老师的 vector <Class>to_be_review，找到相同名字的成员并删除； 
c．将某一课程下架（可以让该课程不再对学生开放）void disapprove_class(Class a); 在所有教务员的 vector <Class>to_be_review 中加入这个对象，
stu_num 置为 0，表示这个对象需要重新审核；
把这个课程对应的老师的vector <Class>have_opened和 vector <Class>to_be_review分别减少和增加一个该对象，stu_num置为0；
遍历所有学生的vector<Class>myclass找到同名课程，删除掉； 
---------------------------------------------------------------------------------------------------------------------------------------
 

四、无QT
五、关于bug，应该是没有
六、关于库，只用了G++的库
七、关于注释详见代码
八、文件结构方面使用了8个文件：“a.out”是编译通过产生的可运行的程序；“main.cpp”是主函数文件；“system.h”是各种函数，
    全局变量声明；“system.cpp”是system类的实现；“person.cpp”是person类的实现；“edu_administrator.cpp”是教务员类的实现；
    “teacher.cpp”是teacher类的实现；“student.cpp”是student类的实现。
九、使用了文件存储，详情见代码

十、关于内存，应该没有泄漏，使用了valgrind检查后，无报错

十一、关于异常处理，做了的。





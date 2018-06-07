一、首先说明项目文件“代码&&可运行程序”文件内容：
（1）其目录下“Storehouse”文件用于保存程序信息，必须和其他六个文件放在同一文件下编译运行，否则无法正常运行程序
（2）文件“a.out”是编译通过产生的可运行的程序；“main.cpp”是主函数文件；“func.h”是各种函数，全局变量声明；
    “func.cpp”是各种函数的定义；“polynomial.h”是多项式类的申明；“polynomial.cpp”是多项式类的实现

二、代码运行环境：Linux下（g++编译）（注意编译选项加上-lm，因为使用了pow函数）

三、功能：
<1>基本功能全部实现；
（0）在任何时候能够返回主菜单界面
这是由string input_and_check(const int num)；实现的
（1）存储多项式
由int input_polynomial(void)；实现
（2）多项式加法
由int add（）；polynomial operator+(const polynomial &other)const;实现
（3）多项式减法
由int subtract(void);polynomial operator-(const polynomial &other)const;实现
（4）多项式求值
由int evaluate_polynomial(void);double polynomial：：evaluate(double number) const;实现
（5）查看现有的所有多项式
由void show_polynomial(void);实现
<2>附加功能：
可以实现的扩展功能：
（1）多项式与多项式相乘
由int multiply(void);polynomial operator*(const polynomial &other)const;实现
（2）判断两个多项式是否相等
由int judge_two_polynomial(void);bool polynomial：：operator==(const polynomial &other)const;实现
（3）对某个多项式求导
由int take_derivative(void);polynomial polynomial：：derivative()const;实现
自己实现的额外功能：
（1）根据名字查找特定多项式
由void show_polynomial(void);实现
（2）文档记录程序的多项式
由void place_in_file(void);实现存档
由void write_in(void);实现读档

四、无QT
五、关于bug，应该是没有
六、关于库，只用了G++的库
七、关于注释详见代码
八、文件结构方面使用了五个文件main.cpp，func.h，func.cpp，polynomial.h，polynomial.cpp
九、使用了文件存储，详情见代码

十、关于内存，没有泄漏，因为用的都是容器

十一、关于异常处理，用户理论上可以输入乱码，我的程序都可以报错并且提示，再要求重新输入

关于其他详情请见pdf及代码。










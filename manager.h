#pragma once
#include"identity.h"
#include"globalFile.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include<algorithm>
#include"computerroom.h"
using namespace std;
class Manager :public Identity
{
public:
	//构造函数
	Manager();

	Manager(string name, string pwd);

	//菜单界面
	virtual void I_menu();

	//添加账号
	void addacount();

	//初始化学生、教师容器
	void initvector();

	//初始化机房容器
	void cptrinitvector();

	//检测重复学生或教师
	bool checkrepeat(int id,int type);

	//查看账号
	void showacount();


	//查看机房信息
	void showinfo();

	//清空预约信息
	void allorder();

	//析构函数
	~Manager();

	//学生容器
	vector<Student> v_stu;

	//教师容器
	vector<Teacher> v_tea;

	//机房容器
	vector<Computerroom>v_cptr;
};
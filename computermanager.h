#pragma once
#include<iostream>
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;

class C_manager
{
public:
	//构造函数
	C_manager();

	//打印角色选择菜单
	void show_menu();

	//登录操作
	void loginin(string Filename, int type);

	//管理员操作功能
	void admin(Identity* &manager);

	//学生操作功能
	void student(Identity*& student);

	//教师操作功能
	void teacher(Identity*& teacher);

	////登录角色
	//template<class T>
	//void perlogin();

	////获取登录角色
	//Identity* getperson();

	//退出系统
	void exit_sys();

	//析构函数
	~C_manager();

	//父类指针
	Identity* person = NULL;
};
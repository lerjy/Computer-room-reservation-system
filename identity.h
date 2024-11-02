#pragma once
#include<iostream>
using namespace std;
#include<fstream>
class Identity
{
public:
	//操作菜单
	virtual void I_menu() = 0;
	//操作员姓名
	string m_name;
	//操作员密码
	string m_pwd;
};
#pragma once
#include"identity.h"
#include"orderfile.h"
class Teacher :public Identity
{
public:
	//构造函数
	Teacher();

	Teacher(int id,string name, string pwd);

	//菜单界面
	virtual void I_menu();

	//查看所有预约
	void allorder();

	//审核预约
	void validorder();

	//设置职工编号
	void setid(int id);

	//获取职工编号
	int getid()const;

	//析构函数
	~Teacher();

private:
	//职工编号
	int tea_id;
};
#pragma once
#include"identity.h"
#include <vector>
#include "computerroom.h"
#include "globalFile.h"
#include"orderfile.h"
#include"orderfile.h"

class Student :public Identity
{
public:

	//构造函数
	Student();

	Student(int id,string name, string pwd);

	//菜单界面
	virtual void I_menu();

	//初始化机房信息
	void initcptrvector();

	//申请预约
	void applyorder();

	//查看自身预约
	void myorder();

	//查看所有预约
	void allorder();

	//取消预约
	void celorder();

	//设置学号
	void setid(int id);

	//获取学号
	int getid()const;

	//析构函数
	~Student();

	//机房信息容器
	vector<Computerroom> v_cptr;

private:
	//学号
	int stu_id;
};
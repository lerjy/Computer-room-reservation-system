#pragma once
#include<iostream>
using namespace std;
#include<map>
#include<string>
#include"globalFile.h"
#include<fstream>

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//文件读取
	void readfile();

	//文件转型
	void trunfile(string str,map<string, string>& ma);

	//存放数据的容器
	map<int, map<string, string>> m_data;

	//更新容器数据
	void updateorder();

	//预约条数
	int m_size;

	//析构函数
	~OrderFile();

};
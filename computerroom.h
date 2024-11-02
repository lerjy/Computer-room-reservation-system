#pragma once
#include <iostream>
using namespace std;

//机房类
class Computerroom
{
public:
	//构造函数
	Computerroom();

	Computerroom(int id,int max);

	//析构函数
	~Computerroom();

public:
	int m_id;//机房id
	int m_max;//机房容量
};
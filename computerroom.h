#pragma once
#include <iostream>
using namespace std;

//������
class Computerroom
{
public:
	//���캯��
	Computerroom();

	Computerroom(int id,int max);

	//��������
	~Computerroom();

public:
	int m_id;//����id
	int m_max;//��������
};
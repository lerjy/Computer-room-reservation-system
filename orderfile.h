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
	//���캯��
	OrderFile();

	//�ļ���ȡ
	void readfile();

	//�ļ�ת��
	void trunfile(string str,map<string, string>& ma);

	//������ݵ�����
	map<int, map<string, string>> m_data;

	//������������
	void updateorder();

	//ԤԼ����
	int m_size;

	//��������
	~OrderFile();

};
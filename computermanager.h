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
	//���캯��
	C_manager();

	//��ӡ��ɫѡ��˵�
	void show_menu();

	//��¼����
	void loginin(string Filename, int type);

	//����Ա��������
	void admin(Identity* &manager);

	//ѧ����������
	void student(Identity*& student);

	//��ʦ��������
	void teacher(Identity*& teacher);

	////��¼��ɫ
	//template<class T>
	//void perlogin();

	////��ȡ��¼��ɫ
	//Identity* getperson();

	//�˳�ϵͳ
	void exit_sys();

	//��������
	~C_manager();

	//����ָ��
	Identity* person = NULL;
};
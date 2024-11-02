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
	//���캯��
	Manager();

	Manager(string name, string pwd);

	//�˵�����
	virtual void I_menu();

	//����˺�
	void addacount();

	//��ʼ��ѧ������ʦ����
	void initvector();

	//��ʼ����������
	void cptrinitvector();

	//����ظ�ѧ�����ʦ
	bool checkrepeat(int id,int type);

	//�鿴�˺�
	void showacount();


	//�鿴������Ϣ
	void showinfo();

	//���ԤԼ��Ϣ
	void allorder();

	//��������
	~Manager();

	//ѧ������
	vector<Student> v_stu;

	//��ʦ����
	vector<Teacher> v_tea;

	//��������
	vector<Computerroom>v_cptr;
};
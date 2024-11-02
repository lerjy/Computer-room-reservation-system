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

	//���캯��
	Student();

	Student(int id,string name, string pwd);

	//�˵�����
	virtual void I_menu();

	//��ʼ��������Ϣ
	void initcptrvector();

	//����ԤԼ
	void applyorder();

	//�鿴����ԤԼ
	void myorder();

	//�鿴����ԤԼ
	void allorder();

	//ȡ��ԤԼ
	void celorder();

	//����ѧ��
	void setid(int id);

	//��ȡѧ��
	int getid()const;

	//��������
	~Student();

	//������Ϣ����
	vector<Computerroom> v_cptr;

private:
	//ѧ��
	int stu_id;
};
#pragma once
#include"identity.h"
#include"orderfile.h"
class Teacher :public Identity
{
public:
	//���캯��
	Teacher();

	Teacher(int id,string name, string pwd);

	//�˵�����
	virtual void I_menu();

	//�鿴����ԤԼ
	void allorder();

	//���ԤԼ
	void validorder();

	//����ְ�����
	void setid(int id);

	//��ȡְ�����
	int getid()const;

	//��������
	~Teacher();

private:
	//ְ�����
	int tea_id;
};
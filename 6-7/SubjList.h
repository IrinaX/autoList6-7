#pragma once
#include "list.h"
#include "subj.h"
class SubjList : public List
{
public:

	void printMenu();

	Car* createNewCar();

	void print();

	void printItem(Car* pCar);

	void placeSort();//���������� ����������� �� ���������� ����

	void swipe(int i);//������ ������� ��������� �������� i � ���� ������� ������. ��� ���� ��� ����������

	//����� �� ������, ��������� � �����
	void search();

	void fillListTest();//���������� ��������� �������

	Car& operator[](int index); //������������� �������� ��������������

private:

};
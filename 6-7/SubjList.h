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

	void placeSort();//сортировка автомобилей по количеству мест

	void swipe(int i);//меняем местами указатели элемента i и того который справа. Это надо для сортировки

	//поиск по номеру, владельцу и цвету
	void search();

	void fillListTest();//заполнение тестовыми данными

	Car& operator[](int index); //перегруженный оператор индексирования

private:

};
/*
14. Элементы списка описывают следующие автомобили: легковой (тип кузова, тип двигателя, тип привода),
микроавтобус (тип двигателя, количество мест), автобус (тип двигателя, количество мест, грузоподъемность),
грузовой (тип двигателя, грузоподъемность), специальный (текстовое описание). Для автомобилей всех типов
также указывается: гос. номер, владелец, марка, модель, цвет. Необходимо реализовать сортировку автомобилей
по количеству мест и поиск по номеру, владельцу и цвету.
*/
//TODO: перегрузка > в сортировке, перегрузка == в поиске и перегрузка по типу


#include <iostream>
#include "list.h"
#include "subj.h"
#include "SubjList.h"
using namespace std;

int main()
{
	Car* car = new Car;
	SubjList* myList = new SubjList;
	int variant = 0;
	while (variant <= 11) {
		myList->printMenu();
		scanf_s("%d", &variant);
		switch (variant) {
		case 0: {
			myList->fillListTest();
			break;
		}
		case 1: { //добавление элемента в хвост
			car = myList->createNewCar();
			myList->addItem((Item*)car);
			cout << "\nItem was added successfully!" << endl;
			break;
		}
		case 2: {// показать список
			myList->print();
			break;
		}
		case 3: {// посчитать элементы
			int amountOfItems = myList->countItems();
			cout << "\namountOfItems = " << amountOfItems << endl;
			break;
		}
		case 4: {// вставить элемент
			if (myList->getHead()) {
				int index;
				Car* newCar = myList->createNewCar();
				cout << "\nEnter index of element:";
				cin >> index;
				myList->insertItem((Item*)newCar, index);
			}
			else {
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст
			}
			break;
		}
		case 5: {// получить элемент по индексу
			if (myList->getHead()) {
				int index = 0;
				cout << "\nEnter index of element:";
				cin >> index;
				Item* element = myList->getItem(index);
				if (element != 0) {
					myList->printItem((Car*)element);
				}
			}
			else {
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст

			}
			break;
		}
		case 6: {// получить индекс элемента по указателю
			if (myList->getHead()) {
				cout << "\nEnter item address (8 bit 0-9 A-F):";
				Item* listItem = new Item;
				scanf_s("%p", &listItem);
				int index = myList->getIndex(listItem);
				if (index > -1) {
					cout << "\nindex = " << index << endl;
				}
				else {
					cout << "\nElement doesn't exist." << endl;
				}
			}
			else {
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст

			}
			break;
		}
		case 7: {// вырезать элемент из списка
			if (myList->getHead()) {
				int index = 0;
				cout << "\nEnter index of element:";
				cin >> index;
				Item* removedElement = myList->removeItem(index);
				if (removedElement) {
					myList->printItem((Car*)removedElement);
				}
			}
			else {
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст

			}
			break;
		}
		case 8: {// удалить элемент из списка
			if (myList->getHead()) {
				int index = 0;
				cout << "\nEnter index of element:";
				cin >> index;
				myList->deleteItem(index);
			}
			else {
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст

			}
			break;
		}
		case 9: {// очистить список
			if (myList->getHead())
				myList->clear();
			else
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст

			break;
		}
		case 10: {//сортировка автомобилей по количеству мест
			if (myList->getHead()) {//если начальный эл-т отсутствует, то список пуст
				myList->placeSort();
				cout << "\nList was sorted successfully." << endl;
			}
			else {
				cout << "\nList is empty." << endl; //если начальный эл-т отсутствует, то список пуст
			}
			break;
		}
		case 11: {//поиск по номеру, владельцу и цвету
			myList->search();
			break;
		}
		case 12: {//Exit
			cout << "Exit..." << endl;
			if (myList) {
				myList->clear();
			}
			break;
		}
		default:
			break;
		}
	}
	return 0;
}

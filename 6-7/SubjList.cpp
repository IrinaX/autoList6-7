#include "SubjList.h"
#include <iostream>
using namespace std;

void SubjList::printMenu()
{
	cout << "\nWhat do you want to do?" << endl;
	cout << "0. Fill list with test data" << endl;
	cout << "1. Add item to tail" << endl;
	cout << "2. Show list" << endl;
	cout << "3. Count items" << endl;
	cout << "4. Insert item" << endl;
	cout << "5. Get item by index" << endl;
	cout << "6. Get index of item" << endl;
	cout << "7. Remove item by index" << endl;
	cout << "8. Delete item by index" << endl;
	cout << "9. Clear list" << endl;
	cout << "10. Sort list by place count" << endl;
	cout << "11. Search by state number, owner, color" << endl;
	cout << "12. Exit" << endl;
	cout << ">" << endl;
}

Car* SubjList::createNewCar()
{
	cout << "Choose car type: " << endl;    //тип авто
	cout << "1. PassengerCar" << endl;      //легковушка
	cout << "2. MicroBus" << endl;          //микроавтобус
	cout << "3. Bus" << endl;               //автобус
	cout << "4. Truck" << endl;             //грузовой
	cout << "5. Special" << endl;           //специальный
	int choice;
	cin >> choice;
	Car* pCreatedCar;
	switch (choice) {
	case 1: {
		pCreatedCar = new PassengerCar;
		break;
	}
	case 2: {
		pCreatedCar = new MicroBus;
		break;
	}
	case 3: {
		pCreatedCar = new Bus;
		break;
	}
	case 4: {
		pCreatedCar = new Truck;
		break;
	}
	case 5: {
		pCreatedCar = new Special;
		break;
	}
	default:
		cout << "Nothing selected." << endl;
		return nullptr;
	}
	pCreatedCar->input();
	return pCreatedCar;
}


void SubjList::print()
{
	if (this) {
		if (this->pHead) {
			int i = 0;
			cout << "\nList: " << this << "\thead: " << this->pHead << "\ttail: " << this->pTail << endl;
			for (Item* pItem = this->pHead; pItem != nullptr; pItem = pItem->pNext) {
				cout << "\nIndex: " << i << endl;
				cout << "Pointer: " << pItem << "\tprev: " << pItem->pPrev << "\tnext: " << pItem->pNext << endl;
				printItem((Car*)pItem);
				++i;
			}
		}
		else {
			cout << "\nList is empty." << endl;
		}
	}
	else {
		cout << "\nUndefined list. Func: void print()" << endl;
	}
}

void SubjList::printItem(Car* pCar)
{
	if (pCar)
	{
		pCar->print();
		return;
	}
		cout << "\nUndefined pCar (func: void printItem(Car *pCar))." << endl;
		
}

void SubjList::placeSort()
{
	int amount = countItems();
	if (amount == 0 || amount == 1)//если список пустой или в нем один элемент, не сортируем
	{
		cout << "\nList is empty or have only one object." << endl;
		return;
	}
	for (int i = 0; i < amount; ++i) {//сортируем методом пузырьковой сортировки
		for (int j = 0; j < amount - i - 1; ++j) {
			Car* currCar = &(*this)[j]; // использование оператора индексирования
			Car* nextCar = &(*this)[j + 1];
			MicroBus* currMicroBus = (MicroBus*)currCar;//MicroBus так как Bus наследуется от MicroBus
			MicroBus* nextMicroBus = (MicroBus*)nextCar;//MicroBus так как Bus наследуется от MicroBus
			//если у текущего микроавтобуса мест больше (перегруженный оператор сравнения одного объекта с другим объектом)
			if ((*currMicroBus) > (*nextMicroBus))
			{
				swipe(j);//меняем их местами
			}
		}
	}
}

void SubjList::swipe(int i)//меняем местами указатели элемента i и того который справа.
{
	Item* first = getItem(i);
	Item* second = first->pNext;
	Item* temp_prev = first->pPrev;

	if (first == this->pHead)
		this->pHead = second;

	if (second == this->pTail)
		this->pTail = first;

	if (first->pPrev != nullptr)
		first->pPrev->pNext = second;

	if (second->pNext != nullptr)
		second->pNext->pPrev = first;

	first->pNext = second->pNext;
	first->pPrev = second;

	second->pNext = first;
	second->pPrev = temp_prev;
}

void SubjList::search()//поиск по номеру, владельцу и цвету
{
	if (this)
		if (this->pHead) {
			int choice;
			cout << "\nChoose search type:" << endl;//Выберите тип поиска
			cout << "1. State number" << endl;//гос. номер
			cout << "2. Owner" << endl;//собственник
			cout << "3. Color" << endl;//цвет
			cin >> choice;
			char keyWord[30];
			int result = 0;
			switch (choice) {
			case 1: {
				cout << "\nEnter state number (max 9 symbols): ";
				cin >> keyWord;
				cout << endl;
				for (Item* pItem = this->pHead; pItem != nullptr; pItem = pItem->pNext) {
					//если гос. номер совпадает с введенным, то выводим на экран
					if ((*(Car*)pItem) == keyWord) {//перегруженный оператор эквивалентности со значением типа string
						printItem((Car*)pItem);
						cout << endl;
						result = 1;
					}
				}
				break;
			}
			case 2: {
				cout << "\nEnter owner (max 29 symbols): ";
				cin >> keyWord;
				cout << endl;
				for (Item* pItem = this->pHead; pItem != nullptr; pItem = pItem->pNext) {
					//если собственник совпадает с введенным, то выводим на экран
					if (((Car*)pItem)->owner == keyWord) {
						printItem((Car*)pItem);
						cout << endl;
						result = 1;
					}
				}
				break;
			}
			case 3: {
				cout << "\nEnter color (max 19 symbols): ";
				cin >> keyWord;
				cout << endl;
				for (Item* pItem = this->pHead; pItem != nullptr; pItem = pItem->pNext) {
					//если цвет совпадает с введенным, то выводим на экран
					if (((Car*)pItem)->color == keyWord) {
						printItem((Car*)pItem);
						cout << endl;
						result = 1;
					}
				}
				break;
			}
			default:
				break;
			}
			if (result == 0) {
				cout << "\nNo info found." << endl;
			}
		}
		else
			cout << "\nList is empty." << endl;
	else
		cout << "\nUndefined list. Func: void search()" << endl;
}

void SubjList::fillListTest()
{
	Car* pCar = new PassengerCar;
	pCar->number = "AM749A";
	pCar->owner = "Irina";
	pCar->brand = "KIA";
	pCar->model = "RIO";
	pCar->color = "white";
	((PassengerCar*)pCar)->engine = Engine::Gasoline;
	((PassengerCar*)pCar)->body = CarBody::Sedan;
	((PassengerCar*)pCar)->drive = Drive::Front;
	addItem((Item*)pCar);
	cout << "\nPassengerCar was added successfully!" << endl;

	pCar = new MicroBus;
	pCar->number = "QW720A";
	pCar->owner = "John";
	pCar->brand = "Mercedes";
	pCar->model = "Benz";
	pCar->color = "blue";
	((MicroBus*)pCar)->engine = Engine::Gasoline;
	(*(MicroBus*)pCar).placeCount = 10;
	addItem((Item*)pCar);
	cout << "\nMicroBus was added successfully!" << endl;

	pCar = new Bus;
	pCar->number = "fg620m";
	pCar->owner = "Sasha";
	pCar->brand = "BMW";
	pCar->model = "Bus";
	pCar->color = "red";
	((Bus*)pCar)->engine = Engine::Gasoline;
	(*(Bus*)pCar).placeCount = 5;
	(*(Bus*)pCar).capacity = 3500;
	addItem((Item*)pCar);
	cout << "\nBus was added successfully!" << endl;

	pCar = new Truck;
	pCar->number = "NM940S";
	pCar->owner = "Petra";
	pCar->brand = "Ford";
	pCar->model = "T";
	pCar->color = "black";
	((Truck*)pCar)->engine = Engine::Diesel;
	(*(Truck*)pCar).capacity = 10500;
	addItem((Item*)pCar);
	cout << "\nTruck was added successfully!" << endl;

	pCar = new Bus;
	pCar->number = "QQ625D";
	pCar->owner = "Misha";
	pCar->brand = "Volkswagen";
	pCar->model = "PoloBig";
	pCar->color = "Grey";
	((Bus*)pCar)->engine = Engine::Gasoline;
	(*(Bus*)pCar).placeCount = 6;
	(*(Bus*)pCar).capacity = 1200;
	addItem((Item*)pCar);
	cout << "\nBus was added successfully!" << endl;
}

Car& SubjList::operator[](int index)//перегруженный оператор индексирования
{
	return *(Car*)getItem(index);
}






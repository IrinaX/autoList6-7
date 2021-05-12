#include "list.h"
#include <iostream>
using namespace std;

Item::Item()
{
	pPrev = nullptr;
	pNext = nullptr;
}

Item::~Item()
{
}

Item* Item::getPrev()
{
	return pPrev;
}

Item* Item::getNext()
{
	return pNext;
}

List::List()
{
	pHead = nullptr;
	pTail = nullptr;
}

List::~List()
{
	while (pHead)//пока не будем пустой список
	{
		deleteItem(0);//удаляем первый элемент(каждый раз список сдвигается при удалении)
	}
	pHead = nullptr;
	pTail = nullptr;
}

Item* List::getTail()
{
	return pTail;
}

Item* List::getHead()
{
	return pHead;
}

void List::addItem(Item* listItem)
{
	if (this->pHead == nullptr) {//если нет элементов в списке
		listItem->pPrev = nullptr;//добавленный элемент ни на что не указывает
		listItem->pNext = nullptr;
		this->pHead = listItem;//голова и хвост в списке это добавленный элемент
		this->pTail = listItem;
	}
	else {
		this->pTail->pNext = listItem;//обновляем указатель на след. эл-т у текущего "хвоста"
		listItem->pPrev = this->pTail; //у нового эл-та определяем указатель на пред. эл-т(т.е. прошлый хвост)
		listItem->pNext = nullptr;//следующего эл-та нет, поэтому указатель на след эл-т null
		this->pTail = listItem; //обновляем хвост списка
	}
}

int List::countItems()
{
	int i = 0;
	for (Item* element = this->pHead; element != nullptr; element = element->pNext) {
		++i;
	}
	return i;
}

Item* List::getItem(int index)
{
	if (this->pHead == nullptr) {//если начальный эл-т в списке отсутствует, возвращаем 0
		cout << "\nList is empty." << endl;
		return nullptr;
	}
	Item* element = this->pHead;//присваиваем начальный элемент списка
	for (int i = 0; i < index; ++i) {
		if (element->pNext == nullptr) {//если указатель на след. эл-т отсутствует, значит текущий эл-т последний
			cout << "\nElement doesn't exist." << endl;
			return nullptr;
		}
		else {
			element = element->pNext;//присваиваем следующий элемент
		}
	}
	return element;
}

Item* List::removeItem(int index)
{
	Item* element = getItem(index);
	if (element == nullptr) {
		return nullptr;
	}
	if (this->pTail == this->pHead) {//если в списке остался один элемент
		this->pTail = nullptr;//хвост обнуляем
		this->pHead = nullptr;//голову тоже
		return element;
	}
	if (element->pPrev == nullptr) {//если удалить надо начальный элемент(голову) (индекс 0)
		element->pNext->pPrev = nullptr;//обнуляем указатель на голову
		this->pHead = element->pNext;//новая голова это эл-т с индексом 1
	}
	else {
		if (element->pNext == nullptr) {//если удалить надо конечный элемент(хвост) (индекс n)
			element->pPrev->pNext = nullptr;//обнуляем указатель на хвост
			this->pTail = element->pPrev;//новый хвост это эл-т с индексом n-1
		}
		else {//если элемент находится посередине
			element->pPrev->pNext = element->pNext;//обновляем указатель на след элемент у пред элемента
			element->pNext->pPrev = element->pPrev;//обновляем указатель на пред элемент у след элемента
		}
	}
	return element;
}

void List::deleteItem(int index)
{
	Item* removedItem = removeItem(index);
	if (removedItem)
	{
		delete removedItem;
		removedItem = nullptr;
		cout << "\nItem was successfully deleted!" << endl;
		return;
	}
	cout << "\nSomething went wrong." << endl;
}

void List::clear()
{
	while (this->pHead)//пока список не пуст
	{
		this->deleteItem(0);//удаляем первый элемент(каждый раз список сдвигается при удалении)
	}
	this->pHead = nullptr;
	this->pTail = nullptr;
	cout << "\nList was cleared successfully!" << endl;
}

void List::insertItem(Item* newItem, int index)
{
	Item* element = this->getItem(index);
	if (element != nullptr) {
		if (element == this->pHead) {     // если выбран 0-ой эл-т
			newItem->pPrev = nullptr;     // у нового элемента обнуляем указатель на предыдущий элемент
			newItem->pNext = element;     // у newItem присваиваем указателю на след элемент адрес текущей головы
			element->pPrev = newItem;     // у текущей головы обновляем указатель на пред эл-т
			this->pHead = newItem;        // обновляем указатель на голову
			return;
		}
		if (element == this->pTail) {     // если выбран последний эл-т
			newItem->pNext = nullptr;     // у нового элемента обнуляем указатель на след элемент
			newItem->pPrev = element;     // у newItem присваиваем указателю на пред элемент адрес текущего хвоста
			element->pNext = newItem;     // у текущего хвоста обновляем указатель на след эл-т
			this->pTail = newItem;        // обновляем указатель на хвост
		}
		else {
			element->pPrev->pNext = newItem;    // у элемента index-1 присваиваем указателю на след элемент адрес newItem
			newItem->pPrev = element->pPrev;    // у newItem присваиваем указателю на пред элемент адрес элемента index-1
			newItem->pNext = element;           // у newItem присваиваем указателю на след элемент адрес элемента index
			element->pPrev = newItem;           // у элемента index присваиваем указателю на пред элемент адрес элемента newItem
		}
		cout << "\nNew item was inserted successfully!" << endl;
	}
}

int List::getIndex(Item* listItem)
{
	int index = 0;
	for (Item* element = this->pHead;  element != nullptr;
		element = element->pNext) {
		if (listItem == element) {//если указатель текущего элемента равен необходимому
			return index;
		}
		++index;
	}
	return -1;//если адрес был не найден
}
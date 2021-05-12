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
	while (pHead)//���� �� ����� ������ ������
	{
		deleteItem(0);//������� ������ �������(������ ��� ������ ���������� ��� ��������)
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
	if (this->pHead == nullptr) {//���� ��� ��������� � ������
		listItem->pPrev = nullptr;//����������� ������� �� �� ��� �� ���������
		listItem->pNext = nullptr;
		this->pHead = listItem;//������ � ����� � ������ ��� ����������� �������
		this->pTail = listItem;
	}
	else {
		this->pTail->pNext = listItem;//��������� ��������� �� ����. ��-� � �������� "������"
		listItem->pPrev = this->pTail; //� ������ ��-�� ���������� ��������� �� ����. ��-�(�.�. ������� �����)
		listItem->pNext = nullptr;//���������� ��-�� ���, ������� ��������� �� ���� ��-� null
		this->pTail = listItem; //��������� ����� ������
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
	if (this->pHead == nullptr) {//���� ��������� ��-� � ������ �����������, ���������� 0
		cout << "\nList is empty." << endl;
		return nullptr;
	}
	Item* element = this->pHead;//����������� ��������� ������� ������
	for (int i = 0; i < index; ++i) {
		if (element->pNext == nullptr) {//���� ��������� �� ����. ��-� �����������, ������ ������� ��-� ���������
			cout << "\nElement doesn't exist." << endl;
			return nullptr;
		}
		else {
			element = element->pNext;//����������� ��������� �������
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
	if (this->pTail == this->pHead) {//���� � ������ ������� ���� �������
		this->pTail = nullptr;//����� ��������
		this->pHead = nullptr;//������ ����
		return element;
	}
	if (element->pPrev == nullptr) {//���� ������� ���� ��������� �������(������) (������ 0)
		element->pNext->pPrev = nullptr;//�������� ��������� �� ������
		this->pHead = element->pNext;//����� ������ ��� ��-� � �������� 1
	}
	else {
		if (element->pNext == nullptr) {//���� ������� ���� �������� �������(�����) (������ n)
			element->pPrev->pNext = nullptr;//�������� ��������� �� �����
			this->pTail = element->pPrev;//����� ����� ��� ��-� � �������� n-1
		}
		else {//���� ������� ��������� ����������
			element->pPrev->pNext = element->pNext;//��������� ��������� �� ���� ������� � ���� ��������
			element->pNext->pPrev = element->pPrev;//��������� ��������� �� ���� ������� � ���� ��������
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
	while (this->pHead)//���� ������ �� ����
	{
		this->deleteItem(0);//������� ������ �������(������ ��� ������ ���������� ��� ��������)
	}
	this->pHead = nullptr;
	this->pTail = nullptr;
	cout << "\nList was cleared successfully!" << endl;
}

void List::insertItem(Item* newItem, int index)
{
	Item* element = this->getItem(index);
	if (element != nullptr) {
		if (element == this->pHead) {     // ���� ������ 0-�� ��-�
			newItem->pPrev = nullptr;     // � ������ �������� �������� ��������� �� ���������� �������
			newItem->pNext = element;     // � newItem ����������� ��������� �� ���� ������� ����� ������� ������
			element->pPrev = newItem;     // � ������� ������ ��������� ��������� �� ���� ��-�
			this->pHead = newItem;        // ��������� ��������� �� ������
			return;
		}
		if (element == this->pTail) {     // ���� ������ ��������� ��-�
			newItem->pNext = nullptr;     // � ������ �������� �������� ��������� �� ���� �������
			newItem->pPrev = element;     // � newItem ����������� ��������� �� ���� ������� ����� �������� ������
			element->pNext = newItem;     // � �������� ������ ��������� ��������� �� ���� ��-�
			this->pTail = newItem;        // ��������� ��������� �� �����
		}
		else {
			element->pPrev->pNext = newItem;    // � �������� index-1 ����������� ��������� �� ���� ������� ����� newItem
			newItem->pPrev = element->pPrev;    // � newItem ����������� ��������� �� ���� ������� ����� �������� index-1
			newItem->pNext = element;           // � newItem ����������� ��������� �� ���� ������� ����� �������� index
			element->pPrev = newItem;           // � �������� index ����������� ��������� �� ���� ������� ����� �������� newItem
		}
		cout << "\nNew item was inserted successfully!" << endl;
	}
}

int List::getIndex(Item* listItem)
{
	int index = 0;
	for (Item* element = this->pHead;  element != nullptr;
		element = element->pNext) {
		if (listItem == element) {//���� ��������� �������� �������� ����� ������������
			return index;
		}
		++index;
	}
	return -1;//���� ����� ��� �� ������
}
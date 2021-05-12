#pragma once
class Item
{
public:
	Item();

	/*������ "������.��� ������ ����� ��������" ��� _free_dbg(block, _UNKNOWN_BLOCK); ��� _crtisValidHeapPointer (block) delete
	��������� ��� �������� ������������ ������ � ������� ��������� �������� ������,
	����� ���������� �������� ������ �� �������� ����������� - ������ ������ �����������
	������������ ������ ���������� ���������� �������� ������, ��� �������� �������.
	��� ��� ������ ��������, ���� �� ������ �������� virtual ~BaseClass(){} � ��������� ������ ���������� ������ BaseClass.
	*/
	virtual ~Item();

	Item* getPrev();
	Item* getNext();

	friend class List; // ����� ���� � ������ ������ Item ����� �������� ������ List
	friend class SubjList; // ����� ���� � ������ ������ Item ����� �������� ������ SubjList

private:
	Item* pPrev;
	Item* pNext;
};

class List
{
public:
	List();
	~List();

	Item* getTail();

	Item* getHead();

	void addItem(Item* listItem);

	int countItems();

	Item* getItem(int index);

	Item* removeItem(int index);

	void deleteItem(int index);

	void clear();

	void insertItem(Item* newItem, int index);

	int getIndex(Item* listItem);

protected:
	Item* pTail;
	Item* pHead;
};

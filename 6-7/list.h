#pragma once
class Item
{
public:
	Item();

	/*ќшибка "проект.срр вызвал точку останова" или _free_dbg(block, _UNKNOWN_BLOCK); или _crtisValidHeapPointer (block) delete
	возникает при удалении производного класса с помощью указател€ базового класса,
	когда деструктор базового класса не €вл€етс€ виртуальным - вместо вызова деструктора
	производного класса вызываетс€ деструктор базового класса, что €вл€етс€ ошибкой.
	¬аш код должен работать, если вы просто добавите virtual ~BaseClass(){} в публичный раздел объ€влени€ класса BaseClass.
	*/
	virtual ~Item();

	Item* getPrev();
	Item* getNext();

	friend class List; // любые пол€ и методы класса Item будут доступны классу List
	friend class SubjList; // любые пол€ и методы класса Item будут доступны классу SubjList

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

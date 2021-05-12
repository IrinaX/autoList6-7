#pragma once
#include "list.h"
#include <iostream>//����� string �������
#include <string>
using namespace std;


enum class Engine
{
	Gasoline,
	Diesel
};

enum class CarBody
{
	Sedan,
	Coup,
	Universal
};

enum class Drive
{
	Front,
	Back,
	Full
};

//������������, �������� �������� ������������� ����� ��������
enum class CarType
{
	itPassengerCar,
	itMicroBus,
	itBus,
	itTruck,
	itSpecial
};

class Car : public Item
{
public:
	virtual void input();
	virtual void print();

	friend class SubjList;
	bool operator==(string keyWord); //������������� �������� ��������������� �� ��������� ���� string
protected:
	//CarType type;
	string number;
	string owner;
	string brand;
	string model;
	string color;
};

class PassengerCar : public Car
{
public:
	void input();
	void print();
	CarType getCarType();
	friend class SubjList;

private:
	Engine engine;
	CarBody body;
	Drive drive;
};

class MicroBus : public Car
{
public:
	virtual void input();
	virtual void print();
	CarType getCarType();
	friend class SubjList;

	bool operator>(MicroBus car); //������������� �������� ��������� ������ ������� � ������ ��������
protected:
	Engine engine;
	int placeCount;
};

class Bus : public MicroBus
{
public:
	void input();
	void print();
	CarType getCarType();
	friend class SubjList;

private:
	int capacity;
};

class Truck : public Car
{
public:
	void input();
	void print();
	CarType getCarType();
	friend class SubjList;

private:
	Engine engine;
	int capacity;
};

class Special : public Car
{
public:
	void input();
	void print();
	CarType getCarType();
	friend class SubjList;

private:
	string description;
};

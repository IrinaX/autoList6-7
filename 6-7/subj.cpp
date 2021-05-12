#include "subj.h"


void Car::input()
{
	cout << "Enter state number (max 9 symbols): ";//���. �����
	cin >> this->number;
	cout << "Enter owner (max 29 symbols): ";//�����������
	cin >> this->owner;
	cout << "Enter brand (max 19 symbols): ";//�����
	cin >> this->brand;
	cout << "Enter model (max 19 symbols): ";//������
	cin >> this->model;
	cout << "Enter color (max 19 symbols): ";//����
	cin >> this->color;
}

void Car::print()
{
	cout << "State number: " << this->number << endl;
	cout << "Owner: " << this->owner << endl;
	cout << "Brand: " << this->brand << endl;
	cout << "Model: " << this->model << endl;
	cout << "Color: " << this->color << endl;
}

bool Car::operator==(string keyWord)//������������� �������� ��������������� �� ��������� ���� string
{
	return (*this).number == keyWord;
}
void PassengerCar::input()
{
	Car::input();//������� ������ ��� ���� ������� ���� � ������� ������
	cout << "Choose engine type: " << endl;		//��� ���������
	cout << "1. Gasoline" << endl;				//������
	cout << "2. Diesel" << endl;				//������
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->engine = Engine::Gasoline;

		break;
	case 2:
		this->engine = Engine::Diesel;
		break;
	default:
		break;
	}
	cout << "Choose car body type: " << endl;	//��� ������
	cout << "1. Sedan" << endl;					//�����
	cout << "2. Coup" << endl;					//����
	cout << "3. Universal" << endl;				//���������
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->body = CarBody::Sedan;
		break;
	case 2:
		this->body = CarBody::Coup;
		break;
	case 3:
		this->body = CarBody::Universal;
		break;
	default:
		break;
	}
	cout << "Choose drive type: " << endl;
	cout << "1. Front" << endl;
	cout << "2. Back" << endl;
	cout << "3. Full" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->drive = Drive::Front;
		break;
	case 2:
		this->drive = Drive::Back;
		break;
	case 3:
		this->drive = Drive::Full;
		break;
	default:
		break;
	}
}

void PassengerCar::print()
{
	cout << "Type: Passenger Car" << endl;
	Car::print();//������� ������� ��� ���� ������� ���� � ������� ������
	cout << "Engine type: ";
	switch (this->engine)
	{
	case Engine::Gasoline:
		cout << "Gasoline" << endl;
		break;
	case Engine::Diesel:
		cout << "Diesel" << endl;
		break;
	default:
		break;
	}

	cout << "Car body type: ";
	switch (this->body)
	{
	case CarBody::Sedan:
		cout << "Sedan" << endl;
		break;
	case CarBody::Coup:
		cout << "Coup" << endl;
		break;
	case CarBody::Universal:
		cout << "Universal" << endl;
		break;
	default:
		break;
	}

	cout << "Drive type: ";
	switch (this->drive)
	{
	case Drive::Front:
		cout << "Front" << endl;
		break;
	case Drive::Back:
		cout << "Back" << endl;
		break;
	case Drive::Full:
		cout << "Full" << endl;
		break;
	default:
		break;
	}
	cout << endl;
}

CarType PassengerCar::getCarType()
{
	return CarType::itPassengerCar;
}

void MicroBus::input()
{
	Car::input();//������� ������ ��� ���� ������� ���� � ������� ������
	cout << "Choose engine type: " << endl;		//��� ���������
	cout << "1. Gasoline" << endl;				//������
	cout << "2. Diesel" << endl;				//������
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->engine = Engine::Gasoline;
		break;
	case 2:
		this->engine = Engine::Diesel;
		break;
	default:
		break;
	}
	cout << "Enter number of seats: ";
	cin >> this->placeCount;
	cout << endl;
}

void MicroBus::print()
{
	cout << "Type: Micro Bus" << endl;
	Car::print();//������� ������� ��� ���� ������� ���� � ������� ������
	cout << "Engine type: ";
	switch (this->engine)
	{
	case Engine::Gasoline:
		cout << "Gasoline" << endl;
		break;
	case Engine::Diesel:
		cout << "Diesel" << endl;
		break;
	default:
		break;
	}
	cout << "Number of seats: " << this->placeCount << endl;
}

CarType MicroBus::getCarType()
{
	return CarType::itMicroBus;
}

bool MicroBus::operator>(MicroBus car)//������������� �������� ��������� ������ ������� � ������ ��������
{
	return (*this).placeCount > car.placeCount;
}

void Bus::input()
{
	Car::input();//������� ������ ��� ���� ������� ���� � Car
	cout << "Choose engine type: " << endl;		//��� ���������
	cout << "1. Gasoline" << endl;				//������
	cout << "2. Diesel" << endl;				//������
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->engine = Engine::Gasoline;
		break;
	case 2:
		this->engine = Engine::Diesel;
		break;
	default:
		break;
	}
	cout << "Enter number of seats: ";
	cin >> this->placeCount;
	cout << "Enter lifting capacity: ";
	cin >> this->capacity;
	cout << endl;
}

void Bus::print()
{
	cout << "Type: Bus" << endl;
	Car::print();//������� ������� ��� ���� ������� ���� � Car
	cout << "Engine type: ";
	switch (this->engine)
	{
	case Engine::Gasoline:
		cout << "Gasoline" << endl;
		break;
	case Engine::Diesel:
		cout << "Diesel" << endl;
		break;
	default:
		break;
	}
	cout << "Number of seats: " << this->placeCount << endl;
	cout << "Lifting capacity: " << this->capacity << endl;
}

CarType Bus::getCarType()
{
	return CarType::itBus;
}

void Truck::input()
{
	Car::input();//������� ������ ��� ���� ������� ���� � ������� ������
	cout << "Choose engine type: " << endl;		//��� ���������
	cout << "1. Gasoline" << endl;				//������
	cout << "2. Diesel" << endl;				//������
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		this->engine = Engine::Gasoline;
		break;
	case 2:
		this->engine = Engine::Diesel;
		break;
	default:
		break;
	}
	cout << "Enter lifting capacity: ";
	cin >> this->capacity;
	cout << endl;
}

void Truck::print()
{
	cout << "Type: Truck" << endl;
	Car::print();//������� ������� ��� ���� ������� ���� � ������� ������
	cout << "Engine type: ";
	switch (this->engine)
	{
	case Engine::Gasoline:
		cout << "Gasoline" << endl;
		break;
	case Engine::Diesel:
		cout << "Diesel" << endl;
		break;
	default:
		break;
	}
	cout << "Lifting capacity: " << this->capacity << endl;
}

CarType Truck::getCarType()
{
	return CarType::itTruck;
}

void Special::input()
{
	Car::input();//������� ������ ��� ���� ������� ���� � ������� ������
	cout << "Enter description (max 99 symbols): ";
	cin.ignore();//ignore \n
	getline(cin, this->description);
}

void Special::print()
{
	cout << "Type: Special" << endl;
	Car::print();//������� ������� ��� ���� ������� ���� � ������� ������
	cout << "Description: " << this->description << endl;
}

CarType Special::getCarType()
{
	return CarType::itSpecial;
}

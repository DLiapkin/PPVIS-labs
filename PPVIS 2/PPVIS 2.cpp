#include <iostream>
#include <string>

using namespace std;

namespace truck
{
	void Cargo()
	{
		cout << "I tansport materials, goods and other things.\n";
	}
}

namespace passenger_car
{
	void Cargo()
	{
		cout << "I tansport leather bas... khm, I mean humans.\n";
	}
}


class Car
{
public:
	void drive()
	{
		cout << "I can drive" << endl;
	}

	void changeengine()
	{
		cout << "changing electro engine to the internal and in reverse" << endl;
	}

	virtual void enginesound()
	{
		cout << "Cars have engine sound , but different " << endl;
	}

	virtual void CarCargo()
	{
		cout << "I can transport something.\n";
	}

private:
	int doors;
protected:
	string color;
};


class Electro :public Car
{
public:
	void charging()
	{
		cout << "Car is charging" << endl;
	}
	void enginesound() override
	{
		cout << "Electro is shy like zzzzzzzz" << endl;
	}
};

class Fuel :public Car
{
public:
	void checkFuel()
	{
		cout << "Fuel is full" << endl;
	}
	void enginesound() override
	{
		cout << "DVS is almost loud like roar trrrrr" << endl;
	}
};


class Hybrid :public virtual Electro, public virtual Fuel
{
public:
	void usingbothenging()
	{
		cout << "i can use both engines" << endl;
	}
	void enginesound() override
	{
		cout << "tr tr tr z z z" << endl;;
	}

};

class Fuel_Truck : private Fuel
{
public:

	void Icandrive()
	{
		drive();
		cout << "but this function is now private\n";
	}

	void CarCargo() override
	{
		truck::Cargo();
	}

};

class Bus : protected Fuel
{
public:

	Bus(string colour)
	{
		cout << "I can change colour. Now it's " << colour << endl;
		this->color = colour;
	}

	void Icandrive()
	{
		drive();
	}

	void CarCargo() override
	{
		passenger_car::Cargo();
	}
};

class AUDI : public Hybrid
{
public:
	void wheelCount()
	{
		cout << "Enter amountof whell on your audi: ";
		cin >> wheel;
		cout << "You have " << wheel << " wheels" << endl;
	}
	void radius()
	{
		cout << "Enter  whell radius on your audi: ";
		cin >> wheelradius;
		cout << "You have " << wheelradius << " radius" << endl;
	}

	void enginesound() override
	{
		cout << "Audi roar is here" << endl;
	}
	void checkColor()
	{
		string color;
		cout << "What is your car color?" << endl;
		cin >> color;
		cout << "Your R8V10 is " << color;
	}

private:
	string vin;
	int wheelradius;
	int wheel;

};

class Tesla :public Electro
{
public:
	void wheelCount()
	{
		cout << "Enter amountof whell on your audi: ";
		cin >> wheel;
		cout << "You have " << wheel << " wheels" << endl;
	}
	void radius()
	{
		cout << "Enter  whell radius on your audi: ";
		cin >> wheelradius;
		cout << "You have " << wheelradius << " radius" << endl;
	}

	void enginesound() override
	{
		cout << "Tesla roar is here" << endl;
	}
	void checkColor()
	{
		string color;
		cout << "What is your car color?" << endl;
		cin >> color;
		cout << "Your Tesla is " << color;
	}
	void checkVin()
	{
		cout << "Enter your tesla vin-code: ";
		cin >> vin;
		cout << "Your vin  is: " << vin << endl;
	}

private:
	string vin;
	int wheelradius;
	int wheel;
};










int main()
{
	Fuel car;
	cout << "AUDI:=================" << endl;
	car.drive();
	car.checkFuel();
	car.CarCargo();
	AUDI R8;
	R8.wheelCount();
	R8.radius();
	R8.enginesound();
	R8.checkFuel();
	R8.checkColor();
	Electro cars;
	cout << "Tesla:================" << endl;
	cars.charging();
	cars.drive();
	cars.enginesound();
	cout << "Hybrid:===============" << endl;
	Hybrid  prius;
	prius.usingbothenging();
	prius.enginesound();
	cout << "Truck:===============" << endl;
	Fuel_Truck Maz;
	Maz.Icandrive();
	Maz.CarCargo();
	cout << "Bus:=================" << endl;
	Bus Zil("green");
	Zil.Icandrive();
	Zil.CarCargo();
	cout << "Audi=====================" << endl;

	AUDI a4E;// electro audi
	a4E.wheelCount();
	a4E.radius();
	a4E.charging();
	a4E.usingbothenging();



}
//2.  Создать класс Car(автомобиль) с полями company(компания) и model(модель).
//   Классы - наследники: PassengerCar(легковой автомобиль) и Bus(автобус).От этих классов наследует класс Minivan(минивэн).
//   Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.Создать объекты для каждого из классов и посмотреть, 
//   в какой последовательности выполняются конструкторы.Обратить внимание на проблему «алмаз смерти».



#include <iostream>

class Car
{
protected:
	std::string company, model;
public:
	Car() {}
	Car(std::string inputCompany, std::string inputModel)
		: company(inputCompany), model(inputModel)
	{
		std::cout << "\nBase car constructor";
	}

	virtual ~Car()
	{
		std::cout << "\nBase car destructor";
	}
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar() {}
	PassengerCar(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\nPassenger car constructor";
		std::cout << "\n" << company << " " << model;
	}

	std::string getModel()
	{
		return model;
	}

	~PassengerCar()
	{
		std::cout << "\nPassenger car destructor";
	}
};

class Bus : virtual public Car
{
public:
	Bus() {}
	Bus(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\nBus constructor";
		std::cout << "\n" << company << " " << model;
	}

	~Bus()
	{
		std::cout << "\nBus destructor";
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string inputCompany, std::string inputModel)
		: Car(inputCompany, inputModel)
	{
		std::cout << "\nMinivan constructor";
		std::cout << "\n" << company << " " << model;
	}

	~Minivan()
	{
		std::cout << "\nMinivan destructor";
	}
};

int main()
{
	Car* car = new Car("Volvo", "S70");
	std::cout << "\n++++++++++++++++++++++++++++++";
	PassengerCar* passengerCar = new PassengerCar("Mersedes", "S 600");
	std::cout << "\n++++++++++++++++++++++++++++++";
	Bus* bus = new Bus("Mercedes Benz", "Tourrider");
	std::cout << "\n++++++++++++++++++++++++++++++";
	Minivan* minivan = new Minivan("Toyota", "Alphard");
	std::cout << "\n++++++++++++++++++++++++++++++";
	delete minivan;
	std::cout << "\n++++++++++++++++++++++++++++++";
	delete bus;
	std::cout << "\n++++++++++++++++++++++++++++++";
	delete passengerCar;
	std::cout << "\n++++++++++++++++++++++++++++++";
	delete car;
};

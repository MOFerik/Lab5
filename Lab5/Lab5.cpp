#include <iostream>
#include <string>

using namespace std;

class Planet
{

	protected: 
	string name;
	double radius;
	double density;
	double mass;
	int temp;

	public: 
	Planet(string n, double r, double d)
	{
		name = n;
		radius = r;
		density = d;

		mass = r * r * d;
		cout << "\n\nA planet was discovered. It was named " << name <<", it's radius is " << radius  <<" e.r. and it's denisty is " << density << " e.d.";
	}

	double getMass()
	{
		cout << name << "'s mass is " << mass << " e.m.";
		return mass;
	}

	void setTemp(int t)
	{
		temp = t;
	}

	int getTemp()
	{
		cout << name << "'s surface temperature is " << temp << " Kelvins.\n";
		return temp;
	}

	virtual ~Planet()
	{
		cout << name << " was destroyed.\n\n";
	};
};

class AtmPlanet : Planet
{
	protected:
	double atmDens;
	int greenHouse;

	public:
	AtmPlanet(string n, double r, double d, double a, int g) : Planet(n, r, d)
	{
		atmDens = a;
		greenHouse = g;
		cout << " This planet has an atmosphere, it's density is " << atmDens << " e.a. and it creates a greenhouse effect, that causes " << greenHouse << " Kelvin increase in temperature. \n";
	}

	int setTemp(int t)
	{
		temp = t + greenHouse;
	}

	~AtmPlanet()
	{
		cout << "A planet with atmosphere - ";
	};
};

int main()
{
	Planet mercury = Planet("Mercury", 0.3, 1.2);
	AtmPlanet jupiter = AtmPlanet("Jupiter", 40, 0.2, 20, 10);
}

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

	string getName()
	{
		return name;
	}

	virtual string getPlanetType()
	{
		return "Planet without an atmosphere.";
	}

	virtual bool isA(string type)
	{
		if ("Planet without an atmosphere." == type)
		{
			cout << name << " is a " << type << "\n";
			return true;
		}
		else
		{
			cout << name << " is not a " << type << "\n";
			return false;
		}
	}

	double getMass()
	{
		cout << "\n" << name << "'s mass is " << mass << " e.m.\n";
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

class AtmPlanet : public Planet
{
	protected:
	double atmDens;
	int greenHouse;

	public:
	AtmPlanet(string n, double r, double d, double a, int g) : Planet(n, r, d)
	{
		atmDens = a;
		greenHouse = g;
		cout << " This planet has an atmosphere, it's density is " << atmDens << " e.a. and it creates a greenhouse effect, that causes " << greenHouse << " Kelvin increase in temperature.";
	}

	string getPlanetType()
	{
		return "Planet with an atmosphere.";
	}

	bool isA(string type)
	{
		if ("Planet with an atmosphere." == type)
		{
			cout << name << " is a " << type << "\n";
			return true;
		}
		else
		{
			cout << name << " is not a " << type << "\n";
			return false;
		}
	}

	void setTemp(int t)
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
	mercury.getMass();
	mercury.setTemp(923);
	mercury.getTemp();

	mercury.isA("Planet with an atmosphere.");
	cout << mercury.getName() << " is a: " << mercury.getPlanetType() <<"\n";

	AtmPlanet jupiter = AtmPlanet("Jupiter", 40, 0.2, 20, 10);
	jupiter.getMass();
	jupiter.setTemp(189);
	jupiter.getTemp();
	jupiter.isA("Planet without an atmosphere.");

	cout << jupiter.getName() <<" is a: " << jupiter.getPlanetType() << "\n";
}

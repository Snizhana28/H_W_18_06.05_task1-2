#include "../parent/pet.h"

class Parrot : public Pet
{
public:
	//constructor
	Parrot()
	{
		this->name = "Kesha";
		this->year = 3;
		this->breed = "ara";
		this->color = "red";
	};
	void print() override
	{
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
		cout << "Breed: " << breed << endl;
		cout << "Color: " << color << endl;
	}
	//destructor
	~Parrot()
	{
		name.clear();
		breed.clear();
		color.clear();
		year = 0;
	};
};
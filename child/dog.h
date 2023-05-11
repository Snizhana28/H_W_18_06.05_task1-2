#include "../parent/pet.h"

class Dog : public Pet
{
public:
	//constructor
	Dog() 
	{
		this->name = "Bob";
		this->year = 2;
		this->breed = "doberman";
		this->color = "black";
	};
	void print() override
	{
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
		cout << "Breed: " << breed << endl;
		cout << "Color: " << color << endl;
	}
	//destructor
	~Dog()
	{
		name.clear();
		breed.clear();
		color.clear();
		year = 0;
	};
};
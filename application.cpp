#include "child/parrot.h"
#include "child/cat.h"
#include "child/dog.h"

#include <vector>

int main()
{
	cout << "Pet" << endl;
	vector<Pet*> pets;
	pets.push_back(new Parrot());
	pets.push_back(new Dog());
	pets.push_back(new Cat());

	for (int i = 0; i < pets.size(); i++)
	{
		pets[i]->print();
		cout << endl;
	}
	for (int i = 0; i < pets.size(); i++)
	{
		delete pets[i];
	}
	pets.clear();
	return 0;
}
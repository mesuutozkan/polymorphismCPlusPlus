#include <iostream>

using namespace std;

//base class

class animal
{

public:

	virtual void voice()								//virtual functions can be manipulated inside of child classes.
	{													//this  allows polymorphism. (use of method with different way inside 
		cout << "animal voice\n" << endl;				//child classes.
	};

	void print()
	{
		cout << "animal class printed\n" << endl;
	};

};

//child class cat

class cat : public animal
{

public:

	void voice()
	{
		cout << "cat voice\n" << endl;
	};

	void print()
	{
		cout << "cat class printed\n" << endl;
	};

};

//child class dog

class dog : public animal
{

public:

	void voice()
	{
		cout << "dog voice\n" << endl;
	};

	void print()
	{
		cout << "dog class printed\n" << endl;
	};

};

//good usage of POLYMORPHISM. It allows clean code.
//below function can be used from any of the child class that having "voice()" virtual method.

static void voiceThreeTimes(animal* animal1)
{
	for (int i = 0; i < 3; i++)
	{
		animal1->voice();
	}
}

int main()
{

	animal* animalPtr;								//define base class pointer
	
	cat cat1;										//define a cat object

	animalPtr = &cat1;								//point base class pointer to child class object

	animalPtr->voice();								//call virtual function which is manipulated inside of child class

	animalPtr->print();								//still uses base class method, where polymorphism can not be implemented

	cat1.print();									//use base class method with inheretence

	voiceThreeTimes(animalPtr);						//feat1/polymorphismImplementation implementation of function

	voiceThreeTimes(&cat1);							//feat1/polymorphismImplementation implementation of function (child class access)

	dog dog1;										//define a dog object

	animalPtr = &dog1;								//point base class pointer to another child class object

	animalPtr->voice();								//call virtual function which is manipulated inside of child class

	animalPtr->print();								//still uses base class method, where polymorphism can not be implemented

	dog1.print();									//use base class method with inheretence

}
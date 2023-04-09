#include "PlayerTestState.h"

namespace RB::Players
{
	PlayerTestState::PlayerTestState()
	{
	
	}

	PlayerTestState::~PlayerTestState()
	{

	}

	void PlayerTestState::OnFixedUpdate()
	{
		iPlayer* player = RB::Controllers::GameplayControllers::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachine->GetID());

		player->Move(olc::vi2d{ 1, 1 });
	}

	void PlayerTestState::SomeFunc()
	{

	}
}

/*
//In C++, you can have a member function pointer as a template parameter by using templates.Here’s an example :

#include <iostream>

template <typename T, void (T::* Func)()>
class MyClass {
public:
	T* myObject;

	MyClass(T* obj) : myObject(obj) {}

	void callMemberFunction() {
		(myObject->*Func)();
	}
};

class MyOtherClass {
public:
	void myFunction() {
		std::cout << "Hello, World!" << std::endl;
	}
};

int main() {
	MyOtherClass myObject;

	MyClass<MyOtherClass, &MyOtherClass::myFunction> myClassObject(&myObject);

	myClassObject.callMemberFunction(); // prints Hello, World!

	return 0;
}
//In this example, the MyClass class has two template parameters : T represents the type of the object that the member function pointer will be called on, and Func represents the member function pointer itself.The callMemberFunction member function of MyClass uses the ->* operator to call the member function pointed to by Func on the object pointed to by myObject.
//Is there anything else you would like to know ?
*/
# private/protected наследование:

## private:

Особенности:
* Все члены базового класса становятся приватными в производном классе.
* Производный класс имеет доступ к public и protected членам базового класса, но они недоступны извне.

Пример:
```cpp
#include <iostream>

class Base {
public:
	void function1() { std::cout << "1st funtion." << '\n'; }
protected:
	void function2() { std::cout << "2nd function" << '\n'; } 
};

class Derived : private Base {
public:
	void callFunctions() {
		function1();
		function2();
	}
};

int main() {
	Derived d;
	d.callFunctions(); // Сработает
	d.funtion1(); // Не сработает (нет доступа, тк function1() стала приватной)!
	return 0;
}
```

## protected:

Особенности:
* `public` члены базового класса становятся `protected` в производном.
* Производный класс и его наследники имеют доступ к `public` и `protected` методам базового, но они недоступны извне.

Пример:
```cpp
#include <iostream>

class Base {
public:
	void function1() { std::cout << "1st funtion." << '\n'; }
protected:
	void function2() { std::cout << "2nd function" << '\n'; } 
};

class Derived : protected Base {
public:
	void callFunctions1() {
		function1();
		function2();
	}
};

class GrandDerived : public Deriver {
public:
	void callFunctions2() {
		function1();
		function2();
	}
};

int main() {
	Derived d;
	d.callFunctions1(); // Сработает
	d.funtion1(); // Не сработает (нет доступа, тк function1() стала приватной)!
	GrandDerived gd;
	gd.callFunctions2(); // Сработает
	return 0;
}
```

Итог:
* `Private` наследование полностью скрывает базовый класс от внешнего мира и наследников.
* `Protected` наследование позволяет наследникам производного класса использовать члены базового.

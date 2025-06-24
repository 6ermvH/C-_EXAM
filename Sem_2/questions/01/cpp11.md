# C++11: final, override

## final:

Используется для предотвращения дальнейшего наследования класса или переопределения виртуальной функции.

Пример для класса:
```cpp
class Base final {
...
};

// Ошибка! Нельзя наследовать из final-класса
class Derived : public Base {
...
}
```

Пример для метода:
```cpp
class Base {
public:
	virtual void func() final {...}
};

class Derived : public Base {
public:
	void func() override {...} // Ошибка! тк функция помечена как final
};
```

## override:

Использутся в производных классах, чтобы явно указать что метод переопределяет виртуальную функцию из базового. Позволяет избежать ошибок, связанных с неправильным переопределением.

Пример:
```cpp
class Base {
public:
	virtual void func() const { std::cout << "Base out." << '\n'; }
};

class Derived : public Base {
public:
	void func() const override { std::cout << "Derived out." << '\n'; }
};

int main() {
	Base *obj = new Derived;
	obj->func(); // Выведет Derived out.
	delete obj;
	return 0;
}
```

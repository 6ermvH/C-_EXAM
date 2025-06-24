---

---
# ООП
## Три ключевые идеи
- ### Инкапсуляция
  1. Языковая конструкция, позволяющая связать переменные с функциями, предназначенными для обработки этих данных (получается новый тип данных)
  2. Механизм языка, позволяющий ограничить доступ одних компонентов программы к другим (не сокрытие!!!)
- ### Наследование
  1. Один класс может наследоваться (копировать себе) данные и функциональность некоторого существующего класса,  способствуя повторному использованию компонентов программного обеспечения
- ### Полиморфизм
  1. Способность функции обрабатывать данные разных типов(классов)
---
# Сортировка и Структуры C vs ООП
## В C для сортировки любых данных используется `qsort`

```C
void qsort (void* base, size_t num, size_t size, 
			int (*compar) (const void*, const void*) );
```

### Пример:
```c
struct point {
	int x, y;
};
struct point point_array[N];
qsort  (point_array, N,
		sizeof(point_array) / sizeof(point_array[0]),
		point_cmp);
```

## В ООП предпологается, что каждый сортируемый класс имеет метод compare

```c++
class Comparable {
	// some methods and variables
	virtual int compare(const Comparable* comp) const;
};

class Point : public Comparable {
	int x, y;
public:
	virtual int compare(const Comparable* comp) const;
};
```
	  
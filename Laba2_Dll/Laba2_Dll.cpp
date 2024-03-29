
#include"pch.h"
#include "dll_complex.h"
#include <iostream>
#include <windows.h>
 
// Создаём указатель на искомую функцию
typedef BaseComplex* (__cdecl *BaseComplex_factory)();

void main()
{
	HINSTANCE hmodule = NULL; //возращает указатель на dll, если найдёт его
	// Cтавим префикс L для преобразования char*  в  wchar*
	hmodule=LoadLibrary(L"dll_complex.dll");
	// проверка - загрузилась ли библиотека 
	if (!hmodule)
	{
		std::cout << "Failed to load Library!\n";
		return;
	}
	// возращает указатель на искомую функцию по указателю на длл и имени функции данное ей при рождении.
	BaseComplex_factory CreateClass = reinterpret_cast<BaseComplex_factory>(GetProcAddress(hmodule, "CreateClass"));
	if (!CreateClass)
	{
		std::cout << "Failed to Find Factory!\n";
		FreeLibrary(hmodule);
		return;
	}
	//инициализация объектов интерфейсного класса
	BaseComplex* A = CreateClass();
	BaseComplex* B = CreateClass();
	BaseComplex* C = CreateClass();
	A->SetReIm(5, 3);
	B->SetReIm(6, 9); 

	A->OutDN();
	// вывод чисел на экран 
	A->OutD();
	B->OutD();
	// сумма 
	C = A->Plus(B);
	C->OutD();
	//умножение 
	C = A->Multiply(B);
	C->OutD();

	//деление 
	C = A->Divide(B);
	C->OutD(); 
	//удаление объектов 
	A->destroy();
	B->destroy();
	C->destroy();
	//Отключение dll
	FreeLibrary(hmodule);
	system("pause");
}

// dll_complex.cpp : Определяет экспортированные функции для приложения DLL.
//




#include "stdafx.h"
#include "dll_complex.h"
#include <iostream>
#include <windows.h>


class Complex :public BaseComplex
{
private:
	float re; // вещественная 
	float im; //мнимая 
public:
	Complex() //конструктор 
	{
		re = 0;
		im = 0;
	}
	Complex(float x, float y) //конструктор 
	{
		re = x;
		im = y;
	}
	~Complex() //деструктор 
	{
	}
	void destroy()  //функция удаления объекта 
	{
		delete this;
	}
	void OutD() //вывод числа на экран 
	{
		std::cout << re;
		if (im > 0) std::cout << "+";
		if (im != 0) std::cout << im << "i\n";
	}
	void OutDN() //вывод числа на экран 
	{
		if (im > 0) std::cout << "+";
		if (im != 0) std::cout << im << "i\n";
		std::cout << re << "i\n";
		
	}
	void Sopr() // Получения сопряженного числа 
	{
		im = im * (-1);
	}
	float Re()  //вызов вещественной части
	{
		return re;
	}
	float Im() //вызов мнимой части
	{
		return im;
	}
	void SetReIm(float a, float b)
	{
		re = a;
		im = b;
	}
	BaseComplex* Plus(BaseComplex* B) //Сумма комплексных чисел 
	{
		BaseComplex* D = new Complex;
		D->SetReIm(Re() + B->Re(), Im() + B->Im());
		return D;
	}
	virtual BaseComplex* Plus(float B) //Сумма комплексного и вещественного 
	{
		BaseComplex* D = new Complex;
		D->SetReIm(Re() + B, Im());
		return D;
	}
	BaseComplex* Minus(BaseComplex* B) //Разность комплексных чисел
	{
		BaseComplex* D = new Complex;
		D->SetReIm(Re() - B->Re(), Im() - B->Im());
		return D;
	}
	BaseComplex* Minus(float B)  //Разность комплексного и вещественного 
	{
		BaseComplex* D = new Complex;
		D->SetReIm(Re() - B, Im());
		return D;
	}
	BaseComplex* Multiply(BaseComplex* B)  //Произведение комплексных
	{
		BaseComplex* D = new Complex;
		D->SetReIm((Re()*B->Re()) - (Im()*B->Im()), ((Re()*B->Im()) + (Im()*B->Re())));
		return D;
	}
	BaseComplex* Multiply(float B)//Произведение комплексного и вещественного
	{
		BaseComplex* D = new Complex;
		D->SetReIm((Re()*B), (Im()*B));
		return D;
	}
	BaseComplex* Divide(BaseComplex* B) //Деление комплексных чисел
	{
		BaseComplex* D = new Complex;
		float x, y;
		x = ((Re()*B->Re() + Im()*B->Im()) / (B->Re()*B->Re() + B->Im()*B->Im()));
		y = ((Im()*B->Re() - Re()*B->Im()) / (B->Re()*B->Re() + B->Im()*B->Im()));
		D->SetReIm(x, y);
		return D;
	}
	BaseComplex* Divide(float B)  //Деление комплексого на вещественное 
	{
		BaseComplex* D = new Complex;
		D->SetReIm((Re()*B) / (B*B), (Im()*B) / (B*B));
		return D;
	}
	
};

extern "C" __declspec(dllexport) BaseComplex* __cdecl CreateClass()
{
	BaseComplex* A = new Complex;
	return A;
}



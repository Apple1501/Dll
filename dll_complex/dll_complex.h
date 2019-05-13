#pragma once

class BaseComplex
{
public:
	virtual void destroy() = 0;
	virtual void OutD() = 0;
	virtual void Sopr() = 0;
	virtual void SetReIm(float a, float b) = 0;
	virtual float Re() = 0;
	virtual float Im() = 0;
	virtual BaseComplex* Plus(BaseComplex* B) = 0;
	virtual BaseComplex* Plus(float B) = 0;
	virtual BaseComplex* Minus(BaseComplex* B) = 0;
	virtual BaseComplex* Minus(float B) = 0;
	virtual BaseComplex* Multiply(BaseComplex* B) = 0;
	virtual BaseComplex* Multiply(float B) = 0;
	virtual BaseComplex* Divide(BaseComplex* B) = 0;
	virtual BaseComplex* Divide(float B) = 0;
};
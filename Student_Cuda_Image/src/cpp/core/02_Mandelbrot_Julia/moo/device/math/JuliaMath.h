#pragma once

#include <math.h>
#include "MathTools.h"

#include "ColorTools_GPU.h"
#include "FractaleMath.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class JuliaMath : public FractaleMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__ JuliaMath(uint stopIteration, float realJuliaParameter, float imaginaryJuliaParameter) : FractaleMath(stopIteration)
	    {
		this->realJuliaFactor = realJuliaParameter;
		this->imaginaryJuliaFactor = imaginaryJuliaParameter;
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	__device__
	virtual ~JuliaMath()
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:


    private:

	__device__
	void f(float x, float y, float* ptrHue)
		    {

			float a = x;
			float b = y;
			float aCopy = 0.f;
			int k = 0.f;
			while((pow(a,2)+pow(b,2))<=4 && k<stopIteration)
			    {
				aCopy =a ;
				a = pow(aCopy,2)-pow(b,2) + realJuliaFactor;
				b = (2.f*aCopy*b) + imaginaryJuliaFactor;
				k+=1;
			    }

			if (k<stopIteration)
			    {
				*ptrHue = (float)k/stopIteration;
			    }
			else
			    {
				*ptrHue = 0.f;
			    }
		    }



	/*--------------------------------------*\
	|*		Attribut			*|
	 \*-------------------------------------*/

    private:

	// Tools
	int stopIteration;
	float realJuliaFactor;
	float imaginaryJuliaFactor;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

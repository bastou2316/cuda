#pragma once
#include <iostream>
#include <math.h>
#include "MathTools.h"

#include "ColorTools_GPU.h"
#include "FractaleMath.h"
using std::cout;
using std::endl;
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelBrothMath : public FractaleMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__ MandelBrothMath(uint stopIteration) : FractaleMath(stopIteration)
	    {
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	__device__ virtual ~MandelBrothMath()
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
		float a = 0;
		float b = 0;
		float aCopy = 0;
		float k = 0.f;
		while(((pow(a,2)+pow(b,2))<=4.f) && k<=stopIteration)
		    {
			aCopy =a ;
			a = pow(aCopy,2)-pow(b,2) + x;
			b = (2.f*aCopy*b) + y;
			k+=1;
		    }

		if (k<stopIteration)
		    {
			*ptrHue = k/stopIteration;
		    }
		else
		    {
			*ptrHue = -1.f;
		    }
	    }



	/*--------------------------------------*\
	|*		Attribut			*|
	 \*-------------------------------------*/

    private:

	// Tools
	int stopIteration;
    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

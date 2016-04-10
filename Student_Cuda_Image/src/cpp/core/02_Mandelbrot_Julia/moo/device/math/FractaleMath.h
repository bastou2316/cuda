#pragma once

#include <math.h>
#include "MathTools.h"

#include "ColorTools_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class FractaleMath
    {
	/*--------------------------------------*\
	|*		Constructeur		*|
	 \*-------------------------------------*/

    public:

	__device__ FractaleMath(uint stopIteration)
	    {
	    this->stopIteration = stopIteration;
	    }

	// constructeur copie: pas besoin car pas attribut ptr

	__device__ virtual ~FractaleMath(void)
	    {
	    // rien
	    }

	/*--------------------------------------*\
	|*		Methode			*|
	 \*-------------------------------------*/

    public:

	__device__
	void colorXY(uchar4* ptrColorXY, float x, float y)
	    {
		    float hue;

		    f(x, y, &hue);
		    //ColorTools::HSB_TO_RVB(hue,saturation,brightness,ptrColorXY);

		    if(hue < 0.f)
			{
			    ptrColorXY->x = 0.f;
			    ptrColorXY->y = 0.f;
			    ptrColorXY->z = 0.f;
			}
		    else
			{
			ColorTools::HSB_TO_RVB(hue,ptrColorXY);

			}


		    ptrColorXY->w = 255;
	    }

    private:

	__device__
	void f(float x, float y, float* ptrHue)
	    {
			/*TO USE IN DAUGHTER CLASSES*/
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

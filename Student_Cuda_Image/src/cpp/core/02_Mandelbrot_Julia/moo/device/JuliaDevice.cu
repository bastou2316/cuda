#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"
#include "math/JuliaMath.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void julia(uchar* ptrDevPixels, uint w, uint h, uint stopIteration, float realJuliaParameter, float imaginaryJuliaParameter, DomaineMath domaineMath);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
__global__ void julia(uchar4* ptrDevPixels, uint w, uint h, uint stopIteration, float realJuliaParameter, float imaginaryJuliaParameter, DomaineMath domaineMath)
	    {
		JuliaMath juliaMath = JuliaMath(stopIteration, realJuliaParameter, imaginaryJuliaParameter);

		const int TID = Indice2D::tid();
		const int NB_THREAD = Indice2D::nbThread();
		const int WH = w * h ;
		int pixelI;
		int pixelJ;

		int s = TID;
		double x,y;
		while( s < WH)
		    {
		    IndiceTools::toIJ(s, w, &pixelI, &pixelJ);


		    domaineMath.toXY(pixelI, pixelJ, &x, &y);
		    juliaMath.colorXY(&ptrDevPixels[s], (float)x, (float)y);
		    s+= NB_THREAD;

		    }
	    }
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

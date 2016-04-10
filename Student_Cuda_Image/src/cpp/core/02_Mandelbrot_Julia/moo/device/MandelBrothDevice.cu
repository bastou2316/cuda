#include "Indice2D.h"
#include "cudaTools.h"
#include "Device.h"
#include "math/MandelBrothMath.h"

#include "IndiceTools_GPU.h"
#include "DomaineMath_GPU.h"
using namespace gpu;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

__global__ void mandelBroth(uchar* ptrDevPixels, uint w, uint h, uint stopIteration, DomaineMath domaineMath);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
__global__ void mandelBroth(uchar4* ptrDevPixels, uint w, uint h, uint stopIteration, DomaineMath domaineMath)
	    {
		MandelBrothMath mandelBrothMath = MandelBrothMath(stopIteration);

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
		    mandelBrothMath.colorXY(&ptrDevPixels[s], (float)x, (float)y);
		    s+= NB_THREAD;

		    }
	    }
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

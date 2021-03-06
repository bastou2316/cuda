#include "MathTools.h"
#include "Grid.h"
#include "MandelBrothProvider.h"
#include "../moo/host/MandelBroth.h"
using namespace gpu;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

Animable_I<uchar4>* MandelBrothProvider::createAnimable()
    {
	DomaineMath domaineMath =  DomaineMath(-2.1f,-1.3f,0.8f,1.3f);
	int dw = 32 * 60;
	int dh = 16 * 60;
	int n = 50;

	dim3 dg = dim3(32,2,1);
	dim3 db = dim3(16,16,1);
	Grid grid(dg,db);

	return new MandelBroth(grid, dw, dh, n, domaineMath);
    }

Image_I* MandelBrothProvider::createImageGL(void)
    {
	ColorRGB_01 colorTexte(0,1,0);
	return new ImageAnimable_RGBA_uchar4(createAnimable(), colorTexte);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

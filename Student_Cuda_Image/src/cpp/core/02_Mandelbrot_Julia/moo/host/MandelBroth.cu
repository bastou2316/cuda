#include <iostream>
#include <assert.h>
#include "Device.h"
#include "MandelBroth.h"
#include "Fractale.h"

using std::cout;
using std::endl;


/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/
/*
 * IMPORTED
 *
 * */

extern __global__ void mandelBroth(uchar4* ptrDevPixels, uint w, uint h, uint n, DomaineMath domaineMath);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

MandelBroth::MandelBroth(const Grid& grid, uint w, uint h, uint n, const DomaineMath& domaineMath) : Fractale (grid, w, h, n, domaineMath)
    {
	this->n = n;
    }
MandelBroth::~MandelBroth()
    {

    }

void MandelBroth::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
	Device::lastCudaError("Mandelbroth BEFORE");
	mandelBroth<<<dg,db>>>(ptrDevPixels, w, h, n, domaineMath);
	Device::lastCudaError("mandelbroth AFTER");
    }
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

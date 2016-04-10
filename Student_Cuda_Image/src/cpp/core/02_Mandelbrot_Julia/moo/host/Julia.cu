#include <iostream>
#include <assert.h>
#include "Device.h"
#include "Julia.h"
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

extern __global__ void julia(uchar4* ptrDevPixels, uint w, uint h, uint n, float realJuliaParameter, float imaginaryJuliaParameter, DomaineMath domaineMath);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

Julia::Julia(const Grid& grid, uint w, uint h, uint n, float realJuliaParameter, float imaginaryJuliaParameter, const DomaineMath& domaineMath) :
	Fractale(grid, w, h, n, domaineMath)
    {
    this->realJuliaParameter = realJuliaParameter;
    this->imaginaryJuliaParameter = imaginaryJuliaParameter;
    }
Julia::~Julia()
    {

    }

void Julia::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
	Device::lastCudaError("Mandelbroth BEFORE");
    	julia<<<dg,db>>>(ptrDevPixels, w, h, n, realJuliaParameter, imaginaryJuliaParameter, domaineMath);
    	Device::lastCudaError("mandelbroth AFTER");
    }
/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

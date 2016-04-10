#include <iostream>
#include <assert.h>
#include "Device.h"
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

extern __global__ void fractale(uchar4* ptrDevPixels, uint w, uint h, uint n, float t, DomaineMath domaineMath);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

Fractale::Fractale(const Grid& grid, uint w, uint h, uint n, const DomaineMath& domaineMath) :
	Animable_I<uchar4>(grid, w, h, "Fractale CUDA", domaineMath)
    {
    this->n = n;
    this->t = 0.0f;
    }
Fractale::~Fractale()
    {

    }

void Fractale::process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath)
    {
	//TODO : CLASSE FILLES
    }


/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

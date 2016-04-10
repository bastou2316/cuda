
#pragma once

#include "cudaTools.h"
#include "MathTools.h"

#include "Animable_I_GPU.h"
#include "Fractale.h"
using namespace gpu;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Julia : public Fractale
    {
	public:
	    Julia(const Grid& grid, uint w, uint h, uint n, float realJuliaParameter, float imaginaryJuliaParameter, const DomaineMath& domaineMath);
	    virtual ~Julia(void);
	    virtual void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);
	private :
	    uint n;
	    float realJuliaParameter;
	    float imaginaryJuliaParameter;

    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

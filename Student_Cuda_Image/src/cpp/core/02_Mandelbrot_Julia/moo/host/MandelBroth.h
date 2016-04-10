
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

class MandelBroth : public Fractale
    {
	public:
	    MandelBroth(const Grid& grid, uint w, uint h, uint n, const DomaineMath& domaineMath);
	    virtual ~MandelBroth(void);
	    virtual void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);
	private :
	    uint n;

    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

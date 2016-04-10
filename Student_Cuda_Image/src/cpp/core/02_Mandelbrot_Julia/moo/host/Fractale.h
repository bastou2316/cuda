#pragma once

#include "cudaTools.h"
#include "MathTools.h"

#include "Animable_I_GPU.h"
using namespace gpu;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class Fractale : public Animable_I<uchar4>
    {
	public:
	    Fractale(const Grid& grid, uint w, uint h, uint n, const DomaineMath& domaineMath);
	    virtual ~Fractale(void);
	    virtual void process(uchar4* ptrDevPixels, uint w, uint h, const DomaineMath& domaineMath);
	    virtual void animationStep(){};
	private :
	    uint n;

    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

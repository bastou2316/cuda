
#pragma once
#include "cudaTools.h"
#include "Provider_I_GPU.h"
using namespace gpu;
/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class MandelBrothProvider
    {
    public:
	virtual ~MandelBrothProvider()
	    {

	    }
	virtual Animable_I<uchar4>* createAnimable(void);
	virtual Image_I* createImageGL(void);
    };


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

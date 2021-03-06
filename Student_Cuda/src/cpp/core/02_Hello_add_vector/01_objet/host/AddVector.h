#pragma once

#include "cudaTools.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

class AddVector
    {
	/*--------------------------------------*\
	|*		Constructor		*|
	 \*-------------------------------------*/

    public:

	/**
	 * update w by v1+v2
	 */
	AddVector(float* ptrV1, float* ptrV2, float* ptrW, int n);

	virtual ~AddVector(void);

	/*--------------------------------------*\
	|*		Methodes		*|
	 \*-------------------------------------*/

    public:

	void run();

	/*--------------------------------------*\
	|*		Attributs		*|
	 \*-------------------------------------*/

    private:

	// Inputs
	float* ptrV1;
	float* ptrV2;
	int n;

	// Inputs/Outputs
	float* ptrW;

	// Tools
	dim3 dg;
	dim3 db;
	float* ptrDevV1;
	float* ptrDevV2;
	float* ptrDevW;
	size_t sizeOctet;

    };

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

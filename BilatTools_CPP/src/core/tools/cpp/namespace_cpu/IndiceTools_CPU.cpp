#include "IndiceTools_CPU.h"

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

namespace cpu
    {

    /**
     * s[0,W*H[ --> i[0,H[ j[0,W[
     */
    void IndiceTools::toIJ( int s, int w, int* ptrI, int* ptrJ)
	{
	*ptrI = s / w;
	*ptrJ = s - w * (*ptrI);
	}

    /**
     * i[0,H[ j[0,W[ --> s[0,W*H[
     */
    int IndiceTools::toS(int W, int i, int j)
	{
	return (i * W) + j;
	}

    }
/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/


#include <iostream>

using std::cout;
using std::endl;

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useNameSpaceProcedure();

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

namespace v1
    {
    static int V = 1;

    static float value();
    }

namespace v2
    {
    static int V = 2;

    static float value();
    }

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

void useNameSpaceProcedure()
    {
    cout << endl<<"[Using Namespaces with procedures] :" << endl<<endl;
    float v1 = v1::value();
    float v2 = v2::value();

    cout << "value of v1 = " << v1 << " V = " << v1::V << endl;
    cout << "value of v2 = " << v2 << " V = " << v2::V << endl;
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * v1 est le name space
 */
float v1::value()
    {
    return 1.0f;
    }

/**
 * v2 est le name space
 */
float v2::value()
    {
    return 2.0f;
    }

/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/


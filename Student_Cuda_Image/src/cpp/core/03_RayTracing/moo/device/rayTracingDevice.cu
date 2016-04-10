//#include "Indice2D.h"
//#include "cudaTools.h"
//#include "Device.h"
//
//#include "IndiceTools_GPU.h"
//
//#include "RayTracingMath.h"
//using namespace gpu;
//
//// Attention : 	Choix du nom est impotant!
////		VagueDevice.cu et non Vague.cu
//// 		Dans ce dernier cas, probl�me de linkage, car le nom du .cu est le meme que le nom d'un .cpp (host)
////		On a donc ajouter Device (ou n'importequoi) pour que les noms soient diff�rents!
//
///*----------------------------------------------------------------------*\
// |*			Declaration 					*|
// \*---------------------------------------------------------------------*/
//
///*--------------------------------------*\
// |*		Imported	 	*|
// \*-------------------------------------*/
//
///*--------------------------------------*\
// |*		Public			*|
// \*-------------------------------------*/
//
//__global__ void RayTracing(uchar4* ptrDevPixels, uint w, uint h, float t);
//
///*--------------------------------------*\
// |*		Private			*|
// \*-------------------------------------*/
//
///*----------------------------------------------------------------------*\
// |*			Implementation 					*|
// \*---------------------------------------------------------------------*/
//
///*--------------------------------------*\
// |*		Public			*|
// \*-------------------------------------*/
//
//__global__ void RayTracing(uchar4* ptrDevPixels, uint w, uint h, float t)
//    {
//    RayTracingMath RayTracingMath = RayTracingMath(w, h);
//
//    const int TID = Indice2D::tid();
//    const int NB_THREAD = Indice2D::nbThread();
//    const int WH = w * h;
//
//    // TODO pattern entrelacement
//    int s = TID;
//
//    int pxI;
//    int pxJ;
//
//    while(s < WH)
//	{
//	IndiceTools::toIJ(s,w,&pxI,&pxJ);
//
//	RayTracingMath.colorXY(&ptrDevPixels[s],pxI, pxJ, t);
//	//ptrDevPixels[s] = color;
//	s += NB_THREAD;
//	}
//    }
//
///*--------------------------------------*\
// |*		Private			*|
// \*-------------------------------------*/
//
///*----------------------------------------------------------------------*\
// |*			End	 					*|
// \*---------------------------------------------------------------------*/
//

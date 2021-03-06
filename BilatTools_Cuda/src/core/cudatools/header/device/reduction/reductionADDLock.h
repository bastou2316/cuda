#pragma once

#include "Indice1D.h"
#include "Lock.h"

/*----------------------------------------------------------------------*\
 |*			Declaration 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Imported		*|
 \*-------------------------------------*/



/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

/**
 * Hyp
 * 	(H1) atomicAdd n'existe pas pour T , sinon utiliser la version in reductionADD.h
 * 	(H2) tabBlock size is a power of 2
 * 	(H3) tabBlock is already fill with data
 *
 *  Usage LockGPU
 *
 *  	// variable global .cu
 *  	__device__ int mutex=0;	// Attention � l'initialisation
 *
 *  	// Variable local inside kernel (same .cu as variable mutex)
 *  	LockGPU lock=LockGPU(&mutex);
 */
template <typename T>
__device__ void reductionADD(T* tabBlock, T* ptrDevResultat,Lock* ptrlock);

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

template <typename T>
static __device__ void reductionIntraBlock(T* tabBlock);

template <typename T>
static __device__ void reductionInterblock(T* tabBlock, T* ptrDevResultat,Lock* ptrlock);

/*----------------------------------------------------------------------*\
 |*			Implementation 					*|
 \*---------------------------------------------------------------------*/

/*--------------------------------------*\
 |*		Public			*|
 \*-------------------------------------*/

template <typename T>
__device__ void reductionADD(T* tabBlock, T* ptrDevResultat,Lock* ptrlock)
    {
    reductionIntraBlock(tabBlock);

    __syncthreads();

    reductionInterblock(tabBlock, ptrDevResultat,ptrlock);
    }

/*--------------------------------------*\
 |*		Private			*|
 \*-------------------------------------*/

/**
 * Hyp :
 * 	(H1) 	length(tabBlock) est une puissance de 2 ! ie blockDim.x est une puissance de 2
 * 	(H2) 	gride et Block de dim 1
 * 	(H3) 	T est un type simple suppoter par atomicAdd
 *
 */
template <typename T>
__device__ void reductionIntraBlock(T* tabBlock)
    {

    //v1
//    int midle = blockDim.x / 2;
//    int tidLocal = threadIdx.x;
//
//    // int tidLocal =   Indice1D::tidLocal()
//
//    while (midle >= 1)
//	{
//
//	if (tidLocal < midle)
//	    {
//	    tabBlock[tidLocal] += tabBlock[tidLocal + midle];
//	    }
//
//	__syncthreads();
//
//	//midle /= 2;
//	midle>>=1;
//	}

//v2
    int midle = blockDim.x / 2;
    int tidLocal = threadIdx.x;

    //a 64 on ne divise plus et on a besoin de 32 thread pour finir de reduire le 64 premi�res cases
    while (midle >= 64)
	{

	if (tidLocal < midle)
	    {
	    tabBlock[tidLocal] += tabBlock[tidLocal + midle];
	    }

	__syncthreads();

	//midle /= 2;
	midle>>=1;
	}

    // Utilisation des 32 thread d'un warp pour finir la reduction
    if(tidLocal<32)
	{
	// no __syncthreads() necessary after exah of the following lines as long as  we acces the data via a pointzer decalred as volatile
	// because teh 32 therad in each warp execute in a locked-step with each other
	volatile T* ptrData=tabBlock;

	ptrData[tidLocal]+=ptrData[tidLocal+32];
	ptrData[tidLocal]+=ptrData[tidLocal+16];
	ptrData[tidLocal]+=ptrData[tidLocal+8];
	ptrData[tidLocal]+=ptrData[tidLocal+4];
	ptrData[tidLocal]+=ptrData[tidLocal+2];
	ptrData[tidLocal]+=ptrData[tidLocal+1];
	}

    }

/**
 *  Hyp : ptrDevResultat iniotaiulias� avec 0 !!
 */
template <typename T>
__device__ void reductionInterblock(T* tabBlock, T* ptrDevResultat,Lock* ptrlock)
    {
    if (threadIdx.x == 0)
	{
	ptrlock->lock();
	*ptrDevResultat+= tabBlock[0];
	ptrlock->unlock();
	}
    }


/*----------------------------------------------------------------------*\
 |*			End	 					*|
 \*---------------------------------------------------------------------*/

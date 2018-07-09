// Code from DDEL 4/20/17
#include "bv.h"
#include <math.h>
#include "sieve.h"

void sieve(bitV *v)
{
	oneVec(v);
	clrBit(v, 0);
	clrBit(v, 1);
	setBit(v, 2);
	for(uint32_t i = 2; i <= sqrtl(lenVec(v)); i+= 1)
	{
		if(valBit(v, i))
		{
			for(uint32_t k = 0; (k + i) * i <= lenVec(v); k += 1)
			{
				clrBit(v, (k+i) * i);

			}
		}
	}
	return;
}

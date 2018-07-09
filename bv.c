#include <stdint.h>
#include "bv.h"
#include <stdlib.h>

bitV *newVec(uint32_t length) //Creates a new vector of specified length
{
	bitV* t;
	t = (bitV *)malloc(sizeof(uint8_t));
	t -> v = calloc(length/8, sizeof(uint8_t));
	t -> l = length;
	return t;	
}
void delVec(bitV *vector) //Deletes a vector
{
	free(vector);
	vector = NULL;
	return;
}
void oneVec(bitV *vector) //Creates a vector of all 1
{
	for(unsigned int i = 0; i < lenVec(vector); i++)
	{ 	
	vector -> v[i/8] |= ~(0x0 << i);
	}
	return;
}
void setBit(bitV *vector, uint32_t set) //Sets a specified bit
{
	vector -> v[set/8] |= (0x1 << (set & 0x7));
	return; 
}
void clrBit(bitV *vector, uint32_t clear) //Clears a specified bit
{
	vector -> v[clear/8] &= ~(0x1 << (clear & 0x7));
	return;
}
uint8_t valBit(bitV *vector, uint32_t val) //Returns the value of a specified bit
{
	uint8_t test = (vector -> v[val >> 3] & (0x1 << (val & 0x7))) >> (val & 0x7);
	return test;	 
	
}
uint32_t lenVec(bitV *vector) //Return the length of the vector
{
	uint32_t test1 = (vector -> l);
	return test1;
}



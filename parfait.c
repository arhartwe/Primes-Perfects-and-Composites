#include <stdio.h>
#include "bv.h"
#include "sieve.h"
#include <math.h>
int main(void)
{
        bitV *vector = newVec(100000);
	sieve(vector);
	int primes;
	
	for(unsigned int i = 2; i < lenVec(vector) + 1; i++)  //loops through entirety of vector
	{
		if(valBit(vector,i) == 1) //checks for number of primes
                {
                        primes++;
                }
	}
	int prime[primes]; //create array based of size of the primes found
	int index = 0;
        for(unsigned int i = 2; i < lenVec(vector) + 1; i++) //loop through vector again
        {
                if(valBit(vector,i) == 1) //if prime, set value of prime array element, move to next index, and print prime value
                {	
			prime[index] = i;
			index++;
                        printf(" %d P \n",i);
                }

		else if(valBit(vector,i) != 1) //if not prime, must be composite
		{
			int composite = i;		
			printf(" %d C: ", i);
			int primeIndex = 0;
			int factor = prime[primeIndex]; //factor is equal to first prime value
			while(composite != 0) 
			{
				if(composite%factor != 0) //if not a factor, move to next index
				{
					primeIndex++;   
					factor = prime[primeIndex];
				}
				else
				{
					composite  = composite / factor; //if it is a factor, divide current number by factor
					printf("%d ", factor);	//print factors
					if(composite == 1) //breaks out to continue
					{
						break;
					}			
				}
			}
			printf("\n");
			unsigned int  start,sum;
			int size = 0;
			start = 1;
			sum = 0;

			while(start < i) //while first possible factor is less than index
			{
				if(i%start == 0) //if number is a factor
				{
					size++;		//size used to create array of factors
					sum = sum+start; //sum used to determine perfect number
				}
				start++; //increment number to find next factor
			}
			
			int perfectFactors[size];
			unsigned int start2 = 1;
			int perfectIndex = 0;
                        
       
                        while(start2 < i)  //same loop as before, this time using the array of factors
			{
				if(i%start2 == 0)
				{
				 perfectFactors[perfectIndex] = start2; //stores factors in array
				 perfectIndex++;
				}
			start2++;
			}
			if(sum == i) //if sum of factors equals number
			{	 
				printf(" %d E: ", i);
				for(int k = 0; k < perfectIndex; k++)  //print out all factors that were stored in array
                       	        {
					printf("%d ", perfectFactors[k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

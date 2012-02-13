#include<avr/io.h>
#include<util/delay.h>

//Power-HIGH:
int segDispPH[]={63,6,91,79,102,109,125,7,127,111};

//Power-LOW:
int segDispPL[]={192,249,164,176,153,146,130,248,128,144};


int main()
{
	DDRC=255;
	int i=0;

	while(1)
	{
		PORTC=segDispPL[i];
		i++;
		i%=10; //i ranges from 0~9
	}

	return 0;
}


/*
 * Just For your Information:
 * PL=~PH=(1<<8)-1-PH=11111111-PH=255-PH
 * 
 * Power-HIGH (PH) mode:
{
//0:
(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<4) |
(1<<5),

//1
(1<<1) |
(1<<2),

//2
(1<<0) |
(1<<1) |
(1<<6) |
(1<<4) |
(1<<3),

//3
(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<6),

//4
(1<<1) |
(1<<2) |
(1<<5) |
(1<<6),

//5
(1<<0) |
(1<<5) |
(1<<6) |
(1<<2) |
(1<<3),

//6
(1<<0) |
(1<<5) |
(1<<6) |
(1<<2) |
(1<<3) |
(1<<4),

//7
(1<<0) |
(1<<1) |
(1<<2),

//8
(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<4) |
(1<<5) |
(1<<6),

//9
(1<<0) |
(1<<1) |
(1<<2) |
(1<<3) |
(1<<5) |
(1<<6)
};
// */
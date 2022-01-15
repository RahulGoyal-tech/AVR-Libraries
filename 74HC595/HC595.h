#ifndef HC595
#define HC595
/*
 * 74HC595.h
 *
 * Created: 14-12-2021 08:56:53 AM
 * Author : Rahul Goyal
 */ 

#include <avr/io.h>
#include <pinPort.h>

int dsPort;
int dsPin;
int shPort;
int shPin;
int stPort;
int stPin;

void HC595_init(int DSPORT, int DSPIN, int SHPORT, int SHPIN, int STPORT, int STPIN){
	//Function to assign pin numbers and set pins as o/p
	pinPortDir(DSPORT,DSPIN,1);
	pinPortDir(SHPORT,SHPIN,1);
	pinPortDir(STPORT,STPIN,1);
	dsPort = DSPORT;
	dsPin = DSPIN;
	shPort = SHPORT;
	shPin = SHPIN;
	stPort = STPORT;
	stPin = STPIN;
}

void HC595_pulse(){
	pinPortVal(shPort, shPin, 1);
	pinPortVal(shPort, shPin, 0);
}

void HC595_MSBFirst(int HC595_Data){
	//Sending 8bit data in MSB First order
	for (uint8_t j=0; j<8; j++)
	{
		if (HC595_Data & 0b10000000){ //Comparing if current(MSB) bit is high
			pinPortVal(dsPort, dsPin, 1);
		}
		else{
			pinPortVal(dsPort, dsPin, 0);
		}
		HC595_pulse(); //giving a clock pulse so 595 gets data
		HC595_Data = HC595_Data<<1; //Left Shift Data
	}
}

void HC595_LSBFirst(int HC595_Data){
	//Sending 8bit data in LSB First order
	for (uint8_t j=0; j<8; j++)
	{
		if (HC595_Data & 0b00000001){//Comparing if current(LSB) bit is high
			pinPortVal(dsPort, dsPin, 1);
		}
		else{
			pinPortVal(dsPort, dsPin, 0);
		}
		HC595_pulse(); //giving a clock pulse so 595 gets data
		HC595_Data = HC595_Data>>1; //Right Shift Data
	}
}

void HC595_write(int HC595_data,int HC595_bits,uint8_t order){
	float rem = HC595_bits%8; //checking no. of 8bits/ no. of shift registers
	if (rem>0)
	{
		HC595_bits = (HC595_bits/8)+1;
	}
	else{
		HC595_bits = HC595_bits/8;
	}
	pinPortVal(stPort, stPin, 0);
	if (!order){//MSB
		for(int i=0; i<HC595_bits; i++){ //writing 8bit data no. of times bit available
			HC595_MSBFirst(HC595_data);//writing 8 bit data
		}
	}
	else{//LSB
		for(int i=0; i<HC595_bits; i++){//writing 8bit data no. of times bit available
			HC595_LSBFirst(HC595_data);//writing 8 bit data
		}
	}
	pinPortVal(stPort, stPin, 1);
}
#endif HC595
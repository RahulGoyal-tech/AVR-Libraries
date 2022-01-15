#ifndef LCDavr.h
#define LCDavr.h

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LCDData PORTB
#define Enable 5
#define LCDControl PORTD
#define RW 7
#define RS 2
#define ControlDir DDRD
#define DataDir DDRB

void busy(void);
void flash(void);
void sendCmd(unsigned char cmd);
void sendChar(unsigned char ch);
void sendStr(char *word);
void curLoc(uint8_t x, uint8_t y);
void sendStrLoc(uint8_t x, uint8_t y, char *word);
void sendIntLoc(uint8_t x, uint8_t y, int num, int maxdig);
void sendStrDel(char *word);
void lcdInit(void);
void curOff(void);
void curOn(void);
char colPos[2] = {0,64};

void curOff(){
	sendCmd(0b00001100);
	_delay_ms(50);
}

void curOn(){
	sendCmd(0b00001110);
	_delay_ms(50);
}

void lcdInit(){
	ControlDir |= 1<<Enable|1<<RW|1<<RS;
	_delay_ms(15);
	
	sendCmd(0x01);
	_delay_ms(2);
	
	sendCmd(0x38);
	_delay_ms(50);
	
	sendCmd(0b00001110);
	_delay_ms(50);
}

void busy(){
	DataDir = 0;
	LCDControl |= (1<<RW);
	LCDControl &= ~(1<<RS);
	
	while (LCDData >= 0x80)
	{
		flash();
	}
	DataDir = 0xFF;
}

void flash(){
	LCDControl |= (1<<Enable);
	
	asm volatile("nop");
	asm volatile("nop");
	
	LCDControl &= ~(1<<Enable);
}

void sendCmd(unsigned char cmd){
	busy();
	LCDData = cmd;
	LCDControl &= ~(1<<RW|1<<RS);
	flash();
	LCDData = 0;
}

void sendChar(unsigned char ch){
	busy();
	LCDData = ch;
	LCDControl &= ~(1<<RW);
	LCDControl |= (1<<RS);
	flash();
	LCDData = 0;
}

void sendStr(char *word){
	
	while (*word>0)
	{
		sendChar(*word++);
	}
}

void curLoc(uint8_t x, uint8_t y){
	
	sendCmd(0x80 + colPos[y-1] + (x-1));
}

void sendStrLoc(uint8_t x, uint8_t y, char *word){
	
	curLoc(x,y);
	sendStr(word);
}

void sendIntLoc(uint8_t x, uint8_t y, int num, int maxdig){
	char String[maxdig];
	itoa(num, String, 10);
	sendStrLoc(x,y,String);
}

void sendStrDel(char *word){
	
	while (*word>0)
	{
		sendChar(*word++);
		_delay_ms(500);
	}
}

#endif
#include <stdio.h>
#include <wiringPi.h>
#include <mcp23017.h>
#include <lcd.h>

#define AF_BASE         100
#define AF_RED          (AF_BASE + 6)
#define AF_GREEN        (AF_BASE + 7)
#define AF_BLUE         (AF_BASE + 8)

#define AF_E            (AF_BASE + 13)
#define AF_RW           (AF_BASE + 14)
#define AF_RS           (AF_BASE + 15)

#define AF_DB4          (AF_BASE + 12)
#define AF_DB5          (AF_BASE + 11)
#define AF_DB6          (AF_BASE + 10)
#define AF_DB7          (AF_BASE +  9)

#define AF_SELECT       (AF_BASE +  0)
#define AF_RIGHT        (AF_BASE +  1)
#define AF_DOWN         (AF_BASE +  2)
#define AF_UP           (AF_BASE +  3)
#define AF_LEFT         (AF_BASE +  4)

int main ()
{
	wiringPiSetup();
	mcp23017Setup(AF_BASE, 0x20);

	pinMode(AF_RED, OUTPUT);
	pinMode(AF_GREEN, OUTPUT);
	pinMode(AF_BLUE, OUTPUT);

	digitalWrite(AF_RED, HIGH);
	digitalWrite(AF_GREEN, LOW);
	digitalWrite(AF_BLUE, HIGH);

	// Buttons 
	int i;
	for (i = 0; i <= 4; i++)
	{
		pinMode(AF_BASE + i, INPUT);
		pullUpDnControl(AF_BASE + i, PUD_UP);
	}

	// Unused & off
	pinMode(AF_RW, OUTPUT);
	digitalWrite(AF_RW, HIGH);

	int lcd;
	lcd = lcdInit(2, 16, 4, AF_RS, AF_E, AF_DB4, AF_DB5, AF_DB6, AF_DB7, 0, 0, 0, 0);

	// Useless shit down here
	unsigned char d[6][8] =
	{
		{0, 0, 0, 0, 0, 14, 9, 21},
		{0, 0, 0, 1, 2, 30, 31, 31},
		{0, 0, 0, 24, 4, 20, 31, 31},
		{31, 31, 15, 0, 0, 0, 0, 0},
		{31, 28, 24, 0, 0, 0, 0, 0},
		{28, 0, 0, 0, 0, 0, 0, 0},
	};
	for (i = 0; i <= 5; i++ )
	{
		lcdCharDef(lcd, i, d[i]);
	}

	lcdPosition(lcd, 0,0);
	lcdPutchar(lcd, 0);
	lcdPutchar(lcd, 1);
	lcdPutchar(lcd, 2);
	lcdPosition(lcd, 0,1);
	lcdPutchar(lcd, 3);
	lcdPutchar(lcd, 4);
	lcdPutchar(lcd, 5);

	lcdPosition(lcd, 4, 0);
	lcdPuts(lcd, "kavacky.lv");
	
	// lel
	while (HIGH)
	{
		lcdPosition(lcd, 4, 1);
		if (digitalRead(AF_SELECT) == LOW)
		{
			lcdPuts(lcd, "pls        ");
		}
		else
		{
			lcdPuts(lcd, "y u do dis?");
		}
		usleep(1000 * 100);
	}

	return 0 ;
}

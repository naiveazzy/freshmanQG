
#include <REGX52.H>
#include <intrins.h>

#define u8 unsigned char
#define u16 unsigned int

sbit led_gio = P2^5;
sbit dled_gio1 = P2^1;
sbit dled_gio2 = P2^2;
sbit dled_gio3 = P2^3;
sbit dled_gio4 = P2^4;
sbit led_io1 = P0^0;
sbit led_io2 = P0^1;
sbit led_io3 = P0^2;
sbit led_io4 = P0^3;
sbit led_io5 = P0^4;
sbit led_io6 = P0^5;
sbit led_io7 = P0^6;
sbit led_io8 = P0^7;
sbit led_dp = P2^6;

sbit buttons_io1 = P1^0;
sbit buttons_io2 = P1^1;
sbit buttons_io3 = P1^2;
sbit buttons_io4 = P1^3;
sbit buttons_io5 = P1^4;
sbit buttons_io6 = P1^5;
sbit buttons_io7 = P1^6;
sbit buttons_io8 = P1^7;

u16 ReadPassword();
void ShowNumber(u16 number);
u8 ButtonCheck();
void DLEDCount(int number, int count);
void Delay1ms(void);
void Delay1000ms(void);
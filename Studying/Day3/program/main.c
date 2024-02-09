#include <REGX52.H>
#include <intrins.h>

#define MODE 2

sbit LED_pin = P1^7;
sbit BUTTON_pin = P1^6;

void Delay1000ms(void);

#if MODE == 1
int main(void) {
    LED_pin = 0;
    
    while(1) {
        LED_pin = 1;
        Delay1000ms();
        LED_pin = 0;
        Delay1000ms();
    }
}
#endif

#if MODE == 2
int main(void) {
		LED_pin = 0;
	
		while(1) {
			BUTTON_pin = 1;
			if (BUTTON_pin == 0) {
					LED_pin = 1;
			} else {
					LED_pin = 0;
			}
		}
}
#endif

void Delay1000ms(void)	//@11.0592MHz
{
	unsigned char data i, j, k;

	_nop_();
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

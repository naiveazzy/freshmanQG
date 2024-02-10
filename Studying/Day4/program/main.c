/*
		板子上驱动LED与数码管的控制引脚为P0，数码管的dp口另用P2^6。
		四位数码管的接地控制引脚为P2^1至P2^4，LED的接地控制引脚为P2^5。
		由于IO口电流限制，同时点亮LED和数码管或数码管四位数字时LED亮度下降。
		LED与数码管引脚定义存于本地目录的pin.h中
*/

#include <REGX52.H>
#include <intrins.h>
#include "pin.h"


//MODE变量用于程序呈现某个功能的程序
//1为流水灯，2为静态循环显示数码管，3为动态显示数码管
#define MODE 3

void Delay1ms(void);
void Delay1000ms(void);
void DLEDCount(int number, int count);

#if MODE == 1
void main() {
	int i;
	
	led_gio = 1;
	dled_gio1 = 0;
	dled_gio2 = 0;
	dled_gio3 = 0;
	dled_gio4 = 0;
	
	while(1) {
		P0 = 0x01;
		for (i = 0; i < 8; i++) {
			Delay1000ms();
			P0 <<= 1;
		}
	}
}
#endif

#if MODE == 2
void main() {
	int i;
	
	// 初始化所有接地设置
	led_gio = 0;
	dled_gio1 = 0;
	dled_gio2 = 0;
	dled_gio3 = 0;
	dled_gio4 = 0;
	
	while(1) {
		
		// 在for循环中利用DLEDCount显示i到数码管最左位
		for (i = 0; i < 16; i++) {
			DLEDCount(i, 1);
			Delay1000ms();
		}
	}
}
#endif

#if MODE == 3
void main() {
	int i;
	
	// 初始化所有接地设置
	led_gio = 0;
	dled_gio1 = 0;
	dled_gio2 = 0;
	dled_gio3 = 0;
	dled_gio4 = 0;
	
	//在while循环中设置某一位数码管显示数字，
	//延迟1毫秒后设置下一个数码管显示，实现动态显示的效果
	while(1) {
		DLEDCount(2, 1);
		Delay1ms();
		DLEDCount(0, 2);
		Delay1ms();
		DLEDCount(2, 3);
		Delay1ms();
		DLEDCount(4, 4);
		Delay1ms();
	}
}
#endif


/*
	让数码管显示指定数字（number为16进制）
	count为指定某位的数码管（0~3)
*/
void DLEDCount(int number, int count)
{
	P2 = 1;
	
	//右移count位实现点亮某个数码管
	//即设置P2^1到P2^4的某位为1
	P2 <<= count;
	switch(number) {
		
		//根据number设置P0显示想要的字符
		case 0: P0 = 63; break;
		case 1: P0 = 6; break;
		case 2: P0 = 91; break;
		case 3: P0 = 79; break;
		case 4: P0 = 102; break;
		case 5: P0 = 109; break;
		case 6: P0 = 125; break;
		case 7: P0 = 7; break;
		case 8: P0 = 127; break;
		case 9: P0 = 111; break;
		case 10: P0 = 119; break;
		case 11: P0 = 124; break;
		case 12: P0 = 57; break;
		case 13: P0 = 94; break;
		case 14: P0 = 121; break;
		case 15: P0 = 113; break;
		
		//其他情况显示H（超出显示范围）
		default: P0 = 118; break;
	}
}

void Delay1ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	_nop_();
	_nop_();
	i = 11;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}


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

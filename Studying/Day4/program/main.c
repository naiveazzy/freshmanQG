/*
		����������LED������ܵĿ�������ΪP0������ܵ�dp������P2^6��
		��λ����ܵĽӵؿ�������ΪP2^1��P2^4��LED�Ľӵؿ�������ΪP2^5��
		����IO�ڵ������ƣ�ͬʱ����LED������ܻ��������λ����ʱLED�����½���
		LED����������Ŷ�����ڱ���Ŀ¼��pin.h��
*/

#include <REGX52.H>
#include <intrins.h>
#include "pin.h"


//MODE�������ڳ������ĳ�����ܵĳ���
//1Ϊ��ˮ�ƣ�2Ϊ��̬ѭ����ʾ����ܣ�3Ϊ��̬��ʾ�����
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
	
	// ��ʼ�����нӵ�����
	led_gio = 0;
	dled_gio1 = 0;
	dled_gio2 = 0;
	dled_gio3 = 0;
	dled_gio4 = 0;
	
	while(1) {
		
		// ��forѭ��������DLEDCount��ʾi�����������λ
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
	
	// ��ʼ�����нӵ�����
	led_gio = 0;
	dled_gio1 = 0;
	dled_gio2 = 0;
	dled_gio3 = 0;
	dled_gio4 = 0;
	
	//��whileѭ��������ĳһλ�������ʾ���֣�
	//�ӳ�1�����������һ���������ʾ��ʵ�ֶ�̬��ʾ��Ч��
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
	���������ʾָ�����֣�numberΪ16���ƣ�
	countΪָ��ĳλ������ܣ�0~3)
*/
void DLEDCount(int number, int count)
{
	P2 = 1;
	
	//����countλʵ�ֵ���ĳ�������
	//������P2^1��P2^4��ĳλΪ1
	P2 <<= count;
	switch(number) {
		
		//����number����P0��ʾ��Ҫ���ַ�
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
		
		//���������ʾH��������ʾ��Χ��
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

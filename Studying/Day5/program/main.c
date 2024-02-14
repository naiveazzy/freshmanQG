#include "head.h"

void main() {
	u16 password;
	u16 i;
	while(1) {
		password = ReadPassword();
		
		while(1) {
			if (password == ReadPassword()) {
				for (i = 0; i < 100; i++) {
					DLEDCount(21, 1);
					Delay1ms();
					DLEDCount(21, 2);
					Delay1ms();
					DLEDCount(21, 3);
					Delay1ms();
					DLEDCount(21, 4);
					Delay1ms();
				}
				break;
			}	
		}
	}
}


u16 ReadPassword() {
	u8 i = 1;
	u16 durat = 0;
	u16 password = 0x0000;
	u8 button;
	
	while(i <= 4) {
		ShowNumber(password);
		if ((button = ButtonCheck()) != 0) {
			button--;
			password += button << (16 - 4*i);
			for (durat = 0; durat < 10; durat++) {
				ShowNumber(password);
			}
			i++;
		}
	}
	
	return password;
}
		
		
		

void ShowNumber(u16 number) {
	u16 cache;
	u8 i;
	
	for (i = 0; i < 16; i+=4) {
		cache = number<<i;
		cache >>= 12;
		DLEDCount(cache, i/4 + 1);
		Delay1ms();
	}
}

/*
	��鵱ǰ���°�ť������1-16��λ���������ʾ��Ϊ���������϶���
	ͨ�������ж�Ӧ�İ˸����ŷ����飬�ֱ����ߺ�
	�ټ�ⱻ�������ţ�����ⱻ���µİ�ť
*/
u8 ButtonCheck() {
	u8 row;
	u8 column;
	
	P1 = 0x0f;
	row = P1 ^ 0x0f;
	
	switch(row) {
		case 1: row = 0; break;
		case 2: row = 1; break;
		case 4: row = 2; break;
		case 8: row = 3; break;
	}
	
	P1 = 0xf0;
	column = P1 ^ 0xf0;
	column >>= 4;
	
	switch(column) {
		case 1: column = 1; break;
		case 2: column = 2; break;
		case 4: column = 3; break;
		case 8: column = 4; break;
	}
	
	return row * 4 + column;
}


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
		case 20: P0 = 0; break;
		case 21: P0 = 8; break;
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
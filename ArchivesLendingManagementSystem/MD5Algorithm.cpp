#pragma once
#include "MD5Algorithm.h"
//private
void MD5Algorithm::mainLoop(unsigned int M[])
{
	unsigned int f, g;
	unsigned int a = atemp;
	unsigned int b = btemp;
	unsigned int c = ctemp;
	unsigned int d = dtemp;
	for (unsigned int i = 0; i < 64; i++)
	{
		if (i < 16) {
			f = F(b, c, d);
			g = i;
		}
		else if (i < 32)
		{
			f = G(b, c, d);
			g = (5 * i + 1) % 16;
		}
		else if (i < 48) {
			f = H(b, c, d);
			g = (3 * i + 5) % 16;
		}
		else {
			f = I(b, c, d);
			g = (7 * i) % 16;
		}
		unsigned int tmp = d;
		d = c;
		c = b;
		b = b + shift((a + f + k[i] + M[g]), s[i]);
		a = tmp;
	}
	atemp = a + atemp;
	btemp = b + btemp;
	ctemp = c + ctemp;
	dtemp = d + dtemp;
}

unsigned int* MD5Algorithm::add(
	string str)
{
	unsigned int num = ((str.length() + 8) / 64) + 1; //��512λ,64���ֽ�Ϊһ��
	unsigned int* strByte = new unsigned int[num * 16]; //64/4=16,������16������
	strlength = num * 16;
	for (unsigned int i = 0; i < num * 16; i++)
		strByte[i] = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		strByte[i >> 2] |= (str[i]) << ((i % 4) * 8); //һ�������洢�ĸ��ֽڣ�i>>2��ʾi/4 һ��unsigned int��Ӧ4���ֽڣ�����4���ַ���Ϣ
	}
	strByte[str.length() >> 2] |= 0x80 << (((str.length() % 4)) * 8); //β�����1 һ��unsigned int����4���ַ���Ϣ,������128����
	/*
	*���ԭ���ȣ�����ָλ�ĳ��ȣ�����Ҫ��8��Ȼ����С�������Է��ڵ����ڶ���,���ﳤ��ֻ����32λ
	*/
	strByte[num * 16 - 2] = str.length() * 8;
	return strByte;
}

string MD5Algorithm::changeHex(int a)
{
	int b;
	string str1;
	string str = "";
	for (int i = 0; i < 4; i++)
	{
		str1 = "";
		b = ((a >> i * 8) % (1 << 8)) & 0xff; //������ÿ���ֽ�
		for (int j = 0; j < 2; j++)
		{
			str1.insert(0, 1, str16[b % 16]);
			b = b / 16;
		}
		str += str1;
	}
	return str;
}

string MD5Algorithm::getMD5(string source)
{
	atemp = A;  //��ʼ��
	btemp = B;
	ctemp = C;
	dtemp = D;
	unsigned int* strByte = add(source);
	for (unsigned int i = 0; i < strlength / 16; i++)
	{
		unsigned int num[16];
		for (unsigned int j = 0; j < 16; j++)
			num[j] = strByte[i * 16 + j];
		mainLoop(num);
	}
	return changeHex(atemp).append(changeHex(btemp)).append(changeHex(ctemp)).append(changeHex(dtemp));
}

//public
string MD5Algorithm::returnMD5()
{
	return MD5;
}

MD5Algorithm::MD5Algorithm(string _s)
{
	MD5 = getMD5(_s);
	MD5 = getMD5(MD5);
}

MD5Algorithm::~MD5Algorithm()
{

}
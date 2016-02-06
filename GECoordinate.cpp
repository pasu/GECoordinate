// GECoordinate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

void calculate(float& fLat1,float& fLat2,float& fLon1,float& fLon2, const string& strNumber)
{
	fLat1 = 180;
	fLon1 = -180;

	fLat2 = -180;
	fLon2 = 180;

	int i = 2;
	int nLength = strNumber.length();

	for (i=1;i<nLength;i++)
	{
		char nCurrentNumber = strNumber[i];
		if(nCurrentNumber == '0')
		{
			fLat1 = (fLat1 + fLat2) / 2.0;
			fLon1 = fLon1;

			fLat2 = fLat2;
			fLon2 = (fLon1 + fLon2) / 2.0;
		}
		else if(nCurrentNumber == '1')
		{
			fLat1 = (fLat1 + fLat2) / 2.0;
			fLon2 = fLon2;

			fLat2 = fLat2;
			fLon1 = (fLon1 + fLon2) / 2.0;
		}
		else if(nCurrentNumber == '2')
		{
			fLat2 = (fLat1 + fLat2) / 2.0;
			fLon2 = fLon2;

			fLat1 = fLat1;
			fLon1 = (fLon1 + fLon2) / 2.0;
		}
		else if(nCurrentNumber == '3')
		{
			fLat2 = (fLat1 + fLat2) / 2.0;
			fLon1 = fLon1;

			fLat1 = fLat1;
			fLon2 = (fLon1 + fLon2) / 2.0;
		}
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//string strNumber = "02031200112103300";
	string strNumber = "0";
	
	float fLat1,fLat2,fLon1,fLon2;
	
	calculate(fLat1,fLat2,fLon1,fLon2,strNumber);

	cout<<strNumber<<":"<<endl;
	cout<<"Longitude:"<<fLon1<<"~"<<fLon2<<endl;
	cout<<"Latitude:"<<fLat1<<"~"<<fLat2<<endl;
	cout<<"Level:"<<strNumber.length()<<endl;
	cout<<endl<<endl;

	strNumber = "020";

	calculate(fLat1,fLat2,fLon1,fLon2,strNumber);

	cout<<strNumber<<":"<<endl;
	cout<<"Longitude:"<<fLon1<<"~"<<fLon2<<endl;
	cout<<"Latitude:"<<fLat1<<"~"<<fLat2<<endl;
	cout<<"Level:"<<strNumber.length()<<endl;
	cout<<endl<<endl;

	strNumber = "02031200112103300";

	calculate(fLat1,fLat2,fLon1,fLon2,strNumber);

	cout<<strNumber<<":"<<endl;
	cout<<"Longitude:"<<fLon1<<"~"<<fLon2<<endl;
	cout<<"Latitude:"<<fLat1<<"~"<<fLat2<<endl;
	cout<<"Level:"<<strNumber.length()<<endl;
	cout<<endl<<endl;
	return 0;
}

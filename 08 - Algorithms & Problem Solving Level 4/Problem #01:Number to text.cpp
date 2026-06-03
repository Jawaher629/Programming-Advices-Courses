#include <iostream>
#include <string>
using namespace std;

string ConvertNumberToText(long int Number)
{
	if (Number == 0)
		return "";
	if (Number >= 1 && Number <= 19)
	{
		string arr1[] = { "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return arr1[Number];
	}
	if (Number >= 20 && Number <= 99)
	{
		string arr1[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
		return arr1[Number / 10] + " " + ConvertNumberToText(Number % 10);
	}
	if (Number >= 100 && Number <= 199)
	{
		return "One Hundred " + ConvertNumberToText(Number % 100);
	}
	if (Number >= 200 && Number <= 999)
	{
		return ConvertNumberToText(Number / 100) + " Hundreds " + ConvertNumberToText(Number % 100);
	}
	if (Number >= 1000 && Number <= 1999)
	{
		return "One Thousand " + ConvertNumberToText(Number % 1000);
	}
	if (Number >= 2000 && Number <= 999999)
	{
		return ConvertNumberToText(Number / 1000) + " Thousands " + ConvertNumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 1999999)
	{
		return "One Million " + ConvertNumberToText(Number % 1000000);
	}
	if (Number >= 2000000 && Number <= 999999999)
	{
		return ConvertNumberToText(Number / 1000000) + " Millions " + ConvertNumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 1999999999)
	{
		return "One Billion " + ConvertNumberToText(Number % 1000000000);
	}
	else
	{
		return ConvertNumberToText(Number / 1000000000) + " Billions " + ConvertNumberToText(Number % 1000000000);
	}

}

long int ReadUserNumber(string Message)
{
	long int num = 0;
	cout << Message;
	cin >> num;
	return num;
}
int main()
{
	
	cout << ConvertNumberToText(ReadUserNumber("Enter number: ") ) << ".";

	system("pause>0");
	return 0;
}

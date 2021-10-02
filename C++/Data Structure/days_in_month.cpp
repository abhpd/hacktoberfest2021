#include <iostream>
using namespace std;

//function will return total number of days
int  getNumberOfDays(int month, int year)
{
	//leap year condition, if month is 2
	if( month == 2)
	{
		if((year%400==0) || (year%4==0 && year%100!=0))	
			return 29;
		else	
			return 28;
	}
	//months which has 31 days
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
	||month == 10 || month==12)	
		return 31;
	else 		
		return 30;
} 

//Main program
int main()
{
	int days=0;

	days = getNumberOfDays(2, 2016);

	cout<<endl<<"Number of Days :  "<<days;

	return 0;
}

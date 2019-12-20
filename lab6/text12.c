#include<stdio.h>
int isYear(int year)    
{
     
    return (year%4==0)&&( year %400==0 || year %100!= 0) ? 1:0;
}
int getDayOfMonth(int year , int month) 
{
     
    int dayArr[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
     
    return (month == 2 && isYear(year)==1) ? dayArr[month]+1 : dayArr[month] ;
}
int getTotalDay(int year1,int month1,int day1,int year2,int month2,int day2){
     
    long total = 0;
     
    for(int year = year1; year < year2 ;  year ++ )
    {
        total = total + 365;
        if(isYear(year)==1) 
            total ++;
    }
    for(int month =1; month < month2; month ++ )
    {
        total = total + getDayOfMonth(year2,month);
    }
    total = total + day2;
     
    for(int month=1 ; month < month1; month ++ )
    {
         total = total - getDayOfMonth(year1,month);
    }
     
    return total - day1;
     
}
int main()
{
     
    int year1 ,month1,day1;
    int year2, month2,day2;
     
    do{
            printf("please input year-month-day\n : ");
            scanf("%d-%d-%d", &year1,&month1,&day1);
    } while( year1 <0 || month1<1 || month1>12 || day1<1|| day1> getDayOfMonth(year1,month1));
 
     
    do{ 
            printf("Input year2-month2-day2\n : ");
            scanf("%d-%d-%d", &year2,&month2,&day2);
    } while( year2 <0 || year2 <year1|| month2<1 || month2>12 || day2<1|| day2> getDayOfMonth(year2,month2));
 
 
     
    printf("we have: %ld  days between \n", getTotalDay(year1,month1,day1,year2,month2,day2));
    return 0;
}
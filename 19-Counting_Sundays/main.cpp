/*
You are given the following information, but you may prefer to do some research for yourself.

    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

ANSWER : 171
*/

#include <iostream>
#include <stdint.h>

int main()
{
   uint32_t month_days[] = {31, 28, 31, 30, 31, 30 , 31, 31, 30, 31, 30 ,31};

   uint64_t sundays = 0;

   uint32_t year = 1900;
   uint32_t day = 0;
   uint32_t day_of_week = 1; // 0 is sunday

   for(uint32_t i = 0; i < 12; i++)
   {
      day += month_days[i];
   }

   day += day_of_week;

   year = 1901;

   day_of_week = (day % 7);
   day = 0;
   if(day_of_week == 0)
   {
      sundays++;
   }

   while(year < 2001)
   {
      for(uint32_t m = 0; m < 12; m++)
      {
         day += month_days[m] + day_of_week;
         if(m == 1)
         {
            if((year % 400) == 0)
            {
               day++;
            }
            else if((year % 100) == 0)
            {

            }
            else if((year % 4) == 0)
            {
               day++;
            }
         }
         day_of_week = (day % 7);

         day = 0;

         if(day_of_week == 0)
         {
            
            if((m != 11) || (year != 2000))
            {
               sundays++;
            }
         }
      }
      year++;
   }


   std::cout << "ans : " << sundays << '\n';
   std::cin.get();
   return 0;
}



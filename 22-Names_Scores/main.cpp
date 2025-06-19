/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
multiply this value by its alphabetical position in the list to obtain a name score.
For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
is the 938th name in the list. So, COLIN would obtain a score of 938 * 53 = 49714.
What is the total of all the name scores in the file?

ANS = 871198282
*/

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <stdlib.h>
#include <cstring>

void load_names(char* &names, uint32_t &max_length, uint32_t &names_count);
uint32_t longest_name(std::string &list, uint32_t &names_count);
void read_names(std::string &list, char* names, uint32_t longest);
void sort_names(char* &names, uint32_t max_length, uint32_t names_count);
uint64_t calculate_list_value(char* &names, uint32_t max_length, uint32_t names_count);

int main()
{
   char* names;

   uint32_t max_length;
   uint32_t names_count;

   load_names(names, max_length, names_count);
   sort_names(names, max_length, names_count);

   /*
   for(uint32_t i = 0; i < names_count; i++)
   {
      std::cout << (i+1) << " : ";

      for(uint32_t j = 0; j < max_length; j++)
      {
         std::cout<<names[(i * max_length) + j];
      }

      std::cout<<'\n';
   }
   */

   std::cout << "ANS = " << calculate_list_value(names, max_length, names_count) << '\n';

   

   free(names);

   std::cin.get();
   return 0;
}

void load_names(char* &names, uint32_t &max_length, uint32_t &names_count)
{
   std::fstream FILE;

   FILE.open("names.txt", std::ios::in);
   if(FILE.is_open() == false)
   {
      std::cout << "NOT GOOD!";
      std::cin.get();
      return;
   }

   std::string list;
   std::getline(FILE, list);
   FILE.close();

   max_length = longest_name(list, names_count);

   names = (char*)malloc(sizeof(char) * names_count * max_length);
   memset(names, ('A' - 1), sizeof(char) * names_count * max_length);

   read_names(list, names, max_length);
}

uint32_t longest_name(std::string &list, uint32_t &names_count)
{
   names_count = 0;

   uint32_t length = 0;
   uint32_t current_length = 0;

   uint32_t index = 0;

   uint32_t l = list.length();

   bool inside_name = false;

   while(true)
   {
      if(index >= l)
      {
         return length;
      }

      if(list[index] == '\"')
      {
         if(inside_name)
         {
            inside_name = false;
            
            if(length < current_length)
            {
               length = current_length;
            }

            index++;
            continue;
         }
         else
         {
            inside_name = true;
            names_count++;
            current_length = 0;
            index++;
            continue;
         }
         
      }

      if(inside_name)
      {
         current_length++;
      }

      index++;
   }
}

void read_names(std::string &list, char* names, uint32_t longest)
{

   uint32_t l = list.length();

   uint32_t index = 0;

   bool inside_name = false;

   uint32_t name_id = 0;
   uint32_t char_id = 0;

   while(true)
   {
      if(index >= l)
      {
         return;
      }

      if(list[index] == '\"')
      {
         if(inside_name)
         {
            inside_name = false;
            name_id++;
            index++;
            continue;
         }
         else
         {
            inside_name = true;
            char_id = 0;
            index++;
            continue;
         }
         
      }

      if(inside_name)
      {
         names[(name_id * longest) + char_id] = list[index];
         char_id++;
      }

      index++;
   }
}

void sort_names(char* &names, uint32_t max_length, uint32_t names_count)
{
   uint32_t char_index = max_length;

   uint32_t name_index;
   uint32_t check_name_index;

   char sorting_char;

   char* temp = (char*)malloc(sizeof(char) * max_length);

   // names[name_index * max_length + char_index]

   while(true)
   {
      char_index--;
      name_index = 0;
      check_name_index = 0;
      sorting_char = ('A' - 1);

      while(true)
      {
         if(names[(check_name_index * max_length) + char_index] == sorting_char)
         {
            if(check_name_index != name_index)
            {
               for(uint32_t i = 0; i < max_length; i++)
               {
                  temp[i] = names[(check_name_index * max_length) + i];
               }

               memmove(&(names[(name_index + 1) * max_length]), &(names[name_index * max_length]), ((check_name_index - name_index) * max_length));

               for(uint32_t i = 0; i < max_length; i++)
               {
                  names[(name_index * max_length) + i] = temp[i];
               }
            }
            name_index++;
         }

         check_name_index++;

         if(check_name_index >= names_count)
         {
            if(sorting_char == 'Z')
            {
               break;
            }

            sorting_char++;
            check_name_index = name_index;
         }
      }

      if(char_index == 0)
      {
         break;
      }
   }

   free(temp);
}

uint64_t calculate_list_value(char* &names, uint32_t max_length, uint32_t names_count)
{
   char sub = 'A' - 1;

   uint64_t sum = 0;

   for(uint32_t n = 0; n < names_count; n++)
   {
      for(uint32_t c = 0; c < max_length; c++)
      {
         sum += (uint64_t)(names[(n * max_length) + c] - sub) * (uint64_t)(n + 1);
      }
   }

   return sum;
}



#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class lexical_analyzer;

// mod 100
static int hashf(int a)
{
   return a % 100;
}

struct Element_hash_table
{
   //��������
   int value;

   //������ � ������� ������
   int index; 

   //������������ ��� �������� || next
   size_t alt;    

};

class string_hash
{
    friend class lexical_analyzer;

   Element_hash_table* hash_table;

   typedef int(*func)(int);
   func function;
   
   //������ ���� �������
   size_t table_size;

   //������ �������� �������
   size_t main_area_size;

   //��������� ��������� ������ � ������� �����������
   size_t next_in_alt_table;

   void Create_table()
   {
      hash_table = new Element_hash_table[table_size];
      hash_table[0].value = 0;
      hash_table[0].index = 0;
      hash_table[0].alt = 0;
      for (size_t i = 1; i < table_size; i++)
      {
         hash_table[i].value = -1;
         hash_table[i].index = -1;
         hash_table[i].alt = 0;
      }
   }

   void Expansion()
   {
      int new_size = determineHashTableSize(table_size);
      Element_hash_table* new_table = new Element_hash_table[new_size];
      Element_hash_table* temp = hash_table;
      for (size_t i = 0; i < table_size; i++)
      {
         new_table[i].value = hash_table[i].value;
         new_table[i].index = hash_table[i].index;
         new_table[i].alt = hash_table[i].alt;
      }
      for (size_t i = table_size; i < new_size; i++)
      {
         new_table[i].value = -1;
         new_table[i].index = -1;
         new_table[i].alt = 0;
      }

      delete[] temp;

      hash_table = new_table; 
   }

   int Conflict_resolution(int a, int ind)
   {
      if (next_in_alt_table == table_size)
      {
         Expansion();
      }
      
      size_t transp = function(a) + 1;
      
      while (hash_table[transp].alt != 0)
      {
         transp = hash_table[transp].alt;
      }

      if (hash_table[0].alt == 0)
      {
         hash_table[transp].alt = next_in_alt_table;
         hash_table[next_in_alt_table].value = a;
         hash_table[next_in_alt_table].index = ind;
         return next_in_alt_table++;
      }
      else
      {
         int alt_zero = hash_table[0].alt;         

         hash_table[0].alt = hash_table[alt_zero].alt;
         hash_table[alt_zero].alt = 0;

         hash_table[transp].alt = alt_zero;
         hash_table[alt_zero].value = a;
         hash_table[alt_zero].index = ind;

      }
      return transp;
   }

   void Correct_removal(int a)
   {
      size_t transp = function(a) + 1;

      if (hash_table[transp].value == a)
      {
         if (hash_table[transp].alt == 0)
         {
            hash_table[transp].value = -1;
         }
         else
         {
            int prev = transp;

            while (hash_table[hash_table[transp].alt].alt != 0)
            {
               transp = hash_table[transp].alt;
            }

            hash_table[prev].value = hash_table[hash_table[transp].alt].value;

            hash_table[hash_table[transp].alt].alt = hash_table[0].alt;
            hash_table[0].alt = hash_table[transp].alt;

            hash_table[hash_table[transp].alt].value = -1;
            hash_table[hash_table[transp].alt].index = -1;
            hash_table[transp].alt = 0;
         }
      }
      else
      {

         while (hash_table[hash_table[transp].alt].value != a)
         {
            transp = hash_table[transp].alt;
         }

         int temp = hash_table[hash_table[transp].alt].alt;

         hash_table[hash_table[transp].alt].alt = hash_table[0].alt;
         
         hash_table[hash_table[transp].alt].value = -1;
         hash_table[hash_table[transp].alt].index = -1;
         
         hash_table[0].alt = hash_table[transp].alt;

         hash_table[transp].alt = temp;

      }
      return;
   }

   int Alt_find(int a)
   {
       size_t transp = function(a) + 1;

       while (hash_table[transp].alt != 0)
       {
           transp = hash_table[transp].alt;
           if (hash_table[transp].value == a)
               return transp;
       }

       return 0;
   }

   int Alt_find_and_return_index(int a)
   {
      size_t transp = function(a) + 1;

      while (hash_table[transp].alt != 0)
      {
         transp = hash_table[transp].alt;
         if (hash_table[transp].value == a)
            return hash_table[transp].index;
      }

      return -1;
   }

public:

   //�� ��������� ������� mod 100, st = 300
   string_hash()
   {
      function = &hashf;
      table_size = 300;
      main_area_size = 100 + 1;
      next_in_alt_table = 100 + 1;

      Create_table();
   }

   string_hash(int(*func)(int), size_t size_table_, size_t size_area_)
   {
      if (size_area_ >= size_table_)
         throw "There are no cells for alternatives";

      function = func;
      table_size = size_table_;

      //������ 0 � ��� n ����� ��� �������
      main_area_size = size_area_ + 1; 

      //������ 0 � ��� n ����� ��� ������� � ����� ��� ������ ���������
      next_in_alt_table = size_area_ + 1;

      Create_table();
   }

   int insert(int a, int ind = -1)
   {
      if (find(a))
          return find(a);
      if (hash_table[function(a) + 1].value == -1)
      {
         hash_table[function(a) + 1].value = a;
         hash_table[function(a) + 1].index = ind;
         return (function(a) + 1);
      }
      else
      {
         return Conflict_resolution(a, ind);
      }

   }

   int insert_index(int a, int ind)
   {
      hash_table[a].index = ind;

      return a;
   }

   void remove(int a)
   {
      if (!find(a))
      {
         ;
      }
      else
      {
         Correct_removal(a);
      }
    
   }

   int& operator[](size_t index_) const
   {
      if (index_ >= table_size)
      {
         cout << "Error hash";
      }
      return hash_table[index_].value;
   }

   int& operator[](size_t index_)
   {
      if (index_ >= table_size)
      {
         cout << "Error hash";
      }

      if (index_ >= table_size)
      {
         Expansion();
      }
      return hash_table[index_].value;
   }

   int find(int a)
   {
       if (hash_table[function(a) + 1].value == a)
       {
           return function(a) + 1;
       }
       else
       {
           return Alt_find(a);
       }
   }

   int find_and_return_index(int a)
   {
      if (hash_table[function(a) + 1].value == a)
      {
         return hash_table[function(a) + 1].index;
      }
      else
      {
         return Alt_find_and_return_index(a);
      }
   }

   //true - ���� �����
   bool error_finder()
   {
      for (int i = 1; i < table_size; i++)
      {
         if (hash_table[i].value != -1 && hash_table[i].index == -1)
            return true;
      }
      return false;
   }

   void Print()
   {
      for (int i = 0; i < main_area_size; i++)
      {
         if (hash_table[i].value == -1 && hash_table[i].alt == 0)
            continue;
         cout << "--------------------------" << endl;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << "\t | " << endl;
      }
      cout << "==========================" << endl;
      for (int i = main_area_size; i < table_size; i++)
      {
         if (hash_table[i].value == -1 && hash_table[i].alt == 0)
            continue;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << "\t | " << endl;
         cout << "--------------------------" << endl;
      }
   }

   void Print(int a)
   {
      if (a > table_size)
         return;
      for (int i = 0; i < main_area_size; i++)
      {
         cout << "--------------------------------" << endl;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << "\t | " << endl;
      }
      cout << "===================================" << endl;
      for (int i = main_area_size; i < a; i++)
      {
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << "\t | " << endl;
         cout << "--------------------------------" << endl;
      }
   }


   void Print_main()
   {
      for (int i = 0; i < main_area_size; i++)
      {
         cout << "--------------------------------" << endl;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << endl;
      }
   }

   void Print_main(int a)
   {
      if (a > main_area_size)
         return;
      for (int i = 0; i < a; i++)
      {
         cout << "--------------------------------" << endl;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << endl;
      }
   }

   void Print_alt()
   {
      cout << "===================================" << endl;
      for (int i = main_area_size; i < table_size; i++)
      {
         cout << "--------------------------------" << endl;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << endl;
      }
   }

   void Print_alt(int a)
   {
      if (a + main_area_size > table_size)
         return;
      cout << "===================================" << endl;
      for (int i = main_area_size; i < a + main_area_size; i++)
      {
         cout << "--------------------------------" << endl;
         cout << i << "\t | " << hash_table[i].value << "\t | " << hash_table[i].alt << endl;
      }
   }

   // ������� ��� ����������� ���������� �������� �����, �� �������� ���������
   bool isPrime(size_t n) {
      if (n < 2) return false;
      if (n < 4) return true;
      if (n % 2 == 0 || n % 3 == 0) return false;
      for (size_t i = 5; i * i <= n; i += 6) {
         if (n % i == 0 || n % (i + 2) == 0) return false;
      }
      return true;
   }

   size_t nextPrime(size_t n) {
      while (!isPrime(n)) {
         ++n;
      }
      return n;
   }

   // ������� ����������� ������� ���-�������
   size_t determineHashTableSize(size_t numElements, double loadFactor = 0.75) {
      if (numElements == 0) return 0;

      size_t estimatedSize = static_cast<size_t>(std::ceil(numElements / loadFactor));
      return nextPrime(estimatedSize);
   }

};

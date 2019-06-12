/**********************************************************
Milestone 2 - Aid Management Application ErrorState state class
// Milestone <Milestone #2>
// Name: Tashi Tsering
// Student #: 114763170
// Course: OOP244 Fall 2018
// File: ms2_tester.cpp
**********************************************************/

#include "ErrorState.h"

using namespace std;
using namespace aid;

int main() {
   ErrorState T("Testing ErrorState Module");
   ErrorState e;
   ErrorState f("");
   ErrorState g(nullptr);
   int ret = 0;
   bool ok = true;
   cout << T << endl 
	    << "e: " << e 
	    << "isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl
	    << "f: " << f 
	    << "isClear(): " << (f.isClear() ? "Passed!" : "Failed!") << endl
        << "g: " << g 
	    << "isClear(): " << (g.isClear() ? "Passed!" : "Failed!") << endl;
   if (!e.isClear()) ok = false;
   cout << "-----------| Long Message\r";
   for (int i = 0; i < 10000000; i++) {
      if (i % 1000000 == 0) {
         cout << "*";
         cout.flush();
      }
      e.message("An ErrorState message that is really long long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long"
         " long  long  long  long  long  long  long  long  long  long  long  long  long");
   }
   cout << '*' << endl;
   cout << e << "|***********\nLong Message  isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   if (e.isClear()) ok = false;

   e.message("Short Message");
   cout << e << " isClear(): " << (e.isClear() ? "Failed!" : "Passed!") << endl;
   if (e.isClear()) ok = false;

   e.message("Clear Message");
   cout << e;
   e.clear();
   cout << e << " isClear(): " << (e.isClear() ? "Passed!" : "Failed!") << endl;
   if (!e.isClear()) ok = false;

   e.message("Empty Message");
   cout << e;
   e.message("");
   cout << e << " isClear(): " << (!e.isClear() ? "Failed!" : "Passed!") << endl;
   if (!e.isClear()) ok = false;
   cout << endl;

   if (ok) {
	   cout << "You passed all the tests!" << endl;
   }
   else {
	   cout << "You did not pass all the tests, keep working on your project!" << endl;
	   ret = 1;
   }

   return ret;
}
// compile flags -  clang++ -std=c++11 -o dayone dayone.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <list>

using namespace std;
int main(){
   fstream INFILE;
   INFILE.open("../input.txt",ios::in); \
   list<int> elves;
   list<int>::iterator iter;
   int count=0;
   int calories = 0;
   int val;
   //elves.push_front(0);
   if (INFILE.is_open()){ //checking whether the file is open
      string tp;
      while(getline(INFILE, tp)){ 
        if (regex_match (tp, regex("[[:digit:]]+") )){
           calories = stoi(tp);
           count = count+calories;
        }
        else{
            elves.push_front(count);
            count=0;
        }
        }
        
      } 
      elves.sort();
      count = 0;
      for (int i=1;i<=3;i++){
        val = elves.back();
        elves.pop_back();
        cout << val << endl;
        count = count + val;        
      }
      cout << count << endl;
      INFILE.close(); //close the file object.
}

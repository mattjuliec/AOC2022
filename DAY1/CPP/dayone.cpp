// compile flags -  clang++ -std=c++11 -c -o dayone dayone.cpp
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
   int count=0;
   int calories = 0;
   elves.push_front(0);
   if (INFILE.is_open()){ //checking whether the file is open
      string tp;
      while(getline(INFILE, tp)){ //read data from file object and put it into string.
        //if (regex_match (tp, regex("-?(0|[1-9]\\d*)") )){
        if (regex_match (tp, regex("[[:digit:]]+") )){
           calories = stoi(tp);
            //cout << calories << "\n"; 
            count = count+calories;
        }
        else{
            for (int x : elves) { // auto sort the list as new entries go in
                if(calories>=x){
                    elves.push_back(calories);
                    break;
                }
		        std::cout << x << '\n';
	        }
            count=0;
        }
      }
      INFILE.close(); //close the file object.
   }
}
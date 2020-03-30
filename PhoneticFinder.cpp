/**
 * AUTHORS: Uriya havshush, Shoval Tayro
 */

#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm> 
#include "PhoneticFinder.hpp"

using namespace std;

namespace phonetic {
string find(string s1 , string s2){
    if(s2.size() == 0) throw out_of_range{"the word you entered is empty"};
  //check if s2 is only one word
    for (int i = 1; i < s2.size()-1; i++) { 
        if (isspace(s2.at(i)) && !isspace(s2.at(i-1)) && !isspace(s2.at(i+1)) ) throw out_of_range{"You entered more than one word"};
    }
   string check;
   for(int i =0; i < s1.size();i++){
        while(i< s1.size() && !isspace(s1.at(i))){
            check+= s1.at(i);
              i++;
        }
        if(checkWords(check , s2)) return check;
        check = "";
    }
    throw out_of_range{"the word does not exist in the given string"};
}

bool checkWords(string s1 , string s2){
    string a = tolowercase(s1);
    string temp_b = tolowercase(s2);
    string b = removeSpaces(temp_b);
    if(s1.size()!= b.size()) return false;
    else{
        int i = 0;
        while( i < a.size()){
            if(a.at(i)== b.at(i)) i++;
            else{
                //check all combinations
               if(a.at(i) == 't' && b.at(i) == 'd') i++;
               else if(a.at(i) == 'd' && b.at(i) == 't') i++;
               else if(a.at(i) == 'v' && b.at(i) == 'w') i++;
               else if(a.at(i) == 'w' && b.at(i) == 'v') i++;
               else if(a.at(i) == 'j' && b.at(i) == 'g') i++;
               else if(a.at(i) == 'g' && b.at(i) == 'j') i++;
               else if(a.at(i) == 's' && b.at(i) == 'z') i++;
               else if(a.at(i) == 'z' && b.at(i) == 's') i++;
               else if(a.at(i) == 'o' && b.at(i) == 'u') i++;
               else if(a.at(i) == 'u' && b.at(i) == 'o') i++;
               else if(a.at(i) == 'i' && b.at(i) == 'y') i++;
               else if(a.at(i) == 'y' && b.at(i) == 'i') i++;
               else if(a.at(i) == 'b' && (b.at(i) == 'f' || b.at(i) == 'p')) i++;
               else if(a.at(i) == 'f' && (b.at(i) == 'b' || b.at(i) == 'p')) i++;
               else if(a.at(i) == 'p' && (b.at(i) == 'b' || b.at(i) == 'f')) i++;
               else if(a.at(i) == 'c' && (b.at(i) == 'k' || b.at(i) == 'q')) i++;
               else if(a.at(i) == 'k' && (b.at(i) == 'c' || b.at(i) == 'q')) i++;
               else if(a.at(i) == 'q' && (b.at(i) == 'c' || b.at(i) == 'k')) i++;
               else return false;
            }
        }
        return true;
    }
}

//convert a string to lower case
string tolowercase(string a){
    string ans;
    for(int i = 0; i < a.size(); i++){
        ans+= tolower(a.at(i));
    }
    return ans;
}

//remove spaces from a given string 
string removeSpaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str;
} 
}
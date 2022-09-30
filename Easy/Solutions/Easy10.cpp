#include<iostream>
#include<string.h>
#include <cctype>
using namespace std;

string ones[] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ",
                     "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ",
                     "seventeen ", "eighteen ", "nineteen "};

string tens[] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
int crore = 10000000, lakh = 100000, thou = 1000, hund = 100, one = 1;
int numss[] = {crore, lakh, thou, hund, one};
string deno[] = {"crore ", "lakh ", "thousand ", "hundred ", ""};

string num2Words(long, string);

int main(){
    long num;
    cin >> num;
    string name = "";
    for (int i = 0; i < 5; i++){
        if (num >= numss[i]){
            name += num2Words(num / numss[i], deno[i]);
            num %= numss[i];
        }
    }
    name[0] = toupper(name[0]);
    cout << name;

}

string num2Words(long n, string ss){
    string word = "";
    if (n > 19)
        word += tens[n/10] + ones[n%10];
    else
        word += ones[n];
    if (n)    // Not zero
        word += ss;
    return word;
}
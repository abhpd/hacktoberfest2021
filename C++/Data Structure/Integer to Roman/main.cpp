#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        while(num >= 1000){
            ans += "M";
            num -= 1000;
        }
        if(num >= 900){
            ans += "CM";
            num -= 900;
        }
        while(num >= 500){
            ans += "D";
            num -= 500;
        }
        if(num >= 400){
            ans += "CD";
            num -= 400;
        }
        while(num >= 100){
            ans += "C";
            num -= 100;
        }
        if(num >= 90){
            ans += "XC";
            num -= 90;
        }
        while(num >= 50){
            ans += "L";
            num -= 50;
        }
        if(num >= 40){
            ans += "XL";
            num -= 40;
        }
        while(num >= 10){
            ans += "X";
            num -= 10;
        }
        if(num >= 9){
            ans += "IX";
            num -= 9;
        }
        while(num >= 5){
            ans += "V";
            num -= 5;
        }
        if(num >= 4){
            ans += "IV";
            num -= 4;
        }
        while(num >= 1){
            ans += "I";
            num -= 1;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.intToRoman(3999) << endl;
    return 0;
}

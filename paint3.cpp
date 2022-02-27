#include "painter.h"
float mymin(float x, float y) {
    if (x > y) return y;
return x;}
float mymax(float x, float y) {
    if (x > y) return x;
return y;}
string mysubstr(string s, int a, int b) {
    string res = "";
    for (int i = a; i <= b; i++) res += s[i];
return res;}
vector<string> strtoarr(string firststr) {
    vector <string> firststrarr;
    firststr += ' ';
    while (find(firststr," ") != -1) {
        firststrarr.push_back(mysubstr(firststr, 0, find(firststr," ") - 1));
        firststr = mysubstr(firststr, find(firststr," ") + 1, firststr.size() - 1);}
return firststrarr;}
bool isnum(string s) {
    for (int i = 0; i < len(s); i++) if (s[i] < '0' || s[i] > '9') return false;
return true;}
void SetColor(int a, int bg) {
    HANDLE pr = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(pr, (WORD)((bg << 4) | a));}

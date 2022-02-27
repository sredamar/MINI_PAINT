#include "painter.h"
int len(string s) {
    int res = 0;
    string e="";
    while (s!=e) {
        e+=s[res];
        res+=1;}
    return res;}
int find(string str1, string str2) {
    int i1=0, i2=0;
    while ((i1 < str1.size()) && (i2 < str2.size())) {
        if (str1[i1]==str2[i2]) i2 += 1;
        else {
            i2 = 0;
            if (str1[i1]==str2[i2]) i2 = 1;}
        i1 += 1;}
    if (i2==str2.size()) return i1-len(str2);
    else return -1;}
float mabs(float x, float y) {
    if (x - y >= 0) return x - y;
    return y - x;}
float sqdist(float x, float y, float x1, float y1) {
    return (x - x1) * (x - x1) + (y - y1) * (y - y1);}
float sqr(float x) {
  return x * x;}

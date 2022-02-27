#ifndef PAINTER_H_INCLUDED
#define PAINTER_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Windows.h"
using namespace std;
int len(string s);
int find(string str1, string str2);
float mabs(float x, float y);
float sqdist(float x, float y, float x1, float y1);
float sqr(float x);
bool isinline(float x,float y,float x1,float y1, int px, int py);
bool isincircleborder(float x, float y, float r, int px, int py);
bool isincircle(float x, float y, float r, int px, int py);
float mymin(float x, float y);
float mymax(float x, float y);
string mysubstr(string s, int a, int b);
vector<string> strtoarr(string firststr);
bool isnum(string s);
void SetColor(int a, int bg);
void error(string err);
long long str_to_num(string temp);
bool commands_check(vector<string> &args);
bool isOk(string filename);
string slicer(string str, int start, int endd);
#endif // PAINTER_H_INCLUDED

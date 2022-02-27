#include "painter.h"
string slicer(string str, int start, int endd) { // str[2:3] analog
    string res = "";
    if (endd >= len(str)) {
        endd = len(str) - 1;}
    if (start > endd) {
        return str;}
    else if (start == (len(str) - 1)) {
        res += str[len(str) - 1];
        return res;}
    else {
        for (long long i = start; i <= endd; i++) {
            res += str[i];}
        return res;}
return "-1";}

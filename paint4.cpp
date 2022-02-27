#include "painter.h"
void error(string err) {
    SetColor(4, 0);
    cout << err << "\n";
    SetColor(7, 0);}
long long str_to_num(string temp) {
    int ch = 0;
    long long temp_num = 0;
    for (long long i = 0; temp[i] != '\0'; i++) {
        ch = temp[i] - 48;
        temp_num = temp_num * 10 + ch;}
return temp_num;}

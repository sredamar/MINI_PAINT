#include "painter.h"
bool isOk(string filename) {
    bool ok = true;
    ifstream inmyfile ("input.txt");
    inmyfile.is_open();
    string firststr;
    getline(inmyfile, firststr);
    vector<string> firststrarr = strtoarr(firststr);
    if (!(firststrarr.size()==4)) {
        error("Error: invalid number of arguments");
        ok = false;}
    if (!(isnum(firststrarr[0]) && isnum(firststrarr[1]))) {
        error("Error: invalid arguments");
        ok = false;}
    if (firststrarr[2].size()!=1) {
        error("Error: needed char for background");
        ok=false;}
    while (ok && !inmyfile.eof()) {
        getline(inmyfile, firststr);
    vector<string> nextline;
        nextline = strtoarr(firststr);
        if (!commands_check(nextline)) ok=false;}
    inmyfile.close();
    return ok;}

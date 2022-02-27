#include "painter.h"
bool isinline(float x,float y,float x1,float y1, int px, int py) {
    int c = 0;
    y = y + 0.1;
    y1 = y1 + 0.1;
    if ((px - x) * (y1 - y) > (py - y) * (x1 - x)) c++;
    if ((1 + px - x) * (y1 - y) > (py - y) * (x1 - x)) c++;
    if ((px - x) * (y1 - y) > (2 + py - y) * (x1 - x)) c++;
    if ((1 + px - x) * (y1 - y) > (2 + py - y) * (x1 - x)) c++;
    return (c > 0 && c < 4);}
bool isincircleborder(float x, float y, float r, int px, int py) {
    int c = 0;
    if (sqr(x - px) + sqr(y - py) > sqr(r)) c++;
    if (sqr(x - px - 1) + sqr(y - py) > sqr(r)) c++;
    if (sqr(x - px) + sqr(y - py - 2) > sqr(r)) c++;
    if (sqr(x - px - 1) + sqr(y - py - 2) > sqr(r)) c++;
    return (c > 0 && c < 4);}
bool isincircle(float x, float y, float r, int px, int py) {
    int c = 0;
    if (sqr(x - px) + sqr(y - py) > sqr(r)) c++;
    if (sqr(x - px - 1) + sqr(y - py) > sqr(r)) c++;
    if (sqr(x - px) + sqr(y - py - 2) > sqr(r)) c++;
    if (sqr(x - px - 1) + sqr(y - py - 2)>sqr(r)) c++;
    return (c < 4);}

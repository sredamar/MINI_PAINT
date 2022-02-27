#include "painter.h"
bool commands_check(vector<string> &args) {
    int s = args.size();
    if (args[0] == "r" || args[0] == "R") {
        if (s != 6 && s != 7) {
            error("Error: number of arguments is wrong");
            return false;}
        if (!(isnum(args[1]) && isnum(args[2]) && isnum(args[3]) && isnum(args[4]))) {
            error("Error: invalid arguments");
            return false;}
        if (s == 7 && !(args[6]=="RGB_R" || args[6]=="RGB_G" || args[6]=="RGB_B")){
            error("Error: invalid arguments");
            return false;}
        if (len(args[5]) != 1) {
            error("Error: needed char");
            return false;}
        if (str_to_num(args[1]) < 0) {
            error("Error: invalid number - negative x coordinate");
            return 0;}
        if (str_to_num(args[2]) < 0) {
            error("Error: invalid number - negative y coordinate");
                return 0;}
        if (str_to_num(args[3]) <= 0) {
            error("Error: invalid number - width too small");
            return false;}
        if (str_to_num(args[4]) <= 0) {
            error("Error: invalid number - height too small");
            return false;}
    }   else if (args[0] == "L") {
        if (s != 6 && s != 7) {
            error("Error: number of arguments is wrong");
            return false;}
        if (!(isnum(args[1]) && isnum(args[2]) && isnum(args[3]) && isnum(args[4]))) {
            error("Error: invalid arguments");
            return false;}
        if (s == 7 && !(args[6]=="RGB_R" || args[6]=="RGB_G" || args[6]=="RGB_B")) {
            error("Error: invalid arguments");
            return false;}
        if (str_to_num(args[1]) < 0) {
            error("Error: invalid number - negative x0 coordinate");
            return 0;}
        if (str_to_num(args[2]) < 0) {
            error("Error: invalid number - negative y0 coordinate");
            return 0;}
        if (str_to_num(args[3]) < 0) {
            error("Error: invalid number - negative x1 coordinate");
            return false;}
        if (str_to_num(args[4]) < 0) {
            error("Error: invalid number - negative y1 coordinate");
            return false;}
        if (len(args[5]) != 1) {
            error("Error: needed char");
            return false;}
    }   else if (args[0] == "c" || args[0] == "C") {
        if (s != 5 && s != 6) {
            error("Error: invalid number of arguments");
            return false;}
        if (!(isnum(args[1]) && isnum(args[2]) && isnum(args[3]))) {
            error("Error: invalid arguments");
            return false;}
        if (s == 6 && !(args[5]=="RGB_R" || args[5]=="RGB_G" || args[5]=="RGB_B")) {
            error("Error: invalid arguments");
            return false;}
        if (str_to_num(args[1]) < 0) {
            error("Error: invalid number - negative x0 coordinate");
            return 0;}
        if (str_to_num(args[2]) < 0) {
            error("Error: invalid number - negative y0 coordinate");
            return 0;}
        if (str_to_num(args[3]) <= 0) {
            error("Error: invalid number - radius too small");
            return false;}
        if (len(args[4]) != 1) {
            error("Error: needed char");
            return false;}
    }   else {
        error("Error: unknown command");
        return false;}
    return true;}

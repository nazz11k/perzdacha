#pragma once

#include "iostream"
#include "iomanip"
#include "random"
#include "ctime"
#include "string"

using namespace std;

void generator(int** matrix, int m);
void founder(int** matrix, int m);
int sum_f(int number);
void swapper(int** matrix, int m, int min_row);
void stringer(int** matrix, int m, string* diagonals);
void separator(string* diagonals);
void matrix_outer(int** matrix, int m, string name);
void outer(string* lines, string name);
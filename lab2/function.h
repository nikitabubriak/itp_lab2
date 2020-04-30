#pragma once
#include <string>

using namespace std;



const int n = 20; //number of countries
string country[n];
int votes[n][n];
int score[n] = { 0 };

void input_data(string[n], int[n][n]);
void count_score(int[n][n], int[n]);
void sort_top(int[n], string[n]);
void output_top(int[n], string[n]);



#include "function.cpp"
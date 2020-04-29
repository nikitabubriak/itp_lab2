#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

//#include <iomanip>

using namespace std;

const int n = 20; //number of countries
string country[n];
int votes[n][n];
int score[n] = { 0 };

void input_data(string[n], int[n][n]);
void count_score(string[n], int[n][n], int[n]);
void enum_top10();
void output_top10();

#include "function.cpp"
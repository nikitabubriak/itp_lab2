#include "stdafx.h"
#include "function.h"

using namespace std;



int main()
{
	input_data(country, votes);
	count_score(votes, score);
	sort_top(score, country);
	output_top(score, country);
	return 0;
}
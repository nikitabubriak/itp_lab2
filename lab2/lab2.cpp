#include "stdafx.h"
#include "function.h"

using namespace std;

int main()
{
	input_data(country, votes);
	//output();//<<<
	count_score(votes, score);
	//output_top(score);
	sort_top(score, country);
	output_top(score, country);
	//output();//<<<
	//system("pause");
}
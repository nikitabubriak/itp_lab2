#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
#include <algorithm>

#include <iomanip>

using namespace std;
namespace fs = experimental::filesystem;

void input_data(string country[n], int votes[n][n])
{
	string	directory, 
			extension = ".csv", 
			c_element, 
			v_element;

	int		c_current, 
			c_processed = 0;

	cout << "Enter " << extension << " files directory:" << endl;
	cin >> directory;

	for (auto &f : fs::directory_iterator(directory))
	{
		if (f.path().extension().string() == extension)
		{
			ifstream inFile(f.path());
			if (!inFile.is_open()) { cout << "Error. Can not open file\n"; return; }
			
			inFile >> c_current;
			for (int i = 0 + c_processed; i < c_current + c_processed; i++)
			{
				getline(inFile, c_element, ',');
				country[i] = c_element;

				for (int j = 0; j < n - 1; j++)
				{
					getline(inFile, v_element, ',');
					votes[i][j] = stoi(v_element);
				}

				getline(inFile, v_element, '\n');
				votes[i][n - 1] = stoi(v_element);
			}

			c_processed += c_current;
			inFile.close();
		}
		else continue;
	}
}

void count_score(int votes[n][n], int score[n])
{
	int votes_reverse[n][n];
	int votes_local[20];
	int g, h, f;
	int score_points[10] = { 12,10,8,7,6,5,4,3,2,1 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			votes_reverse[i][j] = votes[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			votes[i][j] = votes_reverse[j][i];
		}
	}

	for (g = 0; g < n; g++)
	{
		for (int j = 0; j < n; j++)
		{
			votes_local[j] = votes[g][j];
		}

		sort_top(votes_local);

		for (h = 0; h < 10; h++)
		{
			for (f = 0; f < n; f++)
			{
				if (votes_local[h] == votes[g][f]) score[f] += score_points[h];
			}
		}
	}

void sort_top(int a[n])
{
	for (int i = n; i > 0; i--)
	{
		for (int j = n; j > n - i; j--)
		{
			if (a[j] > a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}

	//============
	for (int i = 0; i < 10; i++) cout << setw(10) << a[i];
	cout << endl;
}
	

//===========================\/test\/======================
	
	
void output()
{
	for (int j = 0; j < n; j++)
	{
		cout << setw(10) << country[j];
		cout << "\n" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(10) << votes[i][j];	
		}
		cout << "\n" << endl;
	}
}
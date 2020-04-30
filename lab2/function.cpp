#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>
#include <algorithm>

using namespace std;
namespace fs = experimental::filesystem;



void input_data(string country[n], int votes[n][n])
{
	string	directory,
		extension = ".csv",
		c_element,
		v_element;

	int	c_current,
		c_processed = 0;

	cout << "Enter " << extension << " files directory:" << endl;
	cin >> directory;

	for (auto &f : fs::directory_iterator(directory))
	{
		if (f.path().extension().string() == extension)
		{
			ifstream inFile(f.path());
			if (!inFile.is_open()) { cout << "Error. Cannot open file\n"; return; }

			inFile >> c_current;

			for (int i = 0 + c_processed; i < c_current + c_processed; i++)
			{
				getline(inFile, c_element, ',');
				country[i] = c_element;

				if (i == 0 + c_processed) country[i].erase(0, 1);

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

		string placeholder[n];
		sort_top(votes_local, placeholder);

		for (h = 0; h < 10; h++)
		{
			for (f = 0; f < n; f++)
			{
				if (votes_local[h] == votes[g][f])
				{
					score[f] += score_points[h];
				}
			}
		}
	}
}	



void sort_top(int a[n], string c[n])
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j > n - 1 - i; j--)
		{
			if (a[j] > a[j - 1])
			{
				swap(a[j], a[j - 1]);

				swap(c[j], c[j - 1]);
			}
		}
	}
}



void output_top(int score[n], string country[n])
{
	ofstream outFile("results.csv");
	if (!outFile.is_open()) { cout << "Error. Cannot open file\n"; return; }

	for (int i = 0; i < 10; i++)
	{
		outFile << country[i] << "," << score[i] << endl;
	}
	cout << "\n\nTop 10 winners added to results.csv\n" << endl;
	outFile.close();
}
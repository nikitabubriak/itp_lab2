#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

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

	//===========================test
	//#include <iomanip>
	

	/*for (int j = 0; j < n; j++)
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
}*/
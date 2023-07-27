/* Printing vectors and matrices */

#ifndef GLOBAL_PRINT_H
#define GLOBAL_PRINT_H

void print(const vector<double>& vec)
{
	cout << endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << ", ";
	}
	cout << endl;
}

void print(const vector<vector<double>>& matrix)
{
	cout << endl;
	for (int i = 0; i < matrix.size(); ++i)
	{
		print(matrix[i]);
	}
	cout << endl;
}



#endif GLOBAL_PRINT_H
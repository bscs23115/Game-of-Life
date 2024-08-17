#include<iostream>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#define C 159
#define R 90
using namespace std;

void loadworld(const char fname[],char W[][C],char ls,char ds)
{
	ifstream read(fname);
	if (!read)
	{
		cout << "UNABLE TO READ FILE" << endl;
		exit(1);
	}
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			read >> W[r][c];
			if (W[r][c]=='0')
				W[r][c] = ds;
			else if (W[r][c]=='1')
				W[r][c] = ls;
		}
	}
}
void displayworld(char W[][C])
{
	system("cls");
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cout << W[r][c];
		}
		cout << endl;
	}
}
int neighbourscount(char W[][C],int r, int c, char ds, char ls)
{
	int count = 0;
	for (int n = -1; n <= 1; n++)
	{
		for (int k = -1; k <= 1; k++)
		{
			if (n== 0 && k== 0)
				continue;
			if (r + n >=R || r + n < 0 || c + k >= C || c + k < 0)
				continue;
			if (W[r + n][c + k] == ls)
				count++;
		}
	}
	return count;
}
void updateworld(char copy[][C], char W[][C])
{
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			W[r][c]=copy[r][c];
		}
	}
}
void repopulate(char W[][C], char ls, char ds)
{
	char copy[R][C];
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			int count = neighbourscount(W,r,c,ds,ls);
			if (count < 2)
				copy[r][c] = ds;
			else if (count > 3)
				copy[r][c] = ds;
			else if (count == 3)
				copy[r][c] = ls;
			else
				copy[r][c] = W[r][c];
		}
	}
	updateworld(copy, W);
}

int main()
{
	_getch();
	char W[R][C] = {};
	char ls = -37,ds=' ';
	loadworld("Text15.txt", W, ls, ds);
	displayworld(W);
	while (true)
	{
		repopulate(W, ls, ds);
		displayworld(W);
	}

	return 0;
}



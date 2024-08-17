#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<time.h>
#define C 159
#define R 90
using namespace std;

void loadworld(const char fname[], char W[][C], char ls, char ds)
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
			if (W[r][c] == '0')
				W[r][c] = ds;
			else if (W[r][c] == '1')
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
int neighbourscount(char W[][C], int r, int c, char ds, char ls)
{
	int count = 0;
	for (int n = -1; n <= 1; n++)
	{
		for (int k = -1; k <= 1; k++)
		{
			if (n == 0 && k == 0)
				continue;
			if (W[(r + n) % R][(c + k) % C] == ls)
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
			W[r][c] = copy[r][c];
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
			int count = neighbourscount(W, r, c, ds, ls);
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
	char w1[R][C],w2[R][C], w3[R][C], w4[R][C], w5[R][C], w6[R][C];
	char ls = -37, ds = ' ';
	int t,diff=0;
	loadworld("Textc1.txt", w1, ls, ds);
	loadworld("Textc2.txt", w2, ls, ds);
	loadworld("Textc3.txt", w3, ls, ds);
	loadworld("Textc4.txt", w4, ls, ds);
	loadworld("Textc5.txt", w5, ls, ds);
	loadworld("Textc6.txt", w6, ls, ds);
	t = time(0);
	do
	{
		repopulate(w1, ls, ds);
		repopulate(w2, ls, ds);
		repopulate(w3, ls, ds);
		repopulate(w4, ls, ds);
		repopulate(w5, ls, ds);
		repopulate(w6, ls, ds);
		if (diff == 30)
			t = time(0);
		diff = (time(0) - t);
		if (diff < 5)
			displayworld(w1);
		else if (diff <= 10)
			displayworld(w2);
		else if (diff <= 15)
			displayworld(w3);
		else if (diff <= 20)
			displayworld(w4);
		else if (diff <= 25)
			displayworld(w5);
		else if (diff <= 30)
			displayworld(w6);

	} while (true);

	return 0;
}



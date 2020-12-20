// Project : Pong Game
// Save and Load through Filing
// 2D Array used for Pedals
// Files are created Automatically by the Program


#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

void ScoreDisplay(int rows, int cols,int Score_P1, int Score_P2);

int Up = 1, Down = 0;
int Right = 2, Left = 3;
//int H_direction = Left, V_direction = Up;
//int Score_P1 = 0, Score_P2 = 0;

void wait(int T)
{
	for (int t = 0;t<T;t++)
	{
		for (int c = 0; c <= 9999;c++)
		{
		}
	}
}

void gotoRowCol(float rpos, float cpos)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	float xpos = cpos, ypos = rpos;
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos;
	scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void L2R(int R, int cs, int ce, char S)
{
	for (int c = cs; c <= ce; c++)
	{
		gotoRowCol(R, c);
		cout << S;
	}
}
void T2B(int c, int Rs, int Re, char S)
{
	for (int R = Rs; R <= Re; R++)
	{
		gotoRowCol(R, c);
		cout << S;
	}
}
void T2B2(int c, int Rs, int Re, char S)
{
	for (int R = Rs+1; R <= Re; R+=2)
	{
		gotoRowCol(R, c);
		cout << S;
	}
}

void Make_Board(int rows, int cols,char sym)
{
	L2R(0, 0, cols,sym);
	T2B(0, 0, rows, sym);
	L2R(rows, 0, cols, sym);
	T2B(cols, 0, rows, sym);
	T2B2(cols / 2, 0, rows, sym);
}

void Pedal_Display(int Pedal[][2], char sym, int d)
{
	for (int i = 0; i<6;i++)
	{
		int r = Pedal[i][0];
		int c = Pedal[i][1];
		gotoRowCol(r, c);
		cout << sym;
	}
	wait(d);
}

void Initialize_Pedals(int PedalP_1[][2], int PedalP_2[][2] ,int rows, int cols,char sym,int &limit,float &br, float &bc
															, int &Score_P1,int &Score_P2,int &H_direction,int &V_direction )
{
	PedalP_1[0][0] = rows / 3;
	PedalP_1[0][1] = cols / 10;
	
	PedalP_1[1][0] = (rows / 3) + 1;
	PedalP_1[1][1] = cols / 10;

	PedalP_1[2][0] = (rows / 3) + 2;
	PedalP_1[2][1] = cols / 10;

	PedalP_1[3][0] = (rows / 3) + 3;
	PedalP_1[3][1] = cols / 10;

	PedalP_1[4][0] = (rows / 3) + 4;
	PedalP_1[4][1] = cols / 10;

	PedalP_1[5][0] = (rows / 3) + 5;
	PedalP_1[5][1] = cols / 10;

	//Now Pedal 2

	PedalP_2[0][0] = rows / 3;
	PedalP_2[0][1] = cols-10;

	PedalP_2[1][0] = (rows / 3) + 1;
	PedalP_2[1][1] = cols - 10;

	PedalP_2[2][0] = (rows / 3) + 2;
	PedalP_2[2][1] = cols - 10;

	PedalP_2[3][0] = (rows / 3) + 3;
	PedalP_2[3][1] = cols - 10;

	PedalP_2[4][0] = (rows / 3) + 4;
	PedalP_2[4][1] = cols - 10;

	PedalP_2[5][0] = (rows / 3) + 5;
	PedalP_2[5][1] = cols - 10;

	cout << "Enter Score Limit : ";
	cin >> limit;

	br = rows / 3.0, bc = (cols / 2.0) - 1.0;

	Score_P1 = 0, Score_P2 = 0;

	H_direction = Left, V_direction = Up;
}

void Save(int PedalP_1[][2], int PedalP_2[][2], int &limit, float &br, float &bc, int Score_P1, int Score_P2,
																				int H_direction,int V_direction)
{
	ofstream fout("Save.txt");
	for (int i = 0;i < 6;i++)
	{
		for (int c = 0;c < 2;c++)
		{
			fout << PedalP_1[i][c]<<"\t";
		}
	}
	//Now P2
	for (int i = 0;i < 6;i++)
	{
		for (int c = 0;c < 2;c++)
		{
			fout << PedalP_2[i][c] << "\t";
		}
	}

	fout << limit << "\t";

	fout << br << "\t" << bc<<"\t";
	fout << Score_P1 << "\t" << Score_P2<<"\t";
	fout<< H_direction<<"\t"<< V_direction;
	fout.close();
}

void Load(int PedalP_1[][2], int PedalP_2[][2], int &limit, float &br, float &bc, int &Score_P1, int &Score_P2, 
																				int &H_direction, int &V_direction)
{
	ifstream fin("Save.txt");
	for (int i = 0;i < 6;i++)
	{
		for (int c = 0;c < 2;c++)
		{
			fin >> PedalP_1[i][c];
		}
	}
	//Now P2
	for (int i = 0;i < 6;i++)
	{
		for (int c = 0;c < 2;c++)
		{
			fin>> PedalP_2[i][c];
		}
	}

	fin >> limit;

	fin >>br >> bc;
	fin >> Score_P1 >> Score_P2;
	fin >> H_direction  >> V_direction;
	fin.close();
}


//void Direct(int & Direction)
//{
//	int key = _getch();
//	if (key == 224)
//	{
//		key = _getch();
//		if (key == 72 && Direction != Down)		// Up
//			Direction = Up;
//		if (key == 80 && Direction != Up)		// Down
			//Direction = Down;
		//if (key == 75 && Direction != Right)	// Left
		//	Direction = Left;
		//if (key == 77 && Direction != Left)		// Right
//		//	Direction = Right;
//	}
//}
void MovePedal(int Pedal[][2], int direction, int rows, int cols)
{
	int hr;
	int Pedal_Top= Pedal[0][0];
	int pedal_end = Pedal[5][0];

	if (direction == Up)
	{
		hr = Pedal_Top;
		hr--;
		for (int s = 6 - 1; s >= 1; s--)
		{
			Pedal[s][0] = Pedal[s - 1][0];
		}
	}
	
	if (direction == Down)
	{
		hr= pedal_end;
		hr++;
		for (int s = 0; s <5; s++)
		{
			Pedal[s][0] = Pedal[s + 1][0];
		}
	}

	if (hr == 0)
		hr = rows - 1;
	if (hr>rows - 1)
		hr = 1;
	if (direction==Up)
		Pedal[0][0] = hr;
	else
		Pedal[5][0] = hr;
}

void Direct(int & Direction1, int & Direction2, int PedalP_1[][2], int PedalP_2[][2],int rows, int cols,int d, char sym,int limit,
													float br,float bc,int Score_P1,int Score_P2, int &H_direction, int &V_direction)
{
	char key = _getch();
	if (key == 'S' || key == 's')
	{
		Save(PedalP_1, PedalP_2, limit, br, bc, Score_P1, Score_P2,H_direction, V_direction);
		exit(1);
	}
	if (key == 'O' || key == 'o')
	{
		Direction2 = Up;
		Pedal_Display(PedalP_2, ' ', d);
		MovePedal(PedalP_2,Direction2,rows,cols);
		Pedal_Display(PedalP_2, sym, d);
	}
	else if (key == 'L' || key == 'l')
	{
		Direction2 = Down;
		Pedal_Display(PedalP_2, ' ', d);
		MovePedal(PedalP_2, Direction2, rows, cols);
		Pedal_Display(PedalP_2, sym, d);
	}

	else if (key == 'Q' || key == 'q')
	{
		Direction1 = Up;
		Pedal_Display(PedalP_1, ' ', d);
		MovePedal(PedalP_1, Direction1, rows, cols);
		Pedal_Display(PedalP_1, sym, d);
	}

	else if (key == 'A' || key == 'a')
	{
		Direction1 = Down;
		Pedal_Display(PedalP_1, ' ', d);
		MovePedal(PedalP_1, Direction1, rows, cols);
		Pedal_Display(PedalP_1, sym, d);
	}
}

bool Is_Pedal_P1_Hit(int br, int bc, int PedalP_1[][2])
{
	if (bc == PedalP_1[0][1])
	{
		for (int i = 0;i < 6;i++)
		{
			if (PedalP_1[i][0] == br)
				return 1;
		}
	}
	return 0;
}

bool Is_Pedal_P2_Hit(int br, int bc, int PedalP_2[][2])
{
	if (bc == PedalP_2[0][1])
	{
		for (int i = 0;i < 6;i++)
		{
			if (PedalP_2[i][0] == br)
				return 1;
		}
	}
	return 0;
}

bool Is_UpWall_Hit(int br, int bc, int rows)
{
	if (br ==0)
	{
			return 1;
	}
	return 0;
}
bool Is_DownWall_Hit(int br, int bc, int rows)
{
	if (br == rows)
	{
		return 1;
	}
	return 0;
}

void Watch_Out_Walls(float br, float bc, int rows,int cols, int &H_direction, int &V_direction)
{
	if (Is_UpWall_Hit(br, bc, rows))
	{
		V_direction = Down;
		Make_Board(rows, cols, -37);
	}
	if (Is_DownWall_Hit(br, bc, rows))
	{
		V_direction = Up;
		Make_Board(rows, cols, -37);
	}
}
void Direct_Ball(float br, float bc, int PedalP_1[][2], int PedalP_2[][2],char sym,int &H_direction,int &V_direction)
{
	if (Is_Pedal_P1_Hit(br, bc, PedalP_1))
	{
		H_direction = Right;
		Pedal_Display(PedalP_1, sym, 0);
	}
	if (Is_Pedal_P2_Hit(br, bc, PedalP_2))
	{
		H_direction = Left;
		Pedal_Display(PedalP_2, sym, 0);
	}
}

void Is_Goal(float &br, float &bc, int PedalP_1[][2], int PedalP_2[][2],int rows,int cols,int &Score_P1,int &Score_P2,
																					int &H_direction, int &V_direction)
{
	//bc < PedalP_1[0][1]
	if (bc < 2)
	{
		gotoRowCol(br, bc);
		cout << ' ';
		wait(1999);
		bc = cols / 2;
		H_direction = Right;
		Score_P2++;
		ScoreDisplay(rows, cols, Score_P1, Score_P2);
	}
	if (bc > cols-1)
	{
		gotoRowCol(br, bc);
		cout << ' ';
		wait(1999);
		bc = cols / 2;
		H_direction = Left;
		Score_P1++;
		ScoreDisplay(rows, cols, Score_P1, Score_P2);
	}
}

void Change_Ball_Position(float &br, float &bc, int PedalP_1[][2], int PedalP_2[][2],int rows,int cols,char sym,
																				int &H_direction, int &V_direction)
{
	Direct_Ball(br, bc, PedalP_1, PedalP_2,sym,H_direction, V_direction);
	Watch_Out_Walls(br, bc, rows,cols,H_direction, V_direction);
	if (H_direction == Right&& V_direction==Up)
	{
		br-=0.01;
		bc+=0.02;
	}
	if (H_direction ==Left && V_direction==Up)
	{
		br-=0.01;
		bc-=0.02;
	}

	if (H_direction == Left&& V_direction == Down)
	{
		br += 0.01;
		bc -= 0.02;
	}
	if (H_direction == Right && V_direction ==Down)
	{
		br += 0.01;
		bc += 0.02;
	}
}

void Display_Ball(float &br, float &bc, int PedalP_1[][2], int PedalP_2[][2],char bsym,int rows,int cols, int d,char sym,
																						int &H_direction, int &V_direction)
{
	gotoRowCol(br, bc);
	cout << ' ';
	Change_Ball_Position(br, bc, PedalP_1, PedalP_2,rows,cols,sym, H_direction, V_direction);
	gotoRowCol(br, bc);
	cout << bsym;
	wait(d);
}

bool Is_Game_Over(int limit,int rows,int cols,int Score_P1,int Score_P2)
{
	if (Score_P1==limit)
	{
		gotoRowCol(rows + 4, 10);
		cout << "Player 1 Wins!!!";
		return 1;
	}
	else if (Score_P2 == limit)
	{
		gotoRowCol(rows + 4, 10);
		cout << "Player 2 Wins!!!";
		return 1;
	}
	return 0;
}

void ScoreDisplay(int rows, int cols,int Score_P1,int Score_P2)
{
	gotoRowCol(rows + 2, 4);
	cout <<"P1 Score : "<< Score_P1;

	gotoRowCol(rows + 2, (cols/2)+3 );
	cout << "P2 Score : " << Score_P2;
}

void main()
{
	int rows = 60.0, cols = 80.0, d = 3,limit;
	char sym = -37, bsym = 1,choice;
	system("Color F0");

	int H_direction = Left, V_direction = Up;
	int Score_P1 = 0, Score_P2 = 0;
	float br,bc;
	int Direction1, Direction2;
	int PedalP_1[6][2];
	int PedalP_2[6][2];
	cout << "\nPlayer 1 Buttons : 'Q' for Up and 'A' for Down";
	cout << "\n\nPlayer 2 Buttons : 'O' for Up and 'L' for Down";
	cout << "\n\n\nNew Game or Load Game (N/L) : ";
	cin >> choice;
	if (choice == 'N' || choice == 'n')
		Initialize_Pedals(PedalP_1, PedalP_2, rows, cols, sym, limit, br, bc,Score_P1,Score_P2,H_direction, V_direction);

	else if (choice == 'L' || choice == 'l')
		Load(PedalP_1, PedalP_2, limit, br, bc, Score_P1, Score_P2, H_direction, V_direction);
	system("Cls");
	Make_Board(rows, cols,sym);
	
	Pedal_Display(PedalP_1, sym,0);
	Pedal_Display(PedalP_2, sym, 0);
	ScoreDisplay(rows, cols, Score_P1, Score_P2);
	Display_Ball(br, bc, PedalP_1, PedalP_2, bsym, rows, cols, d, sym, H_direction, V_direction);
	gotoRowCol(rows + 6, 3);
	cout << "Enter 'S' to Save the Game : ";
	
	wait(10000);
	do
	{
		Display_Ball(br,bc,PedalP_1,PedalP_2,bsym,rows, cols,d,sym,H_direction, V_direction);
		if (_kbhit())
			Direct(Direction1, Direction2,PedalP_1,PedalP_2,rows,cols,0,sym,limit,br,bc, Score_P1, Score_P2,H_direction,V_direction);
		Is_Goal(br, bc, PedalP_1, PedalP_2, rows, cols, Score_P1, Score_P2, H_direction, V_direction);
	} 
	while (!Is_Game_Over(limit,rows,cols, Score_P1, Score_P2));
	cout << "\n\n\n\n\n\n\n";
}


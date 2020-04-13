#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "Demo.h"
using namespace std;

static int Lifes = 3;
static int LifesContinue = 3;
static int Speed = 100;
static int SpeedContinue = 100;
static char letter;
static int curItem = 1;
static int i = 0;

void WriteMenu()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;


	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "          Start game       ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "        Speed of fall         ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, Vert);
	WriteStr(26, 12, "       Number of Lifes         ");
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, Vert);
	WriteStr(26, 13, "          QUIT GAME           ");
	WriteChar(56, 13, Vert);

	WriteChar(25, 14, Vert);
	WriteChars(26, 14, ' ', 30);
	WriteChar(56, 14, Vert);

	WriteChar(25, 15, LeftBottom);
	WriteChars(26, 15, Horz, 30);
	WriteChar(56, 15, RightBottom);

}

void WriteMenuQuit()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;


	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "    U SURE U WANT QUIT: Y|N ? ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteChars(26, 11, ' ', 30);
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, LeftBottom);
	WriteChars(26, 12, Horz, 30);
	WriteChar(56, 12, RightBottom);
}

void WriteMenuWish()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;


	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 40);
	WriteChar(66, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 40);
	WriteChar(66, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "    Do you wish to start new game: Y|N ? ");
	WriteChar(66, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteChars(26, 11, ' ', 40);
	WriteChar(66, 11, Vert);

	WriteChar(25, 12, LeftBottom);
	WriteChars(26, 12, Horz, 40);
	WriteChar(66, 12, RightBottom);
}

int MenuWish()
{
	const int Esc = 27;
	const int Enter = 13;

	const unsigned char Vert = 186;
	const unsigned char Horz = 205;


	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuWish();

	const int itemCount = 3;
	int curItem = 1;

	do
	{
		ChangeTextAttr(60 + curItem, 10, White, Black, 1);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:
				SetColor(Yellow, Cyan);
				WriteChars(26, 10, ' ', 30);
				SetColor(Yellow, Blue);
				WriteChars(56, 8, ' ', 4);
				WriteChars(56, 9, ' ', 4);
				WriteChars(56, 10, ' ', 4);
				WriteChars(56, 11, ' ', 4);
				WriteChars(56, 12, ' ', 4);

				WriteChar(60, 8, 186);
				WriteChar(60, 9, 186);
				WriteChar(60, 10, 186);
				WriteChar(60, 11, 186);
				WriteChar(60, 12, 186);

				WriteChars(61, 8, ' ', 6);
				WriteChars(61, 9, ' ', 6);
				WriteChars(61, 10, ' ', 6);
				WriteChars(61, 11, ' ', 6);
				WriteChars(61, 12, ' ', 2);

				WriteChar(63, 12, 'N');
				WriteChar(64, 12, 'u');
				WriteChar(65, 12, 'm');
				WriteChar(66, 12, 'b');

				curItem = 1;
				return 1;
				break;
			case 3:
				return 2;
				break;
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(60 + curItem, 10, White, Cyan, 1);

			switch (key)
			{
			case 77:        // Right
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			case 75:		// Left
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			}
		}
	} while (key != Esc);
	if (key == Esc)
	{
		WriteStr(26, 10, "                               ");
	}
}

int MenuQuit()
{
	const int Esc = 27;
	const int Enter = 13;

	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuQuit();

	const int itemCount = 3;
	int curItem = 1;

	do
	{
		ChangeTextAttr(49 + curItem, 10, White, Black, 1);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:
				return 1;
				break;
			case 3:
				WriteStr(26, 10, "                               ");
				curItem = 4;
				return 2;
				break;
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(49 + curItem, 10, White, Cyan, 1);

			switch (key)
			{
			case 77:        // Right
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			case 75:		// Left
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			}
		}
	} while (key != Esc);
	if (key == Esc)
	{
		WriteStr(26, 10, "                               ");
	}
}

int NotMain()
{

	const int Esc = 27;
	const int Enter = 13;

	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenu();

	const int itemCount = 4;

	do
	{
		ChangeTextAttr(26, 9 + curItem, White, Black, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:
				return 1;
				break;
			case 2:
				return 2;
				break;
			case 3:
				return 3;
				break;
			case 4:

				SetColor(Red, Black);

				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				int choi = MenuQuit();
				if (choi == 1)
				{
					exit(0);
				}
				else
				{
					main();
				}
				break;
			}
		}

		if (key == Esc)
		{

			SetColor(Green, Black);
			WriteChar(25, 13, ' ');
			WriteChars(26, 13, ' ', 30);
			WriteChar(56, 13, ' ');

			WriteChar(25, 14, ' ');
			WriteChars(26, 14, ' ', 30);
			WriteChar(56, 14, ' ');

			WriteChar(25, 15, ' ');
			WriteChars(26, 15, ' ', 30);
			WriteChar(56, 15, ' ');

			WriteChar(25, 16, ' ');
			WriteChars(26, 16, ' ', 30);
			WriteChar(56, 16, ' ');

			WriteChar(25, 17, ' ');
			WriteChars(26, 17, ' ', 30);
			WriteChar(56, 17, ' ');

			int choi = MenuQuit();
			if (choi == 1)
			{
				exit(0);
			}
			else
			{
				main();
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (Lifes != 0);

	ShowCursor(false);
}

void WriteMenuStartGame()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;

	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "        CONTINUE GAME      ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "           Options             ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, Vert);
	WriteStr(26, 12, "            Quit              ");
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, Vert);
	WriteChars(26, 13, ' ', 30);
	WriteChar(56, 13, Vert);

	WriteChar(25, 14, LeftBottom);
	WriteChars(26, 14, Horz, 30);
	WriteChar(56, 14, RightBottom);
}

void WriteMenuOptions()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;


	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "        Speed of fall         ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "    Back to the Pause Menu    ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 12, Vert);
	WriteChars(26, 12, ' ', 30);
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, LeftBottom);
	WriteChars(26, 13, Horz, 30);
	WriteChar(56, 13, RightBottom);

}

void MenuOptions()
{
	const int Esc = 27;
	const int Enter = 13;
	bool stop = false;
	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuOptions();

	const int itemCount = 2;

	do
	{
		ChangeTextAttr(26, 9 + curItem, White, Black, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 2:
				curItem = 1;
				stop = true;
				MenuSpeedOptions();
				break;
			case 1:
				SetColor(Red, Cyan);
				curItem = 2;
				WriteChars(26, 10, ' ', 30);
				stop = true;
				MenuCall();
				break;
			}
		}

		if (key == Esc)
		{
			stop = true;
			SetColor(Green, Blue);
			WriteChar(25, 13, ' ');
			WriteChars(26, 13, ' ', 30);
			WriteChar(56, 13, ' ');

			WriteChar(25, 14, ' ');
			WriteChars(26, 14, ' ', 30);
			WriteChar(56, 14, ' ');

			WriteChar(25, 15, ' ');
			WriteChars(26, 15, ' ', 30);
			WriteChar(56, 15, ' ');

			WriteChar(25, 16, ' ');
			WriteChars(26, 16, ' ', 30);
			WriteChar(56, 16, ' ');

			WriteChar(25, 17, ' ');
			WriteChars(26, 17, ' ', 30);
			WriteChar(56, 17, ' ');

			int choi = MenuQuit();
			if (choi == 1)
			{
				exit(0);
			}
			else
			{
				MenuOptions();
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (stop != true);
}

void MenuCall()
{
	const int Esc = 27;
	const int Enter = 13;
	bool stop = false;
	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuStartGame();

	const int itemCount = 3;

	do
	{
		ChangeTextAttr(26, 9 + curItem, Red, LightGreen, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:

				SetColor(Yellow, Blue);

				WriteChar(25, 8, ' ');
				WriteChars(26, 8, ' ', 30);
				WriteChar(56, 8, ' ');

				WriteChar(25, 9, ' ');
				WriteChars(26, 9, ' ', 30);
				WriteChar(56, 9, ' ');

				WriteChar(25, 10, ' ');
				WriteChars(26, 10, ' ', 30);
				WriteChar(56, 10, ' ');

				WriteChar(25, 11, ' ');
				WriteChars(26, 11, ' ', 30);
				WriteChar(56, 11, ' ');

				WriteChar(25, 12, ' ');
				WriteChars(26, 12, ' ', 30);
				WriteChar(56, 12, ' ');

				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');
				stop = true;
				ShiftLetter(letter);
				break;
			case 2:
				SetColor(Yellow, Blue);
				WriteChars(25, 14, ' ', 32);
				curItem = 1;
				MenuOptions();
				stop = true;
				break;
			case 3:

				SetColor(Green, Blue);
				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				int choi = MenuQuit();
				if (choi == 1)
				{
					exit(0);
				}
				else
				{
					MenuCall();
				}
				break;
			}
		}

		if (key == Esc)
		{
			stop = true;
			SetColor(Green, Blue);
			WriteChar(25, 13, ' ');
			WriteChars(26, 13, ' ', 30);
			WriteChar(56, 13, ' ');

			WriteChar(25, 14, ' ');
			WriteChars(26, 14, ' ', 30);
			WriteChar(56, 14, ' ');

			WriteChar(25, 15, ' ');
			WriteChars(26, 15, ' ', 30);
			WriteChar(56, 15, ' ');

			WriteChar(25, 16, ' ');
			WriteChars(26, 16, ' ', 30);
			WriteChar(56, 16, ' ');

			WriteChar(25, 17, ' ');
			WriteChars(26, 17, ' ', 30);
			WriteChar(56, 17, ' ');

			int choi = MenuQuit();
			if (choi == 1)
			{
				exit(0);
			}
			else
			{
				MenuCall();
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (stop != true);
}

void NumberOfLifes(int Lifes, int i)
{
	GotoXY(70, 10);
	cout << Lifes;
	if (Lifes == 2)
	{
		GotoXY(20, 11);
		cout << "C'MON U CAN DO BETTER";
		/*WriteChars(20, 11, ' ', 30);*/
	}
	if (Lifes == 1)
	{
		GotoXY(20, 11);
		WriteChars(20, 11, ' ', 21);
		GotoXY(20, 14);
		cout << "IT IS UR LAST RESORT";
	}
	if (Lifes == 0)
	{
		GotoXY(20, 14);
		WriteChars(20, 14, ' ', 21);
		GotoXY(20, 17);
		cout << "U ARE LOOOOOOOSER!!!!!!!!!11";
	}
	GotoXY(0, i);
}      //Сделать динамическое появление окон

void CountLetter(int CountLetters, int i)
{
	GotoXY(70, 1);
	cout << CountLetters;
	GotoXY(0, i);
}

int ShiftLetter(char letter)
{
	const int Esc = 27;
	const int Space = 32;
	static int CountLetters = 0;
	int key;
	int count = 0;
	NumberOfLifes(Lifes, i);

	do
	{
		cout << letter;
		Sleep(Speed);
		cout << "\b" << " " << endl;
		i++;
		if (i == 25)
		{
			Lifes--;
			i = (unsigned(0));
			return 4;
		}
		if (Lifes == 0)
		{
			return 0;
		}
	} while (!_kbhit());

	key = _getch();

	if (key == Space)
	{
		GotoXY(13, 2);
		cout << "Game has been paused, press SPACE to continuee";
		do
		{
			cout << "\b" << " " << endl;
		} while (_getch() != Space);
	}

	if (key == Esc)
	{ 
		count++;
		MenuCall();
	}

		if (key == letter)
		{
			CountLetters++;
			CountLetter(CountLetters, i);
			i = (unsigned(0));
			return 4;
		}
		else
		{
			if (key == Space)
			{
				WriteChars(13, 2, ' ', 45);
				ShiftLetter(letter);
			}
			else
			{
				Lifes += count;
				Lifes--;
				NumberOfLifes(Lifes, i);
				if (Lifes == 0)
				{
					return 0;
				}
				ShiftLetter(letter);
			}
		}
}

void StartGame()
{
	const unsigned char Vert = 186;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		letter = rand() % 25 + 97;
		int choi = ShiftLetter(letter);
		if (choi == 4)
		{
			GotoXY(0, 0);
			continue;
		}
		else
		{
			if (choi == 0)
				WriteChar(60, 22, Vert);
			cout << "        " << clock() / 1000.0;
			GotoXY(0, 0);
			cout << "GAME OVER !!!!" << endl;
			break;
		}
	}
	Sleep(1000);
	SetColor(Green, Black);
	system("cls");
	int choi = MenuWish();
	if (choi == 2)
	{
		exit(0);
	}
	else
	{
		Lifes = LifesContinue;
		Speed = SpeedContinue;
		SetColor(Green, Black);
		WriteChars(56, 8, ' ', 11);
		WriteChars(56, 9, ' ', 11);
		WriteChars(56, 10, ' ', 11);
		WriteChars(56, 11, ' ', 11);
		WriteChars(56, 12, ' ', 11);
		i = (unsigned(0));
		main();
	}
}

void AppearanceShiftLetter()
{
	SetColor(Yellow, Blue);
	system("cls"); // полезная хрень
	const unsigned char Vert = 186;
	const unsigned char Horz = 205;

	WriteChar(60, 0, Vert);
	WriteChar(60, 1, Vert);
	WriteChar(60, 2, Vert);
	WriteStr(60, 3, "  Number of Symblos");
	WriteChar(60, 3, Vert);
	WriteChar(60, 4, Vert);
	WriteChar(60, 5, Vert);
	WriteChar(60, 6, Vert);
	WriteChar(60, 7, Vert);
	WriteChar(60, 8, Vert);
	WriteChar(60, 9, Vert);
	WriteChar(60, 10, Vert);
	WriteChar(60, 11, Vert);
	WriteStr(60, 12, "   Number of lifes");
	WriteChar(60, 12, Vert);
	WriteChar(60, 13, Vert);
	WriteChars(60, 13, Horz, 20);
	WriteChar(60, 14, Vert);
	WriteChar(60, 15, Vert);
	WriteChar(60, 16, Vert);
	WriteChar(60, 17, Vert);
	WriteChar(60, 18, Vert);
	WriteChar(60, 19, Vert);
	WriteChar(60, 20, Vert);
	WriteChar(60, 21, Vert);
	WriteChar(60, 22, Vert);
	WriteChar(60, 23, Vert);
	WriteStr(60, 24, "         Time         ");
	WriteChar(60, 24, Vert);
	WriteChar(60, 25, Vert);
	GotoXY(0, 0);
	StartGame();
}

void WriteMenuLife()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;

	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "     BACK TO THE MAIN MENU    ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "          Start game       ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, Vert);
	WriteStr(26, 12, "              5               ");
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, Vert);
	WriteStr(26, 13, "              4                ");
	WriteChar(56, 13, Vert);

	WriteChar(25, 14, Vert);
	WriteStr(26, 14, "              3                ");
	WriteChar(56, 14, Vert);

	WriteChar(25, 15, Vert);
	WriteStr(26, 15, "          QUIT GAME           ");
	WriteChar(56, 15, Vert);

	WriteChar(25, 16, Vert);
	WriteChars(26, 16, ' ', 30);
	WriteChar(56, 16, Vert);

	WriteChar(25, 17, LeftBottom);
	WriteChars(26, 17, Horz, 30);
	WriteChar(56, 17, RightBottom);
}

int MenuLife()
{
	const int Esc = 27;
	const int Enter = 13;

	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuLife();

	const int itemCount = 6;

	do
	{
		ChangeTextAttr(26, 9 + curItem, White, Black, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:

				SetColor(Red, Black);

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				SetColor(Red, Cyan);
				WriteChars(27, 10, ' ', 30);

				curItem = 3;
				main();

				break;
			case 2:
				curItem = 1;
				AppearanceShiftLetter();
				break;
			case 3:
				Lifes = 5;
				LifesContinue = Lifes;
				break;
			case 4:
				Lifes = 4;
				LifesContinue = Lifes;
				break;
			case 5:
				Lifes = 3;
				LifesContinue = Lifes;
				break;
			case 6:

				SetColor(Green, Black);
				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				int choi = MenuQuit();
				if (choi == 1)
				{
					exit(0);
				}
				else
				{
					curItem = 6;
					MenuLife();
				}
				break;
			}
		}

		if (key == Esc)
		{

			SetColor(Green, Black);
			WriteChar(25, 13, ' ');
			WriteChars(26, 13, ' ', 30);
			WriteChar(56, 13, ' ');

			WriteChar(25, 14, ' ');
			WriteChars(26, 14, ' ', 30);
			WriteChar(56, 14, ' ');

			WriteChar(25, 15, ' ');
			WriteChars(26, 15, ' ', 30);
			WriteChar(56, 15, ' ');

			WriteChar(25, 16, ' ');
			WriteChars(26, 16, ' ', 30);
			WriteChar(56, 16, ' ');

			WriteChar(25, 17, ' ');
			WriteChars(26, 17, ' ', 30);
			WriteChar(56, 17, ' ');

			int choi = MenuQuit();
			if (choi == 1)
			{
				exit(0);
			}
			else
			{
				MenuLife();
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (Lifes != 0);
}

void WriteMenuSpeed()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;

	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "     BACK TO THE MAIN MENU    ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "          Start game          ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, Vert);
	WriteStr(26, 12, "              1000             ");
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, Vert);
	WriteStr(26, 13, "              600              ");
	WriteChar(56, 13, Vert);

	WriteChar(25, 14, Vert);
	WriteStr(26, 14, "              300              ");
	WriteChar(56, 14, Vert);

	WriteChar(25, 15, Vert);
	WriteStr(26, 15, "          QUIT GAME           ");
	WriteChar(56, 15, Vert);

	WriteChar(25, 16, Vert);
	WriteChars(26, 16, ' ', 30);
	WriteChar(56, 16, Vert);

	WriteChar(25, 17, LeftBottom);
	WriteChars(26, 17, Horz, 30);
	WriteChar(56, 17, RightBottom);
}

void WriteMenuSpeedOptions()
{
	const unsigned char LeftTop = 201;
	const unsigned char Horz = 205;
	const unsigned char Vert = 186;
	const unsigned char RightTop = 187;
	const unsigned char LeftBottom = 200;
	const unsigned char RightBottom = 188;

	WriteChar(25, 8, LeftTop);
	WriteChars(26, 8, Horz, 30);
	WriteChar(56, 8, RightTop);

	WriteChar(25, 9, Vert);
	WriteChars(26, 9, ' ', 30);
	WriteChar(56, 9, Vert);

	WriteChar(25, 10, Vert);
	WriteStr(26, 10, "   BACK TO THE PREVIOUS MENU  ");
	WriteChar(56, 10, Vert);

	WriteChar(25, 11, Vert);
	WriteStr(26, 11, "          CONTINUE GAME       ");
	WriteChar(56, 11, Vert);

	WriteChar(25, 12, Vert);
	WriteStr(26, 12, "              1000             ");
	WriteChar(56, 12, Vert);

	WriteChar(25, 13, Vert);
	WriteStr(26, 13, "              600              ");
	WriteChar(56, 13, Vert);

	WriteChar(25, 14, Vert);
	WriteStr(26, 14, "              300              ");
	WriteChar(56, 14, Vert);

	WriteChar(25, 15, Vert);
	WriteStr(26, 15, "           QUIT GAME           ");
	WriteChar(56, 15, Vert);

	WriteChar(25, 16, Vert);
	WriteChars(26, 16, ' ', 30);
	WriteChar(56, 16, Vert);

	WriteChar(25, 17, LeftBottom);
	WriteChars(26, 17, Horz, 30);
	WriteChar(56, 17, RightBottom);
}

int MenuSpeedOptions()
{
	const int Esc = 27;
	const int Enter = 13;
	bool stop = false;
	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuSpeedOptions();

	const int itemCount = 6;

	do
	{
		ChangeTextAttr(26, 9 + curItem, White, Black, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:

				SetColor(Red, Blue);

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				curItem = 2;
				stop = true;
				MenuOptions();

				break;
			case 2:
				SetColor(Yellow, Blue);

				WriteChar(25, 8, ' ');
				WriteChars(26, 8, ' ', 30);
				WriteChar(56, 8, ' ');

				WriteChar(25, 9, ' ');
				WriteChars(26, 9, ' ', 30);
				WriteChar(56, 9, ' ');

				WriteChar(25, 10, ' ');
				WriteChars(26, 10, ' ', 30);
				WriteChar(56, 10, ' ');

				WriteChar(25, 11, ' ');
				WriteChars(26, 11, ' ', 30);
				WriteChar(56, 11, ' ');

				WriteChar(25, 12, ' ');
				WriteChars(26, 12, ' ', 30);
				WriteChar(56, 12, ' ');

				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				curItem = 1;
				stop = true;
				ShiftLetter(letter);
				break;
			case 3:
				Speed = 1000;
				SpeedContinue = Speed;
				break;
			case 4:
				Speed = 600;
				SpeedContinue = Speed;
				break;
			case 5:
				Speed = 300;
				SpeedContinue = Speed;
				break;
			case 6:
				stop = true;
				SetColor(Green, Blue);
				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				int choi = MenuQuit();
				if (choi == 1)
				{
					exit(0);
				}
				else
				{
					curItem = 6;
					MenuSpeedOptions();
				}
				break;
			}
		}

		if (key == Esc)
		{
			stop = true;
			SetColor(Green, Blue);
			WriteChar(25, 13, ' ');
			WriteChars(26, 13, ' ', 30);
			WriteChar(56, 13, ' ');

			WriteChar(25, 14, ' ');
			WriteChars(26, 14, ' ', 30);
			WriteChar(56, 14, ' ');

			WriteChar(25, 15, ' ');
			WriteChars(26, 15, ' ', 30);
			WriteChar(56, 15, ' ');

			WriteChar(25, 16, ' ');
			WriteChars(26, 16, ' ', 30);
			WriteChar(56, 16, ' ');

			WriteChar(25, 17, ' ');
			WriteChars(26, 17, ' ', 30);
			WriteChar(56, 17, ' ');

			int choi = MenuQuit();
			if (choi == 1)
			{
				exit(0);
			}
			else
			{
				MenuSpeedOptions();
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (stop != true);
}

int MenuSpeed()
{
	const int Esc = 27;
	const int Enter = 13;

	int key;

	ShowCursor(false);
	SetColor(White, Cyan);

	WriteMenuSpeed();

	const int itemCount = 6;

	do
	{
		ChangeTextAttr(26, 9 + curItem, White, Black, 30);

		key = _getch();

		if (key == Enter)
		{
			switch (curItem)
			{
			case 1:

				SetColor(Red, Black);

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');

				SetColor(Red, Cyan);
				WriteChars(27, 10, ' ', 30);

				curItem = 2;
				main();

				break;
			case 2:
				curItem = 1;
				AppearanceShiftLetter();
				break;
			case 3:
				Speed = 1000;
				SpeedContinue = Speed;
				break;
			case 4:
				Speed = 600;
				SpeedContinue = Speed;
				break;
			case 5:
				Speed = 300;
				SpeedContinue = Speed;
				break;
			case 6:

				SetColor(Green, Black);
				WriteChar(25, 13, ' ');
				WriteChars(26, 13, ' ', 30);
				WriteChar(56, 13, ' ');

				WriteChar(25, 14, ' ');
				WriteChars(26, 14, ' ', 30);
				WriteChar(56, 14, ' ');

				WriteChar(25, 15, ' ');
				WriteChars(26, 15, ' ', 30);
				WriteChar(56, 15, ' ');

				WriteChar(25, 16, ' ');
				WriteChars(26, 16, ' ', 30);
				WriteChar(56, 16, ' ');

				WriteChar(25, 17, ' ');
				WriteChars(26, 17, ' ', 30);
				WriteChar(56, 17, ' ');


				int choi = MenuQuit();
				if (choi == 1)
				{
					exit(0);
				}
				else
				{
					curItem = 6;
					MenuSpeed();
				}
				break;
			}
		}

		if (key == Esc)
		{

			SetColor(Green, Black);
			WriteChar(25, 13, ' ');
			WriteChars(26, 13, ' ', 30);
			WriteChar(56, 13, ' ');

			WriteChar(25, 14, ' ');
			WriteChars(26, 14, ' ', 30);
			WriteChar(56, 14, ' ');

			WriteChar(25, 15, ' ');
			WriteChars(26, 15, ' ', 30);
			WriteChar(56, 15, ' ');

			WriteChar(25, 16, ' ');
			WriteChars(26, 16, ' ', 30);
			WriteChar(56, 16, ' ');

			WriteChar(25, 17, ' ');
			WriteChars(26, 17, ' ', 30);
			WriteChar(56, 17, ' ');

			int choi = MenuQuit();
			if (choi == 1)
			{
				exit(0);
			}
			else
			{
				MenuSpeed();
			}
		}

		if (key == 0 || key == 0xE0)
		{
			key = _getch();

			ChangeTextAttr(26, 9 + curItem, White, Cyan, 30);

			switch (key)
			{
			case 71:		// Home
				curItem = 1;
				break;
			case 72:		// Up
				if (curItem == 1)
					curItem = itemCount;
				else
					curItem--;
				break;
			case 79:		// End
				curItem = itemCount;
				break;
			case 80:		// Down
				if (curItem == itemCount)
					curItem = 1;
				else
					curItem++;
				break;
			}
		}
	} while (Lifes != 0);
}

void main()
{
	switch (NotMain())
	{
	case 1:
		AppearanceShiftLetter();
		break;
	case 2:
		curItem = 1;
		MenuSpeed();
		break;
	case 3:
		curItem = 1;
		MenuLife();
		break;
	case 4:
		int choi = MenuQuit();
		if (choi == 1)
		{
			exit(0);
		}
		else
		{
			main();
		}
		break;
	}
}









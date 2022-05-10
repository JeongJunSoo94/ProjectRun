#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
void GotoXY(int x, int y)//커서의 위치
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

COORD GetXY()//커서 이동
{
	COORD pos;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&curInfo);
	pos.X = curInfo.dwCursorPosition.X;
	pos.Y = curInfo.dwCursorPosition.Y;
}
/*
o      전혀 안눌려진 상황
0x8000 호출 전 눌린적 없고 호출 시점에 눌린 상태
0x8001 호출 전 눌려 있고 호출 시점에도 눌린 상태
1      호출 전 눌린적 있고 호출 시점에는 안 눌린 상태
*/

int GetKeyDown()//키 입력받기
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
	//GetAsyncKeyState(VK_SPACE& 0x8000);
}


void Clear()//화면 초기화
{
	system("cls");
}

void SetColor(unsigned char bgcolor, unsigned char textcolor)//글씨 폰트 변경
{
	if (bgcolor > 15 || textcolor > 15)return;

	unsigned short colornum = (bgcolor << 4) | textcolor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colornum);
}

void HideCursor(int _switch)
{
	CONSOLE_CURSOR_INFO curInfo ={0};
	curInfo.bVisible = _switch;//onoff
	curInfo.dwSize = 100;//size 1~100
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
/*
int FullScreen(void)
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	return 0;
}
*/

void SetDisplaySize(int cols,int line)
{
	char str[100];
	sprintf(str,"mode con cols=%d lines=%d", cols, line);
	system(str);
}

int isCollision()
{

	return 0;
}

int SetFontSize(int a, int b)
{

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX *cfi = malloc(sizeof(CONSOLE_FONT_INFOEX));

	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = cfi;

	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

	lpConsoleCurrentFontEx->dwFontSize.X = a;

	lpConsoleCurrentFontEx->dwFontSize.Y = b;

	SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);
}
void slime(int x,int y)
{
	GotoXY(x, y);
	printf("	 .,:lxOXWWNNNNWWXOxl,.     \n");
	GotoXY(x, y+1);
	printf("    'lkXWWMMMMMMMMMMWNKkl'  \n");
	GotoXY(x, y+2);
	printf("'dKWMMMMMMMMMMWNXXNNMMMMWKd'\n");
	GotoXY(x, y+3);
	printf(".xNMMMWNNNNWMMMMMMWWNNNWNMMMNd.\n");
	GotoXY(x, y+4);
	printf("lNMMMWx;'';dNMMMMMMMMMMMMMMMMMNl\n");
	GotoXY(x, y+5);
	printf("OWMMMXc    ,0MMMMMMMMMMMMMMMMMMWO \n");
	GotoXY(x, y+6);
	printf("WMMMMWO:.'cOWMMMMMMMMMMMMMMMMMMMW \n");
	GotoXY(x, y+7);
	printf("WMMMMMMNXXWMMMMMMMMMMMMMMMMMMMMN\n");
	GotoXY(x, y+8);
	printf(".xNWMMMMMMMMMMMMMMMMMMMMMMMMWXd.\n");
	GotoXY(x, y+9);
	printf(" .cONWMMMMMMMMMMMMNNNNMMMWNXd.\n");
}
void dino()
{
	printf("                  ..........\n");
	printf("               ..;k0O0KKKKKKKd'\n");
	printf("               ,xKM   $$$$$$$$k.\n");
	printf("               ,xKM   $$$$$$$$k.\n");
	printf("               ,xK$$$$$$$$$$$Mk.\n");
	printf("               ,xK#####N \n");
	printf("              ;xK$$$$$$$$$$$$K\n");
	printf(".c.        ..c0NWMMMWx\n");
	printf(";0d.     'ckXWMMMMMMMWk\n");
	printf(",KMKl'.'oXMMMMMMMMMM Wkdk,\n");
	printf(" .c0WMMMMMMMMMMMMMMM  NO,\n");
	printf("  .c0NMMMMMMMMMMMMNx\n");
	printf("     .c0WMMMMWMMMNk;\n");
	printf("       .oXMNOldXNK;\n");
	printf("        ,0O:.  :OO;\n");
	printf("        'kx'   'okx'\n");
	printf("         .,.    ..'.\n");
	
}

int main()
{
	SetDisplaySize(1200, 600);
	system("title run");
	HideCursor(0);

	SetFontSize(10,1);
	GotoXY(00, 50);
	dino();
	slime(140,55);
	return 0;
}
#include <stdio.h>
#include <iostream>
#include <conio.h>	 
#include <Windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int height, width, HEIGHT, WIDTH, speedOption(1), gameSizeOption(3), gameSize[5][2];

int xCoordinateOfPlayer, yCoordinateOfPlayer, score, countOfTail, tail[10000][2];
int xCoordinateOfFood, yCoordinateOfFood;
int countOfMenu, delayTime, sum;
bool isAppearing, isOut;
char keyPressing, tempKeyPressing, oldKeyPressing;


void image() {
	cout << " @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#BBPPPYY5JY55B&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@&&###&&&&##B&@@@@@@@@&BGYJ?7?7!77!7!!77!7??5B@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@&BJ~GY???JJJ^^P&@@#PY?77!7!!7!!7!!!!!7!!777???5#@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@&&#&BB#G?7?7JY??Y??!~~!!!!7!!!77777??JJJJYJJYJJYJYB@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@#BG55YJJJJJYGB#&#GGGBGPYY7^^~~!!!777??JJYY5P55PGGGGGGGGGGPPG&@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@#PJ77!7!77?JJY5YP#&&&##BPJ!^^~!77??JYYY5PPPGGBGBB#B#########BB#&@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@B5J??7????JJY5PGB###&##BP5Y!!7JY5YY55PPGGBBB###&&&#GPPGGPG##BBB&@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@&GPYJJ?YY55PGBBBBBBB#GPPPP5YY55PP55PPPGG##&&@@@@@#GYYYYJ?75B####@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@GPP555PGBBGPP555J?55YY55555PPPPPPGB#&@@@@@@@&#GP5JJJ?77JGGB###@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@&#BBGBBB5J7!!!!7?JY5PPPPPPPGGGB#&@@@@@@@&#BGPPPP5Y?77?5GGBB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@&#GGGP5YYYYJYY55P5PPPPGB#&@@@@@@@@&#BGGPGGGP5YJ7??Y5PGB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@&#BBGGPPPPPPPPGGB#&@@@@@@@@&#BPPPPPGGGGP5???JY5PGBB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#PJ?7?JJ55PPPP5J?JJY5PPGBB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&GJ!~~~~!7??JJJYYYYY55PGGBB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#5?7!~~~!~!!777??J5PPPGGGGB#&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@@@@@#PJ7~~~!~!!!!7!77??YGGGGGGB#&@@@@@&&&#########&&&&@@@@@@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@@@@&B5?77!!!~!~!!7!!77??55PPPGG#&@@@@&#G5YYYJJJJJJJYYY5555PB#&@@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@@@&BY?7!7!!~!~!~7!!7!7?J55PPPG#&@@@@@&BP55JJJJJJJJJ??JJYYY55555P#@@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@@@@#PJ777!!!!!!!!!!7!7??Y5GGGGG#&@@@@@&#GGPPP555555PGGGGGPPP55555PPG#@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@@@@&B5J?7!!7!77!!~77!??7Y55GB#G5Y5555YYYYYYYYYYYYYYYYYY55PPPPGGGPPPPGGG#@@@@@@@@@@@@@@@\n @@@@@@@@@@@@@&#G5Y?77777!!!!7!!77?JYYPB#BP5YYYYYYJJYJJJJJJJJJJJJ?J??J????77?77????JJJ5PPGGGGBBBB####\n @@@@@@@@@&&#BGPYJ?7?77777!!??7JYJJ5PBBBPYJYJJJJJJJJJJ??JJJJJJJJJ?????????777777777!!!!!!!!!!!!!!~!!!\n @@@@@@@&##BGGPYJY77?7?7??7?JJ?YPPPGG5J???7777?77777777777777777777777?7777777777!!7!!!!!!!!!!!!!!!~~\n @@@@@@@&#BBBPPJJJ??7?77JJ?J555PGGPJ?7???7777??????7??7??7777777777!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n @@@@@@@&BBGP55JJJJ7?J??YYYYPGGPYJ???JJJJJJJ?JJJJ??????????????7?7777777!!!!!!!!!~!!!~!!~!!!!~!~~~!~~\n @@@@@@@&GGP5YYY?JJ??YJJJYPPPP555PGGBBBBBBGGGGPPPPPP5555555555555YYJJ??777777!7!!!!!!!!!!!!!!~~!!~!!~\n @@@@@@@@#GP5YJYJ?JJJJY5PB&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&#BGP5YJ??7777!7!!!!!!!~!!~~!!~~!\n @@@@@@@@@#P5YJJ?777?5B#&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&&&&&&######BBBBGPPP55\n @@@@@@@@@@&&&&######&&&&&&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
	Sleep(3000);
}

void setup() {
	gameSize[1][1] = 10; gameSize[1][2] = 5;
	gameSize[2][1] = 20; gameSize[2][2] = 10;
	gameSize[3][1] = 50; gameSize[3][2] = 15;
	gameSize[4][1] = 70; gameSize[4][2] = 20;
	gameSize[5][1] = 70; gameSize[5][2] = 30;
	srand(time(0));
	countOfTail = 1;
	score = 0;
	height = gameSize[gameSizeOption][2];
	width = gameSize[gameSizeOption][1];
	xCoordinateOfPlayer = width/ 2;
	yCoordinateOfPlayer = height / 2;
	keyPressing = 'P';
	xCoordinateOfFood = rand() % (width-1); yCoordinateOfFood = rand() % (height-1);
	oldKeyPressing = 'o';
}
void draw() {
	string buffer;
	for (int i(1); i <= width; i++)  buffer += "#";
	for (int penOfY(2); penOfY <= height - 1; penOfY++) {
		buffer += "\n";
		for (int penOfX(1); penOfX <= width; penOfX++) {
			if (penOfX == 1 || penOfX == width) buffer +=  "#";
			else {
				isAppearing = 0;
				if (penOfX == xCoordinateOfPlayer && penOfY == yCoordinateOfPlayer) buffer += "O";
				else if (penOfX == xCoordinateOfFood && penOfY == yCoordinateOfFood) buffer += "E";
				else {
					for (int i(1); i < countOfTail; i++) {
						if (penOfX == tail[i][1] && penOfY == tail[i][2]) {
							buffer += "0";
							isAppearing = 1;
							break;
						}
					}
					if (isAppearing == 0) buffer += " ";
				}
			}
		}
		
	}
	buffer += "\n";
	for (int i(1); i <= width; i++) buffer += "#";
	buffer += "\n A W S D: MOVE       P: EXIT\n";
	cout << buffer;
	//cout << keyPressing << " " << oldKeyPressing << "\n";
}
	


void logic() {
	if (_kbhit()) {
		keyPressing = _getch();
	}
	///Debug
	cout << "\nScore: " << score; cout << "\n";
	/*for (int i(1); i <= countOfTail; i++) cout << tail[i][1] << " "; cout << "\n";
	for (int i(1); i <= countOfTail; i++) cout << tail[i][2] << " ";
	//cout << "\n";
	//cout << xCoordinateOfFood << " " << yCoordinateOfFood;
	/// */

	///Control
	sum = keyPressing + oldKeyPressing;
	if (sum == 197 || sum == 234) keyPressing = oldKeyPressing;
	switch (keyPressing) {
		case 'a':{
			oldKeyPressing = keyPressing;
			xCoordinateOfPlayer--;
			if(delayTime!= 41) delayTime = 41/speedOption;
			break;
		}
		case 'w': {
			oldKeyPressing = keyPressing;
			yCoordinateOfPlayer--;
			if (delayTime != 82) delayTime = 82/speedOption;
			break;
		}
		case 'd': {
			oldKeyPressing = keyPressing;
			xCoordinateOfPlayer++;
			if (delayTime != 41) delayTime = 41/ speedOption;
			break;
		}
		case 's': {
			oldKeyPressing = keyPressing;
			yCoordinateOfPlayer++;
			if (delayTime != 82) delayTime = 82 / speedOption;
			break;
		}
		case 'o': {
		}
	}
	////
	
	if (xCoordinateOfFood == 1 || xCoordinateOfFood == 0) xCoordinateOfFood = 2;
	if (yCoordinateOfFood == 1 || yCoordinateOfFood == 0) yCoordinateOfFood = 2;



	////This code will teleport your character when it touch the wall
	if (yCoordinateOfPlayer <= 1) yCoordinateOfPlayer = height - 1;
	else if (yCoordinateOfPlayer >= height) yCoordinateOfPlayer = 2;
	if (xCoordinateOfPlayer <= 1) xCoordinateOfPlayer = width - 1;
	else if (xCoordinateOfPlayer >= width) xCoordinateOfPlayer = 2;
	if (xCoordinateOfPlayer == xCoordinateOfFood && yCoordinateOfPlayer == yCoordinateOfFood) {
		srand(time(0));
		xCoordinateOfFood = rand() % (width - 1);
		yCoordinateOfFood = rand() % (height - 1);
		score++;
		countOfTail++;
	}
	for(int i(countOfTail); i >= 1; i--){
		tail[i][1] = tail[i - 1][1];
		tail[i][2] = tail[i - 1][2];
		if (xCoordinateOfPlayer == tail[i][1] && yCoordinateOfPlayer == tail[i][2] && i > 1) {
			isOut = 1;
			while (true) {
				system("cls");
				cout << "YOUR SCORE:" << score;
				cout << "\nPress Enter to continue";
				if (_kbhit()) {
					keyPressing = _getch();
				}
				if(keyPressing == 13) break;
				Sleep(300);
			}
			return;
		}
	}
	tail[0][1] = xCoordinateOfPlayer; tail[0][2] = yCoordinateOfPlayer;
}

void startGame() {
	setup();
	isOut = 0;
	while (isOut == 0) {
		draw();
		logic();
		Sleep(delayTime);
		system("cls");
	}
}


void drawMenu() {
	string buffer;
	if (_kbhit()) {
		keyPressing = _getch();
	}
	if (keyPressing == 's') {
		countOfMenu++;
		keyPressing = 'o';
	}
	else if (keyPressing == 'w') {
		countOfMenu--;
		keyPressing = 'o';
	}
	else if (keyPressing == 13) {
		isOut = 1;  return;
	}

	if (countOfMenu > 3) countOfMenu = 1;
	else if (countOfMenu < 1) countOfMenu = 3;

	for (int i(1); i <= 30; i++) buffer += "=";
	for (int i(2); i <= 19; i++) {
		buffer += "\n";
		for (int j(1); j <= 30; j++) {
			if (j == 1 || j == 30 - 1) buffer += "=";

			switch (countOfMenu) {
			case 1: {
				if (j == 8 && i == 5) buffer += '*';
				break;
			}
			case 2: {
				if (j == 8 && i == 7) buffer += '*';
				break;
			}
			case 3: {
				if (j == 8 && i == 9) buffer += '*';
				break;
			}

			}
			if (j == 10 && i == 2) {
				buffer += "MAIN MENU          =          TURN OFF UNIKEY BEFORE PLAYING GAME";
				break;
			}
			if (j == 10 && i == 5) {
				buffer += "  START            =          W: UP    S: DOWN   A: DECREASE   D: INCRESE";
				break;
			}
			if (j == 10 && i == 7) {
				buffer += "  OPTION           =          ENTER: SELECT";
				break;
			}
			if (j == 10 && i == 9) {
				buffer += "   EXIT            =";
				break;
			}
			else buffer += " ";
		}
	}

	buffer += '\n';
	for (int i(1); i <= 30; i++) buffer += "=";
	system("cls");
	cout << buffer;
}

void option() {
	keyPressing = 'o';
	string buffer;
	system("cls");
		if (_kbhit()) {
			keyPressing = _getch();
		}
		if (keyPressing == 's') {
			countOfMenu++;
		}
		else if (keyPressing == 'w') {
			countOfMenu--;
		}
		else if (keyPressing == 'a') {
			if (countOfMenu == 1) {
				speedOption--;
			}
			else if (countOfMenu == 2) {
				gameSizeOption--;
			}
		}
		else if (keyPressing == 'd') {
			if (countOfMenu == 1) speedOption++;
			else if (countOfMenu == 2) gameSizeOption++;
		}
		else if (keyPressing == 13 && countOfMenu == 3) {
			setup(); isOut = 1; return;
		}
		
		if (speedOption > 4) speedOption = 4;
		else if (speedOption < 1) speedOption = 1;
		if (gameSizeOption > 5) gameSizeOption = 5;
		else if (gameSizeOption < 1) gameSizeOption = 1;

		buffer += "============OPTION============";
			buffer += "\n";
			if (countOfMenu == 1) buffer += " * ";
			buffer += "      Speed: ";
			for (int i(1); i <= speedOption; i++) buffer += "0";
			buffer += " "; buffer += speedOption; buffer += "\n";
			if (countOfMenu == 2) buffer += " * ";
			buffer += "      Game size: ";
			for (int i(1); i <= gameSizeOption; i++) buffer += "0";
			buffer += "\n";
			if (countOfMenu == 3) buffer += " * ";
			buffer += "      OK";
		
		cout << buffer;
		//system("cls");
		
}

void mainMenu() {
	isOut = 0;
	while (isOut == 0) {
		drawMenu();
		Sleep(41);
	}
	switch (countOfMenu) {
	case 1: {startGame(); break; }
	case 2: {
			system("cls"); 
			countOfMenu = 1;
			isOut = 0;
			while (isOut == 0) {
				option();
				Sleep(100);
			}
			break;
	}
	case 3: {exit(0); }
	default: {
	}
	}
}





int main() {
	while (true) {
		image();
		countOfMenu = 1;
		setup();
		mainMenu();
	}
}
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "game.h"

// �� �� �� �� �� ��

int headDirectionWeight[4][2] = {
	{0, -1}, // ���� �̵�
	{0, 1}, // �Ʒ��� �̵�
	{-2, 0}, // �������� �̵�
	{2, 0} // ���������� �̵�
};

int setHeadDirection(int pressedKeyData);
void moveSnakeHead(int &posX, int &posY, int headDirection);

int main()
{
	int currentPosX;
	int currentPosY;
	int currentHeadDirection = 0;
	printMapBoundary();
	setCursorPos(MAP_CENTER_HORIZON * 2, MAP_CENTER_VERTICAL);
	printf("��");
	currentPosX = MAP_CENTER_HORIZON * 2;
	currentPosY = MAP_CENTER_VERTICAL;
	while (true) {
		int refTime = clock();
		int currentTime=0;
		while (true) {
			if (kbhit()) {
				if (getch() == 224) {
					int pressedKey = getch();
					currentHeadDirection = setHeadDirection(pressedKey);
				}
			}
			currentTime += clock()-refTime;
			if (currentTime > 300000) {
				currentTime = 0;
				break;
			}
		}
		moveSnakeHead(currentPosX, currentPosY, currentHeadDirection);
	}
	return 0;
}

void moveSnakeHead(int &posX, int &posY, int headDirection) {
	int prePosX = posX + headDirectionWeight[headDirection][0];
	int prePosY = posY + headDirectionWeight[headDirection][1];
	if (prePosX < 2 || prePosX>(MAP_SIZE_HORIZON - 2) * 2)return;
	if (prePosY < 1 || prePosY>MAP_SIZE_VERTICAL)return;
	setCursorPos(posX, posY);
	printf("  ");
	posX = prePosX;
	posY = prePosY;
	setCursorPos(posX, posY);
	printf("��");
}

int setHeadDirection(int pressedKeyData) {
	int changedHeadDirection;
	switch (pressedKeyData) {
	case KEY_CODE_UP:
		// ���� ������ ���� ����
		changedHeadDirection = 0;
		break;

	case KEY_CODE_DOWN:
		// ���� ������ �Ʒ��� ����
		changedHeadDirection = 1;
		break;

	case KEY_CODE_LEFT:
		// ���� ������ ���ʷ� ����
		changedHeadDirection = 2;
		break;

	case KEY_CODE_RIGHT:
		// ���� ������ �����ʷ� ����
		changedHeadDirection = 3;
		break;

	default:
		break;
	}
	return changedHeadDirection;
}
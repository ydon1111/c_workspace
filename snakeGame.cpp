#include <windows.h> //setcolor, gotoxy
#include <iostream> 
#include <conio.h> //방향키 입력받기
#include <random> //랜덤
#include <time.h> //srand(time(NULL))
using namespace std;
#define LEFT 75 
#define RIGHT 77 
#define UP 72 
#define DOWN 80 
char board[40][20] = { ' ' }; 
void gotoxy(int x, int y)
{ 
    COORD pos = { x, y }; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
} 
void setcolor(int color, int bgcolor)
{ 
    color &= 0xf; 
    bgcolor &= 0xf; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
} 
struct position{ 
    int x; 
    int y; 
}; 
struct snake{ 
    int direction = RIGHT; 
    int length = 3; 
    position pos[101]; 

}; 
int gameover = 0; 
snake game; 
void printscreen(){ 
    for (int i = 0; i < 20; i++){ 
        for (int j = 0; j < 40; j++)
            printf("%c", board[j][i]); 
        cout << endl;
    } 
} 
void meal(){ //밥을 생산하는 함수
    while (1){ 
        int x = rand() % 38 + 1;
        int y = rand() % 18 + 1;
        if (board[x][y] != 'O'){ //꼬리에서 생기게 할 수는 없으므로 반복문을 써줌.
            board[x][y] = 'M'; 
            gotoxy(x, y); 
            printf("M"); 
            return; 
        } 
    } 
} 

int nanido; 
void update(){ 

    gotoxy(game.pos[game.length-1].x, game.pos[game.length-1].y); 
    printf(" "); 
    for (int i = game.length-1; i >=0; i--){ 
        game.pos[i + 1].x = game.pos[i].x; 
        game.pos[i + 1].y = game.pos[i].y; 
    } 
    if (game.direction == RIGHT) game.pos[0].x++;
    if (game.direction == LEFT) game.pos[0].x--; 
    if (game.direction == UP) game.pos[0].y--; 
    if (game.direction == DOWN) game.pos[0].y++;
    if (board[game.pos[0].x][game.pos[0].y] == '#' || board[game.pos[0].x][game.pos[0].y] == 'O'){ 
        gameover = 1; 
        return; 
    } 
    if (board[game.pos[0].x][game.pos[0].y] == 'M'){ 
        meal(); 
        game.length++; 
    } 
    gotoxy(45, 8); 
    printf("현재 꼬리의 개수 : %d", game.length); 
    gotoxy(45, 9); 
    printf("현재 난이도 : %d", 20-nanido/60);
    board[game.pos[0].x][game.pos[0].y] = 'O'; 
    board[game.pos[game.length-1].x][game.pos[game.length-1].y] = ' '; 

    gotoxy(game.pos[0].x, game.pos[0].y);
    printf("O"); 
} 
int gamestart(){ 
    int nan; 
    do{ 
        cout << "난이도를 선택하십시오. 1~16" << endl; 
        cin >> nan; 
    } while (nan > 16 || nan < 1);
    cout << nan << "난이도로 시작합니다." << endl; 
    Sleep(1000); 
    system("cls"); 
    return 60 * (20 - nan);
} 
int main(){ 
    srand(time(NULL)); 
    setcolor(2, 15); 

    nanido = gamestart();//밀리초 
{ 
    for (int i = 0; i < 40; i++){ 
        board[i][0] = '#'; 
        board[i][19] = '#'; 
    } 
    for (int i = 0; i < 20; i++){ 
        board[0][i] = '#'; 
        board[39][i] = '#'; 
    } 
    printscreen(); 
}//기본 판 출력 
    game.pos[0].x = 20;
    game.pos[0].y = 10;
    game.pos[1].x = 19;
    game.pos[1].y = 10;
    game.pos[2].x = 18;
    game.pos[2].y = 10;
    meal();//초기 밥 생산 
    while (gameover == 0){// update 
        Sleep(nanido); //waiting
        if (_kbhit()){//입력 되었는지? 
            if (_getch() == 224){ 
                game.direction = _getch();//무슨 키를 입력하였는지? 
            } 
        } 
        if (game.length == 100){ //꼬리가 100개 붙었다면,
            cout << "WIN!" << endl; //이긴다!
            return 0; 
        } 
        update(); //화면 업데이트
    } 
    if (gameover == 1){ //게임 끝
        setcolor(15,12); 
        cout << "GAME OVER" << endl; 
    } 
    gotoxy(0, 20); 
    return 0; 
}


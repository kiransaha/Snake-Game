#include <iostream>
#include <conio.h>
#include<cstdlib>
#include<ctime>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
int c=0;
void Setup()
{
    srand(int (time(0)));
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{
    system("cls");
    cout << "\n\n\t\t\t\t*@*@INSTRUCTION TO PLAY GAME@*@*"<<endl;
    cout << "press 'a' to move 'left'\n press 'd' to move 'right' \n press 'w' to move 'up' \n press 's' to move 'down'\n press 'x' to 'exit'\n\n";
 //system("clear");
    for (int i = 0; i < width+2; i++)
        cout << "@";
    cout << endl;

    for (int i = 0; i <= height; i++)
    {
        for (int j = 0; j <=width; j++)
        {
            if (j == 0||j==width)
                cout << "@";
            if (i == y && j == x)
            {
                for(int k=1;k<=score+1;k++)
                {

                    if (x == fruitX && y == fruitY)
                    {
                        score ++;
                        fruitX = rand() % width;
                        fruitY = rand() % height;
                    }

                    cout<<"O";
                }
            }
            else if (i == fruitY && j == fruitX)
                cout << "F";
                else
                    cout << " ";



        }
        cout << endl;
    }

    for (int i = 0; i < width+2; i++)
        cout << "@";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }
    if (x == width || x==0||y==0||y == height)
     {c=1;

      //|| x < 0 || y > height || y < 0)
      gameOver = true;

    }
    //if (x >= width)
    //{gameOver=false;}
     //else if (x < 0)
       // x = width - 1;
    //if (y >= height)
      //  y = 0;
    //else if (y < 0)
    //    y = height - 1;


 //   if (x == fruitX && y == fruitY)
   // {
     //   score += 10;
       // fruitX = rand() % width;
        //fruitY = rand() % height;
        //nTail++;
    //}
}

int main()
{

    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        if(c==1)
        {
            break;
        }
        Sleep(1000);
         //sleep(10);
    }
    cout << "\t\t\t\t\t\t\\GAMEOVER\\"<<endl<<"\t\t\t\t\t\t YOUR SCORE IS " << score<<endl<<endl;


    return 0;
}

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

enum Direction
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};             // snake direction
Direction dir; // direction object
bool gameOver; // game state variable
// snake board draw
const int height = 20;
const int width = 20;
int headX, headY, fruitX, fruitY, score;
int tailx[100], taily[100]; // array
int tail_len;

void setup();
void draw();
void input();
void logic();

int main()
{
    // ask user to start the game
    // board draw
    char start;
    cout << "\t--------------------------" << endl;
    cout << "\t\t :Snake King: " << endl;
    cout << "\t--------------------------" << endl;
    cout << "Press 's' to start:";
    cin >> start;
    if (start == 's')
    {
        setup();
        while (!gameOver)
        {
            // this loop will run until gameover value is true
            // gameOver not true until snake bite itself
            draw();
            input();
            logic();
            Sleep(30); // sleep fun called to slow the loop ,enhance experience
            system("cls");//remove old screen &we can print new one there
            
        }
    }

    return 0;
}
void setup()
{

    gameOver = false; // gameover set to false
    // when user input s then what environment will be shown
    dir = STOP;
    headX = width / 2; // snake will be in centre
    headY = height / 2;
    fruitX = rand() % width; // fruit can be anywhere so random is used
    fruitY = rand() % height;
    score = 0;
}
void draw()
{
    system("cls");
    cout << "\t\t"; // board is drawn after some space
    for (int i = 0; i < width - 8; i++)
    { // to draw upper border ,for is used
        cout << "||";
    }
    cout << endl;
    // snake ,fruit ,side border,space print ke liye for loop
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 2loops are there to draw 2D board ,provides x,y axis
            // left side border
            if (j == 0)
            {
                cout << "\t\t||"; // new line then border printed
            }
            // snake head
            if (i == headY && j == headX)
            {
                cout << "O";
            }
            // fruit
            else if (i == fruitY & j == fruitX)
            {
                cout << "*";
                // fruit &head can't be at same point
            }
            // space,snake tail
            else
            {
                bool print = false; // tail not print
                                    // tail
                for (int k = 0; k < tail_len; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        // in this var tail index stored
                        cout << "o";
                        print = true;
                    }
                }
                // space
                if (!print)
                {
                    cout << " ";
                }
            }
                // right border
                if (j == width - 1)
                {
                    cout << "||"; // new line then border printed
                }
        }
                cout << endl;
            }
            // lower border
        cout << "\t\t"; // board is drawn after some space
        for (int i = 0; i < width - 8; i++)
        {
            cout << "||";
        }
        cout<<endl;
                cout << "\t\t\tScore: " << score << endl;
            }
        
       
    


void input()
{
    if(_kbhit())//keyboard hit ,fun return true value until any value is hitting
    //snake movement control left,right,top,etc
    switch (getch())//character input does by user
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
    
    default:
        break;
    }

}


void logic()
{
    //tail logic
    int prevx=tailx[0];
    int prevy=taily[0];
    int prev2x,prev2y;
    tailx[0]=headX;//bcz snake tail follows head
    taily[0]=headY;
    for(int i=1; i<tail_len;i++){
        //other tail elements have to be moved
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]= prevx;//each element follow its next element
        taily[i]= prevy;
        prevx=prev2x;
        prevy=prev2y;
}
        //direction logic
        switch (dir)
        {
        case LEFT:
            headX--;
            break;
            case RIGHT:
            headX++;
            break;
            case UP:
            headY--;
            break;
            case DOWN:
            headY++;
            break;
        
        default:
            break;
        }
        //touch walls
        if(headX >=width){
            headX=0;//snake will come from next side wall
        }
        else if(headX<0)
        {
           headX = width-1;
        }
         if(headY >=height){
            headY=0;//snake will come from next side wall
        }
        else if(headY<0)
        {
           headY = height-1;
        }
      // snake bite itself
      for(int i=0; i<tail_len;i++)
      {
        if(tailx[i]==headX && taily[i]==headY)
        {
            gameOver=true;
        }
      }
      //snake eat fruit
      if(headX==fruitX)
      {
        score+=10;
        fruitX= rand()%width;//new fruit generated
        fruitY= rand()%height;
        tail_len++;//tail len increases
      }
}

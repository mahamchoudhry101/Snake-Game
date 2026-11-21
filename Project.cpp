#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    exitFlag = false;
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
     int maxX = 30;
    int maxY = 15;

    // Create test objPos using  class
    objPos p1(5, 5, 'A');
    objPos p2(10, 7, 'B');
    objPos p3(20, 10, 'C');

    // Loop through rows and columns
    for (int y = 0; y < maxY; y++)
    {
        for (int x = 0; x < maxX; x++)
        {
            // BORDER
            if (y == 0 || y == maxY - 1 || x == 0 || x == maxX - 1)
            {
                MacUILib_printf("#");
            }
            // PRINT objPos p1
            else if (x == p1.pos->x && y == p1.pos->y)
            {
                MacUILib_printf("%c", p1.symbol);
            }
            // PRINT objPos p2
            else if (x == p2.pos->x && y == p2.pos->y)
            {
                MacUILib_printf("%c", p2.symbol);
            }
            // PRINT objPos p3
            else if (x == p3.pos->x && y == p3.pos->y)
            {
                MacUILib_printf("%c", p3.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");   // go to next row
    }

    MacUILib_printf("Iteration 0 — objPos Test\n");    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}

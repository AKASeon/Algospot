#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

char    gArray[4][8] = { "##.##..",
                         "#......",
                         "#....##",
                         "#..####" };

int     gMaxX = 4;
int     gMaxY = 7;

char    gBlock1[2][4] = { "###",
                          "#.." };

char    gBlock2[2][4] = { "#..",
                          "###" };

char    gBlock3[2][4] = { "###",
                          "..#" };

char    gBlock4[2][4] = { "..#",
                          "###" };

int     gBlockMaxX = 2;
int     gBlockMaxY = 3;

int     gMaxCount = 0;

void doNextStep( int x, int y, int stop )
{
}

int cmpArrayAndBlock( int  aX,
                      int  aY,
                      char aBlock[2][4],
                      int  aBlockMaxX )
{
    int     i = 0;

    for ( i = 0; i < aBlockMaxX; i++ )
    {
        printf("%s\n", &gArray[aX][aY] );
        printf("%s\n", aBlock[i] );
        if ( strcmp( &gArray[aX][aY], aBlock[i] ) != 0 )
        {
        printf("FALSE\n");
            return FALSE;
        }
    }

    return TRUE;
}
                        
int checkAndFillArray( int  aX, 
                       int  aY, 
                       char aBlock[2][4],
                       int  aBlockMaxX,
                       int  aBlockMaxY )
{
    if ( cmpArrayAndBlock( aX,
                           aY,
                           aBlock,
                           aBlockMaxX )
         == TRUE )
    {

    }
    else
    {
        printf("FALSE\n");
    }

    return 0;
}

void processArray( int  aX, 
                   int  aY, 
                   char aBlock[2][4],
                   int  aBlockMaxX,
                   int  aBlockMaxY )
{
    checkAndFillArray( aX,
                       aY,
                       aBlock,
                       aBlockMaxX,
                       aBlockMaxY );
}

void process( int x, int y, int stop )
{
    processArray( x, 
                  y, 
                  gBlock1,
                  gBlockMaxX,
                  gBlockMaxY );

    processArray( x, 
                  y, 
                  gBlock2,
                  gBlockMaxX,
                  gBlockMaxY );

    processArray( x, 
                  y, 
                  gBlock3,
                  gBlockMaxX,
                  gBlockMaxY );

    processArray( x, 
                  y, 
                  gBlock4,
                  gBlockMaxX,
                  gBlockMaxY );


    doNextStep( x, y, stop );
}

int main( void )
{
    process( 0, 0, FALSE );

    return 0;
}

#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

//char    gArray[4][8] = { "##.##..",
//                         "#......",
//                         "#....##",
//                         "#..####" };
//
//int     gMaxX = 4;
//int     gMaxY = 7;
//
//char    gBlock1[2][4] = { "###",
//                          "#.." };
//
//char    gBlock2[2][4] = { "#..",
//                          "###" };
//
//char    gBlock3[2][4] = { "###",
//                          "..#" };
//
//char    gBlock4[2][4] = { "..#",
//                          "###" };
//
//int     gBlockMaxX = 2;
//int     gBlockMaxY = 3;

char    gArray[5][11] = { "..........",
                          "..........",
                          "..........",
                          "..........",
                          ".........." };

int     gMaxX = 5;
int     gMaxY = 10;

int     gTotalArrayBlockCount = 5 * 10;
int     gFillArrayBlockCount = 0;

/* original */
char    gBlock1[3][4] = { ".#.",
                          "###",
                          "..#" };

char    gBlock2[3][4] = { ".#.",
                          ".##",
                          "##." };

char    gBlock3[3][4] = { "#..",
                          "###",
                          ".#." };

char    gBlock4[3][4] = { ".##",
                          "##.",
                          ".#." };

int     gBlockMaxX = 3;
int     gBlockMaxY = 3;

int     gTotalBlockCount = 5;

int     gTempMaxCount = 0;
int     gMaxCount = 0;

void printArray( void )
{
    for ( int i = 0; i < gMaxX; i++ )
    {
        for ( int j = 0; j < gMaxY; j++ )
        {
            printf("%c", gArray[i][j] );
        }
        printf("\n");
    }
    printf("\n\n" );
}
void printBlock( char aBlock[3][4],
                 int  aBlockMaxX,
                 int  aBlockMaxY )
{
    int i = 0;

    printf( "%d %d\n", aBlockMaxX, aBlockMaxY );
    for ( i = 0; i < aBlockMaxX; i++ )
    {
        printf("%s\n", aBlock[i] );
    }
}

void process( int x, int y );

char    gTestBlock[3][4] = { ".#.",
                             "###",
                             "..#" };
char    gTestResultBlock[3][4] = { "...",
                                    "...",
                                    "..." };
int     gTestMaxX = 3;
int     gTestMaxY = 3;

void rotateBlock( char aTestBlock[3][4] )
{
    int x = 0;
    int y = 0;

    for ( x = 0; x < gTestMaxX; x++ )
    {
        for ( y = 0; y < gTestMaxY; y++ )
        {
            gTestResultBlock[y][gTestMaxX-x-1] = aTestBlock[x][y];
        }
    }
}
void rotateBlockTest( void )
{
    printBlock( gTestBlock,
                gTestMaxX,
                gTestMaxY );

    rotateBlock( gTestBlock );

    printBlock( gTestResultBlock,
                gTestMaxX,
                gTestMaxY );

    memcpy( gTestBlock, gTestResultBlock, 3*4 );

    rotateBlock( gTestBlock );

    printBlock( gTestResultBlock,
                gTestMaxX,
                gTestMaxY );

    memcpy( gTestBlock, gTestResultBlock, 3*4 );

    rotateBlock( gTestBlock );

    printBlock( gTestResultBlock,
                gTestMaxX,
                gTestMaxY );

    memcpy( gTestBlock, gTestResultBlock, 3*4 );

    rotateBlock( gTestBlock );

    printBlock( gTestResultBlock,
                gTestMaxX,
                gTestMaxY );

}

void setMaxCount( int aTempMaxCount )
{
    if ( gMaxCount < aTempMaxCount )
    {
        //printf("%d\n", aTempMaxCount );
        //printArray();
        gMaxCount = aTempMaxCount;
    }
    else
    {
        /* do nothing */
    }
}

void doNextStep( int x, int y )
{
    y++;

    if ( ( x == gMaxX-1 ) && 
         ( y == gMaxY-1 ) )
    {
        setMaxCount( gTempMaxCount );
        return;
    }

    /* 
     * 더이상 옆으로 이동을 못한다.
     * block 의 가로 길이가 남은길이보다 크다 
     */
    if ( ( gMaxY-1 == y ) ||
         ( gBlockMaxY > gMaxY-y ) )
    {
        x++;
        y = 0;
    }

    ///* block의 세로길이가 남은 길이보다 크다 */
    if ( gBlockMaxX > gMaxX - x )
    {
        setMaxCount( gTempMaxCount );
        return;
    }

    process( x, y );
}

int fitBlockFromArray( int  aX,
                       int  aY,
                       char aBlock[3][4] )
{
    int     i = 0;
    int     j = 0;
    int     sRC = TRUE;

    for ( i = 0; i < gBlockMaxX; i++ )
    {
        for ( j = 0; j < gBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                if ( gArray[aX+i][aY+j] == '.' )
                {
                    /* do nothing */
                }
                else
                {
                    /* do not fit */
                    sRC = FALSE;
                    break;
                }
            }
            else
            {
                /* do nothing */
            }
        }
    }

    return sRC;
}

void fillArrayFromBlock( int  aX,
                         int  aY,
                         char aBlock[3][4] )
{
    int i = 0;
    int j = 0;

    for ( i = 0; i < gBlockMaxX; i++ )
    {
        for ( j = 0; j < gBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                gArray[aX+i][aY+j] = '#';
            }
            else
            {
                /* do nothing */
            }
        }
    }
}

void recoverArrayFromBlock( int  aX,
                            int  aY,
                            char aBlock[3][4])
{
    int i = 0;
    int j = 0;

    for ( i = 0; i < gBlockMaxX; i++ )
    {
        for ( j = 0; j < gBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                gArray[aX+i][aY+j] = '.';
            }
            else
            {
                /* do nothing */
            }
        }
    }
}
                        
void processArray( int  aX, 
                   int  aY,
                   char aBlock[3][4] )
{
    if ( fitBlockFromArray( aX,
                            aY,
                            aBlock )
         == TRUE )
    {
        gTempMaxCount++;

        fillArrayFromBlock( aX, aY, aBlock );

        doNextStep( aX, aY );

        recoverArrayFromBlock( aX, aY, aBlock );

        gTempMaxCount--;
    }
}

void process( int x, int y )
{
    processArray( x, 
                  y, 
                  gBlock1 );

    processArray( x, 
                  y, 
                  gBlock2 );

    processArray( x, 
                  y, 
                  gBlock3 );

    processArray( x, 
                  y, 
                  gBlock4 );

    doNextStep( x, y );
}

int main( void )
{
    gMaxCount = 0;
    gTempMaxCount = 0;

    process( 0, 0 );

    printf( "%d\n", gMaxCount );

    rotateBlockTest();

    return 0;
}

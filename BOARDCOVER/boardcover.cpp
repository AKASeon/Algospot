#include <stdio.h>

#define TRUE    1
#define FALSE   0

//char    gArray[3][8] = { "#.....#",
//                         "#.....#",
//                         "##..###" };
//
//int gMaxX = 3;
//int gMaxY = 7;
//char      gArray[8][11] = { "##########",
//                            "#........#", 
//                            "#........#", 
//                            "#........#", 
//                            "#........#", 
//                            "#........#", 
//                            "#........#", 
//                            "##########"};
//int gMaxX = 8;
//int gMaxY = 10;
char gArray[3][8] = { "#.....#",
                      "#.....#", 
                      "##...##"};
int gMaxX = 3;
int gMaxY = 7;
int gCount = 0;

int gFillCount = 0;

void process( int x, int y, int stop );

int checkFillCount()
{
    int count = 0;

    for ( int i = 0; i < gMaxX; i++ )
    {
        for ( int j = 0; j < gMaxY; j++ )
        {
            if ( gArray[i][j] == '#' )
                count++;
        }
    }

    return count;
}

int checkFillArray( int x )
{
    int sRC = TRUE;

    for ( int i = 0; i < gMaxY; i++ )
    {
        if ( gArray[x][i] != '#' )
        {
            sRC = FALSE;
            break;
        }
    }

    return sRC;
}

void doNextStep( int x, int y, int stop )
{
    int sProcess = TRUE;

    y++;
    if ( gMaxY-1 == y )
    {
        sProcess = checkFillArray( x );

        if ( stop == TRUE )
        {
            sProcess = FALSE;
        }

        x++;
        y = 0;
    }

    if ( gMaxX-1 == x )
    {
        sProcess = FALSE;
    }

    if ( sProcess == TRUE )
    {
        process( x, y, FALSE );
    }
}

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

int checkAndFillArray( int x1, int y1,
                       int x2, int y2,
                       int x3, int y3 )
{
    int sRC = FALSE;
    int count = 0;

    if ( ( gArray[x1][y1] == '.' ) && 
         ( gArray[x2][y2] == '.' ) &&
         ( gArray[x3][y3] == '.' ) ) 
    {
        gArray[x1][y1] = '#';
        gArray[x2][y2] = '#';
        gArray[x3][y3] = '#';

        sRC = TRUE;

        //printArray();
        count = checkFillCount();
        if ( count == gMaxX * (gMaxY) )
        {
            gCount++;
            //printf(" %d\n", count );
        }
    }
    else
    {
        sRC = FALSE;
    }

    return sRC;
}

void recoveryArray( int x1, int y1,
                    int x2, int y2,
                    int x3, int y3 )
{
    gArray[x1][y1] = '.';
    gArray[x2][y2] = '.';
    gArray[x3][y3] = '.';
}

void processArray( int x1, int y1,
                   int x2, int y2,
                   int x3, int y3 )
{
    if ( checkAndFillArray( x1, y1,
                            x2, y2,
                            x3, y3 ) == TRUE )
    {
        doNextStep( x1, y1, FALSE );

        recoveryArray( x1, y1,
                       x2, y2,
                       x3, y3 );
        //printArray();
    }
}

void process( int x, int y, int stop )
{
    /* .
     * .. 
     */
    processArray( x,    y,
                  x+1,  y,
                  x+1,  y+1 );

    /*  .
     * .. 
     */
    processArray( x,    y,
                  x+1,  y,
                  x+1,  y-1 );

    /* ..
     * . 
     */
    processArray( x,    y,
                  x,    y+1,
                  x+1,  y );

    /* ..
     *  .
     */
    processArray( x,    y,
                  x,    y+1,
                  x+1,  y+1 );

    doNextStep( x, y, stop );
}

int main( void )
{
    printArray();

    process( 0, 0, TRUE );

    printf("%d\n", gCount );

    return 0;
}

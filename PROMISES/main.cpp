//
//  main.cpp
//  PROMISES
//
//  Created by DooSeon Choi on 2015. 3. 29..
//  Copyright (c) 2015년 DooSeon Choi. All rights reserved.
//

#include <iostream>

#define INIT_VALUE  ( INT_MAX )
#define MAX_CITY    ( 200 )

int gRoad[MAX_CITY][MAX_CITY];
int gWrongBuild;
int gColumnMaxCount;
int gRowMaxCount;

void promises( void );

int main(int argc, const char * argv[])
{
    promises();

    return 0;
}

void initRoad( void )
{
    unsigned int i = 0;
    unsigned int j = 0;
    
    for ( i = 0; i < MAX_CITY; i++ )
    {
        for ( j = 0; j < MAX_CITY; j++ )
        {
            gRoad[i][j] = INIT_VALUE;
        }
    }
    
    gWrongBuild = 0;
}

void updateViaRoadInfo( int aRowIndex,
                        int aColumnIndex )
{
    int i = 0;
    int sTempValue = 0;
    int sColumnIndex = 0;
    int sRowIndex = 0;
    
    for ( i = aRowIndex + 1; i < gColumnMaxCount; i++ )
    {
        if ( gRoad[aRowIndex][i] != INT_MAX )
        {
            sTempValue = gRoad[aRowIndex][i] + gRoad[aRowIndex][aColumnIndex];
        
            if ( aColumnIndex > i )
            {
                sColumnIndex = aColumnIndex;
                sRowIndex = i;
            }
            else
            {
                sColumnIndex = i;
                sRowIndex = aColumnIndex;
            }
            
            if ( gRoad[sRowIndex][sColumnIndex] > sTempValue )
            {
                gRoad[sRowIndex][sColumnIndex] = sTempValue;
            }
            else
            {
                /* do nothing */
            }
        }
        else
        {
            /* do nothing */
        }
    }
    
}

void updateRoadInfo( int aRowIndex,
                     int aColumnIndex,
                     int aWeight )
{
    bool    sShouldUpdate = true;
 
    gRoad[aRowIndex][aColumnIndex] = aWeight;
    /*
    if ( gRoad[aRowIndex][aColumnIndex] > aWeight )
    {
        gWrongBuild++;
        sShouldUpdate = false;
    }
    else
    {
        gRoad[aRowIndex][aColumnIndex] = aWeight;
        sShouldUpdate = true;
    }
     */
    
    if ( sShouldUpdate == true )
    {
        updateViaRoadInfo( aRowIndex,
                           aColumnIndex );
    }
    else
    {
        /* do nothing */
    }
}

void inputRoadInfo( int aIndex1,
                    int aIndex2,
                    int aWeight )
{
    int sIndex1 = 0;
    int sIndex2 = 0;
    int sWeight = 0;
    
    //scanf("%d %d %d", &sIndex1, &sIndex2, &sWeight );
    
    sIndex1 = aIndex1;
    sIndex2 = aIndex2;
    sWeight = aWeight;
    
    if ( sIndex1 > sIndex2 )
    {
        updateRoadInfo( sIndex2, sIndex1, sWeight );
    }
    else
    {
        updateRoadInfo( sIndex1, sIndex2, sWeight );
    }
}

void printRoadInfo( void )
{
    int sRowIndex = 0;
    int sColumnIndex = 0;
    
    for ( sRowIndex = 0; sRowIndex < gRowMaxCount; sRowIndex++ )
    {
        for ( sColumnIndex = 0; sColumnIndex < gColumnMaxCount; sColumnIndex++ )
        {
            if ( gRoad[sRowIndex][sColumnIndex] == INT_MAX )
            {
                printf("%4d", 0 );
            }
            else
            {
                printf("%4d ", gRoad[sRowIndex][sColumnIndex] );
            }
        }
        printf("\n");
    }
}

void promises( void )
{
    gRowMaxCount = 4;
    gColumnMaxCount = 4;
    
    initRoad();
    
    inputRoadInfo( 0, 1, 2 );
    inputRoadInfo( 0, 3, 2 );
    inputRoadInfo( 2, 0, 1 );
    inputRoadInfo( 3, 1, 1 );
    inputRoadInfo( 3, 2, 1 );
    
    printRoadInfo();
}


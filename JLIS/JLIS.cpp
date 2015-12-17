#include <stdio.h>

typedef struct jlisNodeType
{
    int mValue;
    int mJlis;
} jlisNodeType;

jlisNodeType gList1[100];
jlisNodeType gList2[100];

int printList( jlisNodeType * aList,
               int            aListCount )
{
    int sIndex = 0;

    for ( sIndex = 0; sIndex < aListCount; sIndex++ )
    {
        printf( "Index : %d Value : %d JLIS : %d\n", 
                sIndex, aList[sIndex].mValue, aList[sIndex].mJlis );
    }

    return 0;
}
int calculateJoinedLength( jlisNodeType   * aList,
                           int              aListCount )
{
    int sIndex = 0;

    sIndex = aListCount - 1;

    /* last one */
    aList[sIndex].mJlis = 1;
    sIndex--;
    
    while ( sIndex >= 0 )
    {
        if ( aList[sIndex].mValue < aList[sIndex+1].mValue )
        {
            aList[sIndex].mJlis = aList[sIndex+1].mJlis + 1;
        }
        else if ( aList[sIndex].mValue == aList[sIndex].mValue )
        {
            aList[sIndex].mJlis = aList[sIndex+1].mJlis;
        }
        else
        {
            aList[sIndex].mJlis = 1;
        }
        sIndex--;
    }
}

int getJLIS( jlisNodeType * aNode
             jlisNodeType * aList,
             int            aListCount )
{
    int sMaxJLIS = 0;

    sMaxJLIS = aNode->mJLIS;
    for ( sIndex = 0; sIndex < aListCount; sIndex++ )
    {
        if ( aNode->mValue <= aList[sIndex].mValue )
        {

        }
        else
        {
        }
    }
}

int solve( jlisNodeType * aList1,
           int            aList1Count,
           jlisNodeType * aList2,
           int            aList2Count )
{
    int sCount = 0;
    int sIndex = 0;

    calculateJoinedLength( aList1, aList1Count );
    calculateJoinedLength( aList2, aList2Count );

    printList( aList1, aList1Count );
    printList( aList2, aList2Count );

    for ( sIndex = aList1Count - 1;
          sIndex >= 0;
          sIndex-- )
    {
    }

    return sCount;
}

int main( void )
{
    jlisNodeType sList1[100];
    jlisNodeType sList2[100];

    sList1[0].mValue = 1;
    sList1[1].mValue = 2;
    sList1[2].mValue = 3;
    sList1[3].mValue = 4;
    sList1[4].mValue = 5;
    sList1[5].mValue = 6;

    solve( sList1, 6,
           sList2, 6 );

    return 0;
}

#include <stdio.h>
#include <limits> 
#include <algorithm>  

const long long NEGINF = std::numeric_limits<long long>::min();

int n, m, A[100], B[100];
int cache[101][101];

int jlis(int indexA, int indexB)
{
    int &ret = cache[indexA+1][indexB+1];

    if ( ret != 0 )
    {
        return ret;
    }

    ret = 2;

    long long a = (indexA == -1 ? NEGINF : A[indexA] );
    long long b = (indexB == -1 ? NEGINF : B[indexB] );
    long long maxElement = std::max(a, b );

    for ( int nextA = indexA+1; nextA < n; ++nextA )
        if ( maxElement < A[nextA] )
            ret = std::max( ret, jlis(nextA, indexB) + 1 );

    for ( int nextB = indexB+1; nextB < m; ++nextB )
        if ( maxElement < B[nextB] )
            ret = std::max( ret, jlis(indexA, nextB) + 1 );

    return ret;
}

int main( void )
{
    int sCount = 0;
    int i = 0;
    int j = 0;

    scanf( "%d", &sCount );

    for ( i = 0; i < sCount; i++ )
    {
        memset( cache, 0x00, sizeof(cache) );
        scanf( "%d %d", &n, &m );

        /* list 1 */
        for ( j = 0; j < n; j++ )
        {
            scanf( "%d ", &A[j] );
        }
        
        /* list 2 */
        for ( j = 0; j < m; j++ )
        {
            scanf( "%d ", &B[j] );
        }
        
        printf( "%d\n", jlis( -1, -1 ) );
    }

    return 0;
}


""" 
First data is root in PreOrder
InOrder data can be divided by first data in PreOrder.
left data list is left Tree
right data list is right tree
"""
def solve ( aPreOrder, aInOrder ) :

    sList = []
    sKey = aPreOrder[0]
    sKeyIndex = aInOrder.index( sKey )
    del aPreOrder[0];

    sLeftTreeList = aInOrder[:sKeyIndex]
    sRightTreeList = aInOrder[sKeyIndex+1:]

    if ( len( sLeftTreeList ) != 0 ) :
        sList.extend( solve( aPreOrder, sLeftTreeList ) )

    if ( len( sRightTreeList ) != 0 ):
        sList.extend( solve( aPreOrder, sRightTreeList ) )
    """
    print sKey, sKeyIndex
    print "sLeftTreeList : ",  sLeftTreeList
    print "sRightTreeList : ",  sRightTreeList 
    """
    sList.append( sKey )

    return sList

#sPreOrder = [ '27', '16', '9', '12', '54', '36', '72' ]
#sInOrder = [ '9', '12', '16', '27', '36', '54', '72' ]

def main() :
    sCount = input()

    for i in range( sCount ) :
        sListLength = input() 
        sPreOrder = raw_input().split()
        sInOrder = raw_input().split()
        
        print ' '.join( str(sItem) for sItem in solve( sPreOrder, sInOrder ) )

main()

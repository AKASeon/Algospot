
def josephus ( aCount, aJumpNumber ) :

    sList = []

    sSequenceNumber = 0;

    for sIndex in xrange( 2, aCount + 1 ) :
        sSequenceNumber = sSequenceNumber + 1

        if sSequenceNumber is not aJumpNumber :
            sList.append( sIndex )
        else :
            sSequenceNumber = 0;

    while len( sList ) >  2 :

        for sNode in sList[:] :
            sSequenceNumber = sSequenceNumber + 1
            #print sNode

            if sSequenceNumber == aJumpNumber :
                #print "Remote : ", sNode
                sList.remove( sNode ) 
                sSequenceNumber = 0

            if len( sList ) == 2 :
                break;

    print sList[0], sList[1]
    #for sNode in sList :
    #    print "Reulst : ", sNode


def main() :
    sCount = input()

    for i in range( sCount ) :

        sInput = raw_input()
        sInput_list = sInput.split()

        josephus( int( sInput_list[0] ), 
                  int( sInput_list[1] ) )

main()

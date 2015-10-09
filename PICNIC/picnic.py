
def makeFriends( aTarget, aFriendList ) :
    
    sCouple = ( aTarget, aFriendList )

    return sCouple

def solve( aStartNumber, aEndNumber, aConditionaList, aAlreadyPickUp ) :

    #print 'Enter Func ', len(aAlreadyPickUp), aEndNumber

    sCount = 0;

    if aStartNumber in aAlreadyPickUp :
        sCount += solve( aStartNumber + 1, aEndNumber, aConditionaList, aAlreadyPickUp )
    else :

        sMe = aStartNumber
        sWantedFriendList = aConditionaList[aStartNumber]

        #print 'Me ', sMe, 'AlReady ', aAlreadyPickUp

        if type( sWantedFriendList ) is list :
            
            aAlreadyPickUp.append( sMe )

            for sFriend in sWantedFriendList :

                if sFriend in aAlreadyPickUp :
                    continue 
                else :
                    aAlreadyPickUp.append( sFriend )

                    if len(aAlreadyPickUp) is aEndNumber + 1:
                        aAlreadyPickUp.remove( sFriend )
                        aAlreadyPickUp.remove( sMe )
                        return 1
                    else :
                        sCount += solve( aStartNumber + 1, aEndNumber, aConditionaList, aAlreadyPickUp )
                        aAlreadyPickUp.remove( sFriend )


            aAlreadyPickUp.remove( sMe )

    return sCount

def picnic() :
    sCount = input()

    for i in range( sCount ) :

        sFriendCount = 0

        sInput = raw_input()
        sInput_list = sInput.split()

        if sInput_list[1] is not '0' :

            sFriendList = [0] * int( sInput_list[0] )

            sInput2 = raw_input()
            sInput2_list = sInput2.split()

            for j in range( 0, len( sInput2_list ), 2 ) :
                sFriend1 = int( sInput2_list[j] )
                sFriend2 = int( sInput2_list[j+1] )

                if ( sFriend1 < sFriend2 ) :
                    if type( sFriendList[ sFriend1 ] ) is list :
                        sFriendList[ sFriend1 ].append( sFriend2 )
                    else :
                        sFriends = []
                        sFriends.append( sFriend2 )
                        sFriendList[ sFriend1 ] = sFriends
                else :
                    if type( sFriendList[ sFriend2 ] ) is list :
                        sFriendList[ sFriend2 ].append( sFriend1 )
                    else :
                        sFriends = []
                        sFriends.append( sFriend1 )
                        sFriendList[ sFriend2 ] = sFriends

            #print sFriendList 
            sFriendCount = solve( 0, int( sInput_list[0] ) - 1, sFriendList, [] )
        else :
            sFriendCount = 0

        print sFriendCount

picnic()

#sStart = 0
#sEnd = 5 
#
#sFriendList = [0] * ( sEnd + 1 )
#
#sFriends = []
#sFriends.append( 1 )
#sFriends.append( 2 )
#
#sFriendList[0] = sFriends 
#
#sFriends = []
#sFriends.append( 2 )
#sFriends.append( 3 )
#sFriends.append( 4 )
#sFriendList[1] = sFriends
#
#sFriends = []
#sFriends.append( 3 )
#sFriends.append( 4 )
#sFriendList[2] = sFriends
#
#sFriends = []
#sFriends.append( 4 )
#sFriends.append( 5 )
#sFriendList[3] = sFriends
#
#sFriends = []
#sFriends.append( 5 )
#sFriendList[4]= sFriends

#print solve( sStart, sEnd, sFriendList, [] )

#print sFriends
#print sCouple
#print sFriendList

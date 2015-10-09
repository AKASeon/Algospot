
def makeFriends( aTarget, aFriendList ) :
    
    sCouple = ( aTarget, aFriendList )

    return sCouple

def solve( aStartNumber, aEndNumber, aConditionaList, aAlreadyPickUp ) :

    #print 'Enter Func ', len(aAlreadyPickUp), aEndNumber

    sCount = 0;

    if aStartNumber in aAlreadyPickUp :
        sCount += solve( aStartNumber + 1, aEndNumber, aConditionaList, aAlreadyPickUp )
    else :

        sMe, sWantedFriendList = aConditionaList[aStartNumber]

        #print 'Me ', sMe, 'AlReady ', aAlreadyPickUp

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



sFriendList = []

sFriends = []
sFriends.append( 1 )
sFriends.append( 2 )

sCouple = makeFriends( 0, sFriends )
sFriendList.append( sCouple )

sFriends = []
sFriends.append( 2 )
sFriends.append( 3 )
sFriends.append( 4 )
sCouple = makeFriends( 1, sFriends )
sFriendList.append( sCouple )

sFriends = []
sFriends.append( 3 )
sFriends.append( 4 )
sCouple = makeFriends( 2, sFriends )
sFriendList.append( sCouple )

sFriends = []
sFriends.append( 4 )
sFriends.append( 5 )
sCouple = makeFriends( 3, sFriends )
sFriendList.append( sCouple )

sFriends = []
sFriends.append( 5 )
sCouple = makeFriends( 4, sFriends )
sFriendList.append( sCouple )

sStart = 0
sEnd = 5 
print solve( sStart, sEnd, sFriendList, [] )

#print sFriends
#print sCouple
#print sFriendList

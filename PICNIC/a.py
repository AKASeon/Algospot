

def input( aCount , aList ) :

    sInput = raw_input()
    sInput_list = sInput.split()

    print type( sInput_list )

    if type( sInput_list ) is not list :
        for i in range( aCount ) :
            aList[i] = i
            print type( aList[i] )
    else :
        print 'Fuck'


sEnd = 4
sFriendList = [0] * ( sEnd + 1 )

print sFriendList
input( 4, sFriendList )
print sFriendList

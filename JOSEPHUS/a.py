
sList = []

sList.append(1)
sList.append(2)
sList.append(3)
sList.append(4)
sList.append(5)
sList.append(6)

for sIndex in sList :
    print 'List : ', sIndex
    if sIndex is 2 :
        print 'remove : ', 2
        sList.remove( 2 )

print type( sList )
print sList


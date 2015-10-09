import random

class randomwalik_iter :
    def __init__( self ):
        self.last = 1
        self.rand = random.random()

    def __iter__( self ):
        return self

    def next( self ):
        if self.rand < 0.1:
            raise StopIteration
        else :
            while abs( self.last - self.rand ) < 0.5 :
                print '*'
                self.rand = random.random()

            self.last = self.rand
            
            return self.rand 


for num in randomwalik_iter():
    print num,


class Player:
    def __init__(self):
        print("Player created")
        self.vec = Vec2f(0.0, 0.0)

    def _draw(self, renderer):
        print("Player drawn")
    
    def _update(self, deltaTime):
        self.vec.x += deltaTime
        #print(self.vec.x)

def _create():
    return Player()
import Vector2
class Player:
    def __init__(self):
        print("Player created")
        position = Vector2.Vec2f(0, 0)
        print(position.x)
        self.x = 1

    def _draw(self, renderer):
        print("Player drawn")
    
    def _update(self, deltaTime):
        self.x += deltaTime

def _create():
    return Player()
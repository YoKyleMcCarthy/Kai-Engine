class Enemy:
    def __init__(self):
        print("Enemy created")
        self.x = 1

    def _draw(self, renderer):
        print("Enemy drawn")
    
    def _update(self, deltaTime):
        self.x += deltaTime
        #print(self.x)

def _create():
    return Enemy()
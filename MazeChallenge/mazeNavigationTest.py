from Myro import *
init ("COM4")
setIRPower(124) #initalize infrared sensor

moveBy(0,-115)
x = 0
obstacle = getObstacle()
while x < 100:
    x += 1
    if(obstacle == 0):
        moveBy(0, 390)
    else:
        turnBy(90)
        if (obstacle >0):
            turnBy (180)

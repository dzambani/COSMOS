from Myro import *
init ("COM4")
setIRPower(125) #initialize infrared sensor

pic = takePicture()
show(pic)
green = 0
blue = 0
for i in range(212, 215):
    for j in range (131, 136):
        pixel = getPixel(pic, i , j)
        r, g, b = getRGB(pixel) #get rgb values from pixel range
        green += g
        blue += b
green = green / 16 #average the g and b values
blue = blue / 16
print (r, g, b)
if (green > blue): #compare the g and b of the picture, yellow always had more green than blue, pink always has more blue than green
    print ("yellow") #move left or right based on picture
    turnBy(90)
else:
    print ("Pink")
    turnBy(-90)

forward(1,1) #navigate the maze
while True:
    if getObstacle(1) > 0: #check for obstacle after moving
        turnBy(90)
        forward(1,0.5)
        if getObstacle(1) > 0:
            turnBy(180)
            forward(1,1)
    else:
        forward(1, 0.25)

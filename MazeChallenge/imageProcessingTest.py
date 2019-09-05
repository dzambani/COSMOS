from Myro import *
init ("COM5")
setIRPower(200) #initialize infrared sensor

pic = takePicture()
show(pic)
total = 0
#test dimensions of picture to estimate colors in picture
w = getWidth(pic)
h = getHeight(pic)
print (w)
print (h)

from hashlib import new
import math
import cv2 as cv
import numpy as np
from math import cos, pi
from calculos import iDCT, DCT

img_name = '../img/img_01.png'
img = cv.imread(img_name)

newImg = np.zeros(img.shape)
img = cv.cvtColor(np.float32(img), cv.COLOR_BGR2GRAY)
img1 = DCT(img)
img2 = iDCT(img1)
# img1 = cv.dct(img)
# img2 = cv.idct(img1)

cv.imwrite('original_1.png', img)
cv.imwrite('dct_1.png', img1)
cv.imwrite('idct_1.png', img2)
# cv.waitKey(0)

# cv.imwrite('saida_01.png', img)

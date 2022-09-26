import cv2 as cv
import numpy as np
from math import cos, pi, sqrt

def cosDCT(x, i, N):
    return cos( ( (2.0*x+1)*i*pi) / (2*N) )

def alfa(x, a1, a2):
    return a1 if x==0 else a2


def DCT(image: cv.Mat):
    h, w = image.shape
    n = w
    if n>h: h = w
    newImg = np.zeros(image.shape)
    alfa1 = 1.0/sqrt(n)
    alfa2 = sqrt(2.0/n)
    
    cossenos = [[0 for col in range(n)] for row in range(n)]
    for i in range(w):
        for j in range(h):
            cossenos[i][j] = cosDCT(i, j, n)
    
    for i in range(w):
        for j in range(h):
            soma = 0

            for x in range(w):
                for y in range(h):
                    soma += image[x][y] * cossenos[x][i] * cossenos[y][j]

            aux = alfa(i, alfa1, alfa2) * alfa(j, alfa1, alfa2) * soma
            newImg[i][j] = aux
    
    return newImg


def iDCT(image: cv.Mat):
    h, w = image.shape
    n = w
    if n>h: h = w
    newImg = np.zeros(image.shape)
    alfa1 = 1.0/sqrt(n)
    alfa2 = sqrt(2.0/n)
    
    for i in range(w):
        for j in range(h):
            soma = 0

            for x in range(w):
                aux = cosDCT(i,x,n)
                alfai = alfa(x, alfa1, alfa2)
                for y in range(h):
                    soma += alfai * alfa(y,alfa1,alfa2) * image[x][y] * aux * cosDCT(j,y,n)

            newImg[i][j] = soma
    
    return newImg

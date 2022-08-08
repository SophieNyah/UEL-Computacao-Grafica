import cv2
import numpy

def normalize_cmy(cyan, magenta, yellow):
    K = min(cyan, magenta, yellow)
    if K < 1:
        c = (1 - cyan)    / (1 - K)
        m = (1 - magenta) / (1 - K)
        y = (1 - yellow)  / (1 - K)
    else:
        c = 0
        m = 0
        y = 0
    return (c, m, y, K)

def rgb_to_cmyk(imagem: cv2.Mat):
    (height, width, _) = imagem.shape
    cyan_image = numpy.zeros((height, width, 1), numpy.uint8)
    mag_image = numpy.zeros((height, width, 1), numpy.uint8)
    yel_image = numpy.zeros((height, width, 1), numpy.uint8)
    black_image = numpy.zeros((height, width, 1), numpy.uint8)
    for y in range(0, height):
        for x in range(0, width):
            normPixel = imagem[y][x]/255
            (r, g, b) = normPixel
            cyan = 1 - r
            mag  = 1 - g
            yel  = 1 - b
            (C, M, Y, K) = normalize_cmy(cyan, mag, yel)
            cyan_image[y][x]  = C * 255
            mag_image[y][x]   = M * 255
            yel_image[y][x]   = Y * 255
            black_image[y][x] = K * 255
    return (cyan_image, mag_image, yel_image, black_image)

morango = cv2.imread('morango.jpg')
(c_img, m_img, y_img, k_img) = rgb_to_cmyk(morango)
#cv2.imshow('moranguinhos hmmmmm', img)

cv2.imshow('ciano', c_img)
cv2.imshow('magenta', m_img)
cv2.imshow('amarelo', y_img)
cv2.imshow('preto', k_img)
cv2.waitKey(0)
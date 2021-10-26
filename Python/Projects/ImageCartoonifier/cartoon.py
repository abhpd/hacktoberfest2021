import cv2
import numpy as np
import easygui
import tkinter as tk
from tkinter import *


top = tk.Tk()
top.geometry('400x400')
top.title('Cartoonify Your Image !')
top.configure(background='white')
label = Label(top, background='#CDCDCD', font=('calibri', 20, 'bold'))


def upload():
    ImagePath = easygui.fileopenbox()
    cartoonify(ImagePath)


def cartoonify(ImagePath):
    # Reading the Image
    image = cv2.imread(ImagePath)
    # Finding the Edges of Image
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    gray = cv2.medianBlur(gray, 7)
    edges = cv2.adaptiveThreshold(gray, 255, cv2.ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 9, 10)
    # Making a Cartoon of the image
    color = cv2.bilateralFilter(image, 12, 250, 250)
    cartoon = cv2.bitwise_and(color, color, mask=edges)
    #Visualize the cartoon image
    cv2.imshow("Cartoon", cartoon)
    cv2.waitKey(0) # "0" is Used to close the image window
    cv2.destroyAllWindows()

    #convert to gray scale
    grayImage = cv2.cvtColor(ImagePath, cv2.COLOR_BGR2GRAY)
    #apply gaussian blur
    grayImage = cv2.GaussianBlur(grayImage, (3, 3), 0)
    #detect edges
    edgeImage = cv2.Laplacian(grayImage, -1, ksize=5)
    edgeImage = 255 - edgeImage
    #threshold image
    ret, edgeImage = cv2.threshold(edgeImage, 150, 255, cv2.THRESH_BINARY)
    #blur images heavily using edgePreservingFilter
    edgePreservingImage = cv2.edgePreservingFilter(ImagePath, flags=2, sigma_s=50, sigma_r=0.4)
    #create output matrix
    output =np.zeros(grayImage.shape)
    #combine cartoon image and edges image
    output = cv2.bitwise_and(edgePreservingImage, edgePreservingImage, mask=edgeImage)
    #Visualize the cartoon image
    cv2.imshow("Cartoon", output)
    cv2.waitKey(0) # "0" is Used to close the image window
    cv2.destroyAllWindows()

    cartoon_image = cv2.stylization(ImagePath, sigma_s=150, sigma_r=0.25)
    cv2.imshow('cartoon', cartoon_image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

    cartoon_image1, cartoon_image2  = cv2.pencilSketch(ImagePath, sigma_s=60, sigma_r=0.5, shade_factor=0.02)
    cv2.imshow('pencil', cartoon_image1)
    cv2.waitKey()
    cv2.destroyAllWindows()

    cv2.imshow('pencil', cartoon_image2)
    cv2.waitKey()
    cv2.destroyAllWindows()


upload = Button(top, text="Cartoonify an Image", command=upload, padx=10, pady=5)
upload.configure(background='#364156', foreground='white', font=('calibri', 10, 'bold'))
upload.pack(side=TOP, pady=50)

top.mainloop()
import cv2
image = cv2.imread("./annu.png") #reading the image
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) #converting it to grayscale
inverted_image = 255 - gray_image
blurred = cv2.GaussianBlur(inverted_image, (21, 21), 0)
inverted_blurred = 255 - blurred #creating pencil sketch
pencil_sketch = cv2.divide(gray_image, inverted_blurred, scale=250.0)
cv2.imshow("Original Image", image)
cv2.imshow("Pencil Sketch of annapurna", pencil_sketch)
cv2.waitKey(0)

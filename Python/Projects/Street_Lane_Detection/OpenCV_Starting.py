import matplotlib.pylab as plt
import cv2
import numpy as np

def region_of_interest(img, vertices):
    mask = np.zeros_like(img)
    #channel_count = img.shape[2]
    match_mask_color = 255
    cv2.fillPoly(mask, vertices, match_mask_color)
    masked_image = cv2.bitwise_and(img, mask)
    return masked_image

def draw_the_lines (img, lines):
    img = np.copy (img)
    blank_image = np.zeros((img.shape[0],img.shape[1], 3), dtype=np.uint8)

    for line in lines:
        for x1,y1,x2,y2 in line:
            cv2.line(blank_image, (x1,y1), (x2,y2), (0,255,0), thickness=10)

    img = cv2.addWeighted(img, 0.8, blank_image, 1, 0.0)
    return img

def main(image):
    # print(image.shape)
     height = image.shape[0]
     width = image.shape[1]

     roi_vertices = [(0, height-70), (width / 2.3, height / 2.5), (width, height-70)]#ROI may vary from frame to frame, these values are for my input 

     gray_scale_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)
     canny_image = cv2.Canny(gray_scale_image, 100, 120)
     cropped_image = region_of_interest(canny_image, np.array([roi_vertices], np.int32))

     lines = cv2.HoughLinesP(cropped_image, rho=1, theta=np.pi / 180, threshold=100, lines=np.array([]),
                             minLineLength=80, maxLineGap=120)

     image_with_lines = draw_the_lines(image, lines)
     return image_with_lines

capture  = cv2.VideoCapture('roadvideo.mov')

while(capture.isOpened()):
    ret, frame = capture.read()
    frame = main(frame)
    cv2.imshow('frame',frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

capture.release()
cv2.destroyAllWindows()





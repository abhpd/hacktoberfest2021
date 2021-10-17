import streamlit as st
import numpy as np
from PIL import Image
import cv2


def cartonize(image):
    # converting to RGB
    new_img = np.array(image.convert('RGB'))
    img = cv2.cvtColor(new_img, 1)

    # detect edges
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Edges
    gray = cv2.medianBlur(gray, 5)
    edges = cv2.adaptiveThreshold(
        gray, 255, cv2 .ADAPTIVE_THRESH_MEAN_C, cv2.THRESH_BINARY, 9, 9)
    # Cartoonify using bilateral
    color = cv2.bilateralFilter(img, 9, 250, 250)
    # Cartoon
    cartoon = cv2.bitwise_and(color, color, mask=edges)

    return cartoon


st.title('Cartoonize your character')

uploaded_file = st.file_uploader("Choose a file", type=['jpg', 'png', 'jpeg'])
if uploaded_file is not None:
    our_image = Image.open(uploaded_file)

    col1, col2 = st.columns(2)
    with col1:
        st.image(our_image, caption='Original Image')

    with col2:
        result_img = cartonize(our_image)
        st.image(result_img, caption='Cartoon Image')

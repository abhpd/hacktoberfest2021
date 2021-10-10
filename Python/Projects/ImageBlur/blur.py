from PIL import Image, ImageFilter
img = Image.open('sample.jpg')
blurredImage = img.filter(ImageFilter.GaussianBlur)
blurredImage.save('blurred.jpg')

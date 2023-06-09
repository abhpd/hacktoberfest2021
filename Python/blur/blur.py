from PIL import Image, ImageFilter

before=Image.open("BingWallpaper.jpg")
after=before.filter(ImageFilter.BLUR)
after.save("forestblur.jpg")
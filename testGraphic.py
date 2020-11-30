#NOTE: This is a test file
#More info here: https://pillow.readthedocs.io/en/latest/reference/ImageDraw.html

from PIL import Image, ImageDraw

img = Image.new('RGB', (100, 100))

draw = ImageDraw.Draw(img)

draw.line((0, 0) + img.size, fill = 255)

draw.line((0, img.size[1], img.size[0], 0), fill = 128)

img.save('test.png')
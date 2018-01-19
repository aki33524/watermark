# watermark
Digital Watermark system using key

This program is made for assignment of media security lesson.

# Install
`make all`

# Usage
`./embed image.ppm key message output.ppm`

`./extract image.ppm key bitlength`

# Example
`convert image.jpg -compress none image.ppm`

This program support only P3 ppm image. You can convert the image with ImageMagick.

![image.ppm](https://github.com/aki33524/watermark/blob/master/demo/image.ppm)

`./embed image.ppm password "" output.ppm`

# watermark
Digital Watermark system using key

This program has robustness for converting grayscale.

This is made for assignment of media security lesson.

# Install
`make all`

# Usage
`./embed image.ppm key message output.ppm`

`./extract image.ppm key bitlength`

# Example
`convert demo/image.jpg -compress none demo/image.ppm`

This program support only P3 ppm image. You can convert the image with ImageMagick.

![image.ppm](https://github.com/aki33524/watermark/blob/master/demo/image.png)

`./embed demo/image.ppm password "fuga" demo/embed.ppm`

![embed.ppm](https://github.com/aki33524/watermark/blob/master/demo/embed.png)

`./extract demo/embed.ppm password 32`

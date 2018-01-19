# watermark
Digital Watermark system using key

This is made for assignment of my media security lesson.

# Install
`make all`

# Usage
`./embed image.ppm key message output.ppm alpha`

`./extract image.ppm key bitlength alpha`

When you make alpha greater, embedded image will be lower quality. But you can embed longer message.

# Example
`convert demo/image.jpg -compress none demo/image.ppm`

This program supports only P3 ppm image. You can convert the image with ImageMagick.

![image.ppm](https://github.com/aki33524/watermark/blob/master/demo/image.png)

`./embed demo/image.ppm password "OSAKA-U" demo/embed.ppm`

![embed.ppm](https://github.com/aki33524/watermark/blob/master/demo/embed.png)

`./extract demo/embed.ppm password 32 3`

`OSAKA-U`

This program has robustness for converting grayscale.

`convert demo/embed.ppm -compress none -type GrayScale demo/embed_gray.ppm`

![embed_gray.ppm](https://github.com/aki33524/watermark/blob/master/demo/embed_gray.png)

`./extract demo/embed.ppm password 32 3`

`OSAKA-U`

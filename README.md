PSID: 1838738
Osama Abdullah

The objective of this assignment is to create a program that will generate two semi-circles with the radius of 150 and 100. The larger semi-circle will appear in the top 2 quadrants whereas the smaller semi-circle will appear on the right 2 quadrants.

The environment we will be using is a Linux subsystem, repl.it can be used as a substitute should you not have this, which allows us to run the following commands: 

g++ main.cpp followed by ./a.out 300

We use 300 to set the size of the image/ppm, and this is used to allow a proper size to display the two semicircles from the center of the image without being cut off.

The details of the project are as follows: The two semi-circles will be created through two calls of RasterizeArc, one being 150 and the other being 100 (called in main). Afterwards, it will take the radius and run them through RenderPixel which will determine where the pixels will be rendered based on the size of the radius as a parameter. Finally, this will result in a ppm file to be generated, displaying the two semicircles in the proper placements. 

As aforementioned, a ppm file will be generated, displaying two semicircles, one being 150 radius and the other being 100 radius. The larger will be on the top two quadrants, reflecting to the top of the X axis, while the smaller will be on the right two quadrants, reflecting to the right of the Y axis.

The result will appear as the following:    
![Result](https://i.imgur.com/Bu0A5JX.png "Optional title")




References for code were taken from the last algorithm for RasterizeArc written in the reading document given with the assignment.


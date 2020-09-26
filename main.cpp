
 /*-----------------------------------------------------*
 * Here you will implement the circle rasterization    *
 * method you derived in the written portion of the    *
 * homework.                                           *
 * To compile this in linux:                           *
 *        g++ hw1.cpp                                  *
 * Then, run the program as follows:                   *
 *        ./a.out 200                                  *
 * to generate a 200x200 image containing a circular   *
 * arc. 
 * Your code will generate a .ppm file containing the  *
 * final image. These images can be viewed using       *
 * "display" in Linux or Irfanview in Mac/Windows.     *
 *******************************************************/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
using namespace std;

// We'll store image info as globals; not great programming practice
// but ok for this short program.
int size;
bool **image;

void renderPixel(int x, int y, int radius) {
	assert(x >= 0 && y >= 0 && x <= size && y <= size);
  if (radius == 100){
	image[x][y] = 1;
  image[y][x] = 1;
  image[size - x][y] = 1;
  image[size - y][x] = 1;
  }
  else{
	image[x][y] = 1;
  image[y][x] = 1;
  image[x][size - y] = 1;
  image[y][size - x] = 1;
  }
}



void rasterizeArc(int radius) {
  int x = 150;
  int y = radius + x;
  int d = 1 - radius;
  int deltaE = 3;
  int deltaSE = -2 * radius + 5;
  renderPixel(x,y, radius);

  while (y > x){
    if (d < 0){
    d += deltaE;
    deltaE += 2;
    deltaSE += 2;
    }
   else{
    d += deltaSE;
    deltaE += 2;
    deltaSE += 4;
    y--;
    }
    x++;
    renderPixel(x,y, radius);
    }
}


int main(int argc, char *argv[]) {
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " circleSize\n";
		return 0;
	}
	
#ifdef _WIN32
	sscanf_s(argv[1], "%d", &size);
#else
	sscanf(argv[1], "%d", &size);
#endif
	if (size <= 0) {
		cout << "Image must be of positive size.\n";
		return 0;
	}
	
	// reserve image as 2d array
	image = new bool*[size+1];
	for (int i = 0; i <= size; i++) image[i] = new bool[size+1];
	
	rasterizeArc(100);
  rasterizeArc(150);
	
	char filename[50];
#ifdef _WIN32
	sprintf_s(filename, 50, "circle%d.ppm", size);
#else
	sprintf(filename, "circle%d.ppm", size);
#endif
	
	ofstream outfile(filename);
	outfile << "P3\n# " << filename << "\n";
	outfile << size+1 << ' ' << size+1 << ' ' << 1 << endl;

	for (int i = 0; i <= size; i++)
	for (int j = 0; j <= size; j++)	
		outfile << image[size-i][j] << " 0 0\n";
	
	// delete image data
	for (int i = 0; i <= size; i++) delete [] image[i];
	delete [] image;
	
	return 0;
}

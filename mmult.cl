#include "my_math.h"
__kernel void mmult(__global float *a, __global float *b, __global float *output)
{

  float running = 0;
	int c=get_global_id(0);
	int r = get_global_id(1);

  for (int index=0; index<rank; index++) {
#pragma HLS pipeline
    int aIndex = r*rank + index;
    int bIndex = index*rank + c;
    running += mysqrt(a[aIndex] * b[bIndex]);
  }
  output[r*rank + c] = running;
}

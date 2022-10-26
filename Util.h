#ifndef UTIL_H
#define UTIL_H
#include<math.h>

struct point2f
{
  int x, y;  
};

float dist(point2f pos, point2f goal)
{
  int a,b,c;
  a=(goal.x)-(pos.x);
  b=(goal.y)-(goal.y);
  c=sqrt((a*a)+(b*b));
    return c;
};

struct Robot
{
  int index;
  float theta;
  point2f pos; 
  point2f goal;
};

struct Roda
{
  int vel;
};

class util
{
    private:

    public:
        float dist(point2f pos, point2f goal);
}; 

#endif
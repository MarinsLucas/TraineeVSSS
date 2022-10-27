
#ifndef UTIL_H
#define UTIL_H

#include<cmath>
#include <iostream>

using namespace std; 

template <typename T>
struct point2f
{
  T x,y;  
};

struct Bola{
  point2f<int> pos;
  point2f<float> velocity;
  float sin;
}; 

struct rodas
{
  int ve;
  int vd;
};

struct Robot
{
  int index;
  float theta;
  point2f<int> pos; 
  point2f<int> goal;
  rodas c;
}; 

template<typename T>
float dist(point2f<T> pos, point2f<T> goal)
{
  int ha,he,hi;
  ha=(goal.x)-(pos.x);
  he=(goal.y)-(goal.y);
  hi=sqrt((ha*ha)+(he*he));
return hi;
}
/*vou considerar o robô como ponto, então ele não pode estar virado ao contrário
procurando o arcsen*/

template<typename T>
float angle(point2f<T> pos, point2f<T> goal)
{
    int ha,he,hi,ho;
  ha=(goal.x)-(pos.x);
  he=(goal.y)-(goal.y);
  hi=ha/he;
  ho=asin(hi);
  
return ho;
}

class util
{
    private:
    Robot robot; 

    public:
    float dist(point2f<int> pos, point2f<int> goal);
    float angle();
    
}; 

#endif
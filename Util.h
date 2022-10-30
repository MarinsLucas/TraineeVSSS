#ifndef UTIL_H
#define UTIL_H

#include<cmath>
#include <iostream>

#define ROBOT_MAX_VELOCITY 10.0
#define ACE 10

using namespace std; 

template <typename T>
struct point2f
{
  T x,y;  
};

struct Placar{
  short a; 
  short b;
};

struct Bola{
  point2f<float> pos;
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
  point2f<float> pos; 
  point2f<float> goal;
  point2f<float> velocity; 
  rodas c;
}; 

class util
{
    public:
    template<typename T>
    float dist(point2f<T> pos, point2f<T> goal);
    template<typename T>
    point2f<T> angle(point2f<T> pos, point2f<T> goal);
   
}; 

template<typename T>
float util::dist(point2f<T> pos, point2f<T> goal)
{
  float cat_o,cat_a,hip;
  cat_a=(goal.x)-(pos.x);
  cat_o=(goal.y)-(pos.y);
  hip=sqrt((cat_a*cat_a)+(cat_o*cat_o));
	return hip;
}
/*vou considerar o robô como ponto, então ele não pode estar virado ao contrário
procurando o arcsen*/

template<typename T>
point2f<T> util::angle(point2f<T> pos, point2f<T> goal)
{
  point2f<T> sincos; 
  float cat_a,cat_o;
  cat_o=(goal.y)-(pos.y);
  cat_a=(goal.x)-(pos.x);
  sincos.y = (cat_o == 0) ? 0 : cat_o/sqrt((cat_a*cat_a)+(cat_o*cat_o));
  sincos.x = (cat_a == 0) ? 0 : cat_a/sqrt((cat_a*cat_a)+(cat_o*cat_o));  
	return sincos;
}

#endif
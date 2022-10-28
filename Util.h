#ifndef UTIL_H
#define UTIL_H

#include<cmath>
#include <iostream>

#define ROBOT_MAX_VELOCITY 10.0

using namespace std; 

template <typename T>
struct point2f
{
  T x,y;  
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
  point2f<int> pos; 
  point2f<int> goal;
  rodas c;
}; 

template<typename T>
float dist(point2f<T> pos, point2f<T> goal)
{
  float cat_o,cat_a,hip;
  cat_a=(goal.x)-(pos.x);
  cat_o=(goal.y)-(goal.y);
  hip=sqrt((cat_a*cat_a)+(cat_o*cat_o));
return hip;
}
/*vou considerar o robô como ponto, então ele não pode estar virado ao contrário
procurando o arcsen*/

template<typename T>
float angle(point2f<T> pos, point2f<T> goal)
{
  float cat_a,cat_o,sen,theta;
  cat_a=(goal.x)-(pos.x);
  cat_o=(goal.y)-(goal.y);
  sen=cat_o/cat_a;
  theta=asin(sen);
  
return theta;
}

class util
{
    public:
    float dist(point2f<float> pos, point2f<float> goal);
    float angle(point2f<float> pos, point2f<float> goal);
}; 

#endif
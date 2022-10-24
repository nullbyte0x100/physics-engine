#include<iostream>
struct AABB
{
  Vec2 min;
  Vec2 max;
};
bool AABBvsAABB( AABB a, AABB b )
{
  // Exit with no intersection if found separated along an axis
  if(a.max.x < b.min.x or a.min.x > b.max.x) return false
  if(a.max.y < b.min.y or a.min.y > b.max.y) return false
 
  // No separating axis found, therefor there is at least one overlapping axis
  return true
}
struct Circle
{
  float radius
  Vec position
};
float Distance( Vec2 a, Vec2 b )
{
  return sqrt( (a.x - b.x)^2 + (a.y - b.y)^2 )
}
 
bool CirclevsCircleUnoptimized( Circle a, Circle b )
{
  float r = a.radius + b.radius
  return r < Distance( a.position, b.position )
}
 
bool CirclevsCircleOptimized( Circle a, Circle b )
{
  float r = a.radius + b.radius
  r *= r
  return r < (a.x + b.x)^2 + (a.y + b.y)^2
}
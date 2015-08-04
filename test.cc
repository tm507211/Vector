#include <iostream>
#include <vector.h>
using namespace CM;
using std::cout;
using std::endl;

int main(){
 Vector2<double> Vec2(1, 1);
 Vector3<double> a(1, 0, 0), b(0, 2, 0);
 cout << cross(a, b * 0.5) << endl;
 return 0;
}

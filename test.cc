#include <iostream>
#include <vector.h>
using namespace CM;
using std::cout;
using std::endl;

int main(){
 Vector2<double>  vec(1, 1);
 cout << vec << " " << vec.length() << endl;
 vec.normalize();
 cout << vec << " " << vec.length() << endl;
 return 0;
}

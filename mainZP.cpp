using namespace std;

#include <iostream>

#include <vector>

#include <queue>

struct vec3 {

float x, y, z;
};

class Compare {

public:

inline static vec3 p;



bool operator()(vec3 below, vec3 above) {

	float b = (below.x- p.x) * (below.x - p.x) + (below.y - p.y) * (below.y - p.y) + (below.z - p.z) * (below.z - p.z);

	float a = (above.x - p.x) * (above.x - p.x) + (above.y - p.y) * (above.y - p.y) + (above.z - p.z) * (above.z - p.z);



	if (a > b) return false;

	else return true;

}
};

int main() {

priority_queue<vec3, vector<vec3>, Compare> q;



Compare::p = { 0, 0, 0 };



q.push({ 5, 5, 5 });

q.push({ 2, 2, 2 });

q.push({ 1, 1, 1 });

q.push({ 4, 4, 4 });



while (!q.empty()) {

	vec3 a = q.top();

	cout << a.x << " " << a.y << " " << a.z << endl;

	q.pop();

}
}

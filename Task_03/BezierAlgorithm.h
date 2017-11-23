#ifndef BEZIER_ALGORITHM_H_
#define BEZIER_ALGORITHM_H_
#include <iostream>
using namespace std;

template <class Pen>
class BezierAlgorithm{
	private:
		Pen pen;
		int* C;
		vector <Point> vec;
		void getComb(int n);
		Point clacPoint(float u);
	public:
		BezierAlgorithm(Pen pen):pen(pen){ }
		void addPoint(int x, int y);
		void BezierCompute(int N);
};

template <class Pen>
void BezierAlgorithm <Pen> :: addPoint(int x, int y){
	if(vec.size() < 10) vec.push_back(Point(x, y));
}


template <class Pen>
void BezierAlgorithm <Pen> :: getComb(int n){
	C = new int[n + 4];
	C[0] = 1;
	for(int i = 1; i <= n; i++){
		C[i] = C[i-1] * (n-i+1) / i;
	}
}

template <class Pen>
Point BezierAlgorithm <Pen> :: clacPoint(float u){
	int n = vec.size() - 1;
	float x = 0, y = 0;
	for(int i = 0; i <= n; i++){
		x = x + float(vec[i].x) * C[i] * pow(u, i) * pow(1 - u, n - i);
		y = y + float(vec[i].y) * C[i] * pow(u, i) * pow(1 - u, n - i);
	}
	return Point(x, y);
}

template <class Pen>
void BezierAlgorithm <Pen> :: BezierCompute(int N){
	if(vec.size() < 2) return;
	int n = vec.size(); 
	getComb(n-1);
	LineAlgorithm <Pen> lin((Pen(pen)));
	Point last = clacPoint(0);
	for(int i = 1; i <= N; i++){
		float u = float(i) / float(N);
		Point cur = clacPoint(u);
		lin.LineBresenhamAlgorithm(last.x, last.y, cur.x, cur.y);
		last = cur;
	}
	delete[] C;
}

#endif

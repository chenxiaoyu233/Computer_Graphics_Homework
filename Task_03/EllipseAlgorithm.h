#ifndef ELLIPSE_ALGORITHM_H_
#define ELLIPSE_ALGORITHM_H_

template <class Pen>
class EllipseAlgorithm{
	private:
		Pen pen;
	public:
		EllipseAlgorithm(Pen pen):pen(pen){ }
		void EllipseCompute(int ax, int ay, int bx, int by, int cx, int cy, int N);
};

template <class Pen>
void EllipseAlgorithm <Pen> :: EllipseCompute(int ax, int ay, int bx, int by, int cx, int cy, int N){
	Point a(ax, ay), b(bx, by), c(cx, cy);
	Point mid = (a + b) / 2;
	float A = (Length(a-c) + Length(b-c)) * 0.5, A2 = A * A;
	float C = Length(a-b) * 0.5, C2 = C * C;
	float B2 = A2 - C2, B = sqrt(B2);
	float ang = atan2(by-ay, bx-ax);
	Point X = (b-a) * (A / 2 / C);
	Point Y = Rotate(X, pi/2);
	Y = Y * (B / Length(Y));
	Point last = mid + X * cos(ang) + Y * sin(ang);
	LineAlgorithm <Pen> lin((Pen(pen)));
	for(int i = 1; i <= N; i++){
		float Ang = ang + 2*pi/N*i;
		Point cur = mid + X * cos(Ang) + Y * sin(Ang);
		lin.LineBresenhamAlgorithm(last.x, last.y, cur.x, cur.y);
		last = cur;
	}
}

#endif

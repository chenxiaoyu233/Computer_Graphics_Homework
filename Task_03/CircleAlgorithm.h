#ifndef CIRCLE_ALGORITHM_H_
#define CIRCLE_ALGORITHM_H_

template <class Pen>
class CircleAlgorithm{
	private:
		Pen pen;
		void midPointSetPixel(int cx, int cy, int ptx, int pty, int grayScale = 255);
	public:
		CircleAlgorithm(Pen pen):pen(pen){ }
		void CircleMidPoint(int cx, int cy, int R);
		void CircleWuXiaoLinAlgorithm(int cx, int cy, int R);
};

template <class Pen>
void CircleAlgorithm <Pen>::midPointSetPixel(int cx, int cy, int ptx, int pty, int grayScale){
	pen.drawPoint(cx + ptx, cy + pty, grayScale);
	pen.drawPoint(cx - ptx, cy + pty, grayScale);
	pen.drawPoint(cx + ptx, cy - pty, grayScale);
	pen.drawPoint(cx - ptx, cy - pty, grayScale);
	pen.drawPoint(cx + pty, cy + ptx, grayScale);
	pen.drawPoint(cx - pty, cy + ptx, grayScale);
	pen.drawPoint(cx + pty, cy - ptx, grayScale);
	pen.drawPoint(cx - pty, cy - ptx, grayScale);
}

template <class Pen>
void CircleAlgorithm <Pen>::CircleMidPoint(int cx, int cy, int R){
	Point <int> c(cx, cy), pt(0, R);
	int p = 1 - R;
	while(pt.x <= pt.y){
		midPointSetPixel(c.x, c.y, pt.x, pt.y);
		++ pt.x;
		if(p < 0) p = p + 2 * pt.x + 1;
		else -- pt.y, p = p + 2 * pt.x + 1 - 2 * pt.y;
	}
}

//画圆算法使用的引理在x==y附近的时候受精度影响很大，
//这是调参狗的胜利 -> 0.25是个不错的数字
template <class Pen>
void CircleAlgorithm <Pen> :: CircleWuXiaoLinAlgorithm(int cx, int cy, int R){
	Point <int> pt(R, -1), c(cx, cy);
	//midPointSetPixel(c.x, c.y, pt.x, pt.y, 255);
	int T = 0, m = 8, mask = 255;
	float lim = sqrt(0.5) * R + 0.25;
	while(pt.x > pt.y){
		++pt.y;
		if(pt.y > lim) break;
		float tt = sqrt(float(R)*R - float(pt.y)*pt.y);
		int D = float((1 << m)-1) * (ceil(tt) - tt) + 0.5;
		if(D < T) pt.x--; T = D;
		midPointSetPixel(c.x, c.y, pt.x, pt.y, D^mask);
		midPointSetPixel(c.x, c.y, pt.x-1, pt.y, D);
	}
}

#endif

#ifndef FILL_ALGORITHM_H_
#define FILL_ALGORITHM_H_

#include <queue>

template <class Pen>
class FillAlgorithm{
	private:
		Pen pen;
	public:
		FillAlgorithm(Pen pen):pen(pen){ }
		void FillFloodAlgorithm(int cx, int cy);
};

extern int dirx[4], diry[4];

template <class Pen>
void FillAlgorithm <Pen> :: FillFloodAlgorithm(int cx, int cy){
	int tR = pen.paper -> accessPixel(cx, cy, 0),
	    tG = pen.paper -> accessPixel(cx, cy, 1),
	    tB = pen.paper -> accessPixel(cx, cy, 2);
	bool *vis = new bool[(pen.paper -> Width) * (pen.paper -> Height)];
	for(int i = 0; i < pen.paper -> Width; i++)
		for(int j = 0; j < pen.paper -> Height; j++)
			vis[j*(pen.paper -> Width) + i] = 0;
	typedef std::pair<int, int> pii;
	std::queue <pii> q; while(!q.empty()) q.pop();
	q.push(pii(cx, cy)); vis[cy*(pen.paper -> Width) + cx] = 1;
#define X first
#define Y second
	while(!q.empty()){
		pii tt = q.front(); q.pop();
		pen.drawPoint(tt.X, tt.Y);
		for(int i = 0; i < 4; i++){
			int x1 = tt.X + dirx[i], y1 = tt.Y + diry[i];
			if(x1 < 0 || y1 < 0 || x1 >= pen.paper -> Width || y1 >= pen.paper -> Height) continue;
			if(pen.paper -> accessPixel(x1, y1, 0) != tR) continue;
			if(pen.paper -> accessPixel(x1, y1, 1) != tG) continue;
			if(pen.paper -> accessPixel(x1, y1, 2) != tB) continue;
			if(!vis[y1*(pen.paper -> Width) + x1]){
				vis[y1*(pen.paper -> Width) + x1] = 1;
				q.push(pii(x1, y1));
			}
		}
	}
#undef X
#undef Y
	delete[] vis;
}

#endif

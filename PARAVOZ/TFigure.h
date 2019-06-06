#pragma once
using namespace std;
using namespace System::Drawing;

class TFigure {
protected:
	bool IsVisible;
public:
	TFigure(void) {}
	virtual void Show(Graphics^g) = 0;
	virtual void Hide(Graphics^g) = 0;
	virtual void Move(Graphics^g, int dx, int dy) = 0;

};
class TPoint :public TFigure {
protected:
	int x, y;
public:
	TPoint(int _x, int _y) {
		x = _x;
		y = _y;
	}
	virtual void Show(Graphics^g) {
		g->DrawEllipse(Pens::Black, x - 2, y - 2, 4, 4);
	}
	virtual void Hide(Graphics^g) {
		g->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
	}
	virtual void Move(Graphics^g, int dx, int dy) {
		Hide(g);
		x += dx;
		y += dy;
		Show(g);
	}
};

class TCircle :public TPoint {
protected:
	int R;
public:
	TCircle(int _x, int _y, int _R) :TPoint(_x, _y) {
		R = _R;
	}
	virtual void Show(Graphics^g) {
		g->DrawEllipse(Pens::Black, x - R, y - R, 2 * R, 2 * R);
	}
	virtual void Hide(Graphics^g) {
		g->DrawEllipse(Pens::White, x - R, y - R, 2 * R, 2 * R);
	}
};

class TRectangle :public TPoint {
protected:
	int w, h;
public:
	TRectangle(int _x, int _y, int _w, int _h) :TPoint(_x, _y) {
		w = _w;
		h = _h;
	}
	virtual void Show(Graphics^g) {
		g->DrawRectangle(Pens::Black, x, y, w, h);
	}
	virtual void Hide(Graphics^g) {
		g->DrawRectangle(Pens::White, x, y, w, h);
	}
};

class TLine :public TPoint {
protected:
	int x1, y1;
public:
	TLine(int _x, int _y, int _x1, int _y1) : TPoint(_x, _y) {
		x1 = _x1;
		y1 = _y1;
	}
	virtual void Show(Graphics^g) {
		g->DrawLine(Pens::Black, x, y, x1, y1);
	}
	virtual void Hide(Graphics^g) {
		g->DrawLine(Pens::White, x, y, x1, y1);
	}
	virtual void Move(Graphics^g, int dx, int dy) {
		Hide(g);
		x += dx;
		y += dy;
		x1 += dx;
		y1 += dy;
		Show(g);
	}
};


/*
#pragma once
#include "MyCar.h"
#include "MyPipe.h"
#include "MyEngine.h"
class MyLocomotive {
private:
	MyCar * car;
	MyPipe * pipe;
	MyEngine * engineLeft, *engineRight;
public:
	MyLocomotive(int x, int y, int s) {
		car = new MyCar(x, y, s);
		pipe = new MyPipe(x + 32 * s, y - 6 * s, s);
		engineLeft = new MyEngine(x + 6 * s, y + 20 * s, s);
		engineRight = new MyEngine(x + 26 * s, y + 20 * s, s);
	};
	~MyLocomotive() {
		delete car;
		delete pipe;
		delete engineLeft;
		delete engineRight;
	};
	MyLocomotive(const MyLocomotive& tmp) {
		car = new MyCar(*(tmp.car));
		pipe = new MyPipe(*(tmp.pipe));
		engineLeft = new MyEngine(*(tmp.engineLeft));
		engineRight = new MyEngine(*(tmp.engineRight));
	};
	MyLocomotive& operator= (const MyLocomotive& tmp) {
		delete this->car;
		delete this->pipe;
		delete this->engineLeft;
		delete this->engineRight;
		this->car = new MyCar(*(tmp.car));
		this->pipe = new MyPipe(*(tmp.pipe));
		this->engineLeft = new MyEngine(*(tmp.engineLeft));
		this->engineRight = new MyEngine(*(tmp.engineRight));
		return *this;
	};
	void move(int dx) {
		car->move(dx);
		pipe->move(dx);
		engineLeft->move(dx);
		engineRight->move(dx);
	};
	void draw(System::Drawing::Graphics^ g) {
		car->draw(g);
		pipe->draw(g);
		engineLeft->draw(g);
		engineRight->draw(g);
	};
};*/
#pragma once
class Rectangle
{
public:
	Rectangle(int left, int bottom, int right, int up) :_left(left), _bottom(bottom), _right(right), _up(up) {}
	int height()const { return _up - _bottom; }
	int width()const { return _right - _left; }
	int area()const { return height()*width(); }
	void MoveTo(int newLeft, int newBottom)
	{
		int h = height();
		int w = width();
		_left = newLeft;
		_bottom = newBottom;
		_right = _left + w;
		_up = _bottom + h;
	}
private:
	int _left;
	int _bottom;
	int _right;
	int _up;
};
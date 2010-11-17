#ifndef UIElement_h
#define UIElement_h

class UIElement {
	protected:
		Rectangle	rectangle;

	public:
		Rectangle GetRectangle() {
			return rectangle;
		}
};

#endif
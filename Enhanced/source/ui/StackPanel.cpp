#include "StackPanel.h"

void Item_UpdatePosition(itemDef_t *item);

StackPanel::StackPanel(void) {

}

void StackPanel::Arrange() {
	const int ChildMargin = 5;
	int x = rectangle.x;
	int y = rectangle.y;


	for(std::list<itemDef_t*>::iterator i = oldChildren.begin(); i != oldChildren.end(); ++i) {
		itemDef_t *child = (*i);

		int margin = 0;
		if(child->window.border != 0) {
			margin = child->window.borderSize;
		}

		child->window.rectClient.SetPosition(x, y);
		//child->textRect.SetPosition(x + ChildMargin, y + ChildMargin);
		//child->window.rect.SetPosition(x + ChildMargin, y + ChildMargin);
		Item_UpdatePosition(child);

		y += child->window.rectClient.h;

	}
}
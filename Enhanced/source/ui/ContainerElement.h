#ifndef ContainerElement_h
#define ContainerElement_h

#include "UIElement.h"
#include "itemDef_t.h"
#include <list>

void Item_Paint(itemDef_t *item);

class ContainerElement : public UIElement {
	protected:
		std::list<UIElement*> children;
		std::list<itemDef_t*> oldChildren;

	public:
		/*std::list<UIElement*> GetChildren() {
			return children;
		}*/

		ContainerElement() {}
		~ContainerElement() {}

		void AddOldElement(itemDef_t* item) {
			oldChildren.push_back(item);
		}

		void AddElement(UIElement* element) {
			children.push_back(element);
		}

		void Draw() {
			for(std::list<itemDef_t*>::iterator i = oldChildren.begin(); i != oldChildren.end(); ++i) {
				itemDef_t *child = (*i);

				Item_Paint(child);
			}
		}
};

#endif
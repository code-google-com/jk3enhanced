#ifndef ContainerElement_h
#define ContainerElement_h

#include "UIElement.h"
#include "itemDef_t.h"
#include <list>

class ContainerElement : public UIElement {
	protected:
		std::list<UIElement*> children;
		std::list<itemDef_t*> oldChildren;

	public:
		/*std::list<UIElement*> GetChildren() {
			return children;
		}*/

		ContainerElement() {}

		void AddOldElement(itemDef_t *item) {
			oldChildren.insert(oldChildren.end(), item);
		}

		void AddElement(UIElement *element) {
			children.insert(children.end(), element);
		}
};

#endif
#include "PlacementFactory.h"

namespace rechteckpackungen {
namespace bStarTree2Placement {

//TODO assert that y is not smaller than yMin - height (+-1?) of root and not too big either
int PlacementFactory::findMinY(std::list<PositionedRectangle*>* horizontalContour,
		std::list<PositionedRectangle*>::iterator currentHorizontalContourElement, int width) {
	int y = 0;
	int xMax = (*currentHorizontalContourElement)->getXMax() + width;
	if (horizontalContour->end() != currentHorizontalContourElement) {
		currentHorizontalContourElement++;
		y = std::max(y, (*currentHorizontalContourElement)->getYMax());
		bool end = horizontalContour->end() != currentHorizontalContourElement;
		while ((*currentHorizontalContourElement)->getXMax() < xMax && *(--horizontalContour->end()) != *currentHorizontalContourElement) {
			currentHorizontalContourElement++;
			y = std::max(y, (*currentHorizontalContourElement)->getYMax());
		}
	}
	return y;
}

std::list<PositionedRectangle*>::iterator PlacementFactory::updateContour(std::list<PositionedRectangle*>* horizontalContour,
		std::list<PositionedRectangle*>::iterator firstHorizontalContourElementBelowNewElement, PositionedRectangle* newElement) {
	auto currentHorizontalontourElementBelowNewElement = firstHorizontalContourElementBelowNewElement;
	while ((*currentHorizontalontourElementBelowNewElement)->getXMax() <= newElement->getXMax()) {
		if ((*currentHorizontalontourElementBelowNewElement)->getXMin() >= newElement->getXMin()
				&& (*currentHorizontalontourElementBelowNewElement)->getXMin() < newElement->getXMax()) {
			currentHorizontalontourElementBelowNewElement = horizontalContour->erase(currentHorizontalontourElementBelowNewElement);
		} else {
			currentHorizontalontourElementBelowNewElement++;
		}
	}
	return horizontalContour->insert(currentHorizontalontourElementBelowNewElement, newElement);
}

void PlacementFactory::buildPlacementRecursively(BStarTree* tree, Placement* placement, BTreeNode* rootNode,
		PositionedRectangle* rootPositionedRecangle, std::list<PositionedRectangle*>* horizontalContour,
		std::list<PositionedRectangle*>::iterator currentHorizontalContourElement) {
	auto rootRectangle = tree->getRectangle(rootNode);

	//Left child = rectangle to the right
	if (rootNode->hasLeftChild()) {
		auto leftChildRectangle = tree->getRectangle(rootNode->getLeftChild());
		int y = findMinY(horizontalContour, currentHorizontalContourElement, leftChildRectangle->getWidth());
		auto leftChildPositionedRectangle = new PositionedRectangle(leftChildRectangle, new Coordinates(rootPositionedRecangle->getXMax(), y));
		placement->add(leftChildPositionedRectangle);
		auto firstHorizontalContourElementBelowNewElement = currentHorizontalContourElement;
		firstHorizontalContourElementBelowNewElement++;
		auto rightCurrentHorizontalContourElement = updateContour(horizontalContour, firstHorizontalContourElementBelowNewElement, leftChildPositionedRectangle);
		buildPlacementRecursively(tree, placement, rootNode, rootPositionedRecangle, horizontalContour, rightCurrentHorizontalContourElement);
	}

//Right child = rectangle to the top
	if (rootNode->hasRightChild()) {

	}

}

Placement* PlacementFactory::create(BStarTree* tree) {
	auto placement = new Placement();
	auto horizontalContour = std::list<PositionedRectangle*>();

	auto rootPositionedRectangle = new PositionedRectangle(tree->getRectangle(tree->getRoot()), new Coordinates(0, 0));

	placement->add(rootPositionedRectangle);
	horizontalContour.push_back(rootPositionedRectangle);

	buildPlacementRecursively(tree, placement, tree->getRoot(), rootPositionedRectangle, &horizontalContour, horizontalContour.begin());

	return placement;
}

}
}

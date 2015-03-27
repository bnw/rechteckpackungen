#include "PlacementFactory.h"

namespace rechteckpackungen {
namespace bStarTree2Placement {

//TODO assert that y is not smaller than yMin - height (+-1?) of root and not too big either
int PlacementFactory::findMinY(std::list<PositionedRectangle*>* horizontalContour,
		std::list<PositionedRectangle*>::iterator firstHorizontalContourElementBelowNewElement, int width, int xMin) {
	int y = 0;
	int xMax = xMin + width;
	if (horizontalContour->end() != firstHorizontalContourElementBelowNewElement) {
		y = std::max(y, (*firstHorizontalContourElementBelowNewElement)->getYMax());
		while ((*firstHorizontalContourElementBelowNewElement)->getXMax() < xMax
				&& horizontalContour->back() != *firstHorizontalContourElementBelowNewElement) {
			firstHorizontalContourElementBelowNewElement++;
			y = std::max(y, (*firstHorizontalContourElementBelowNewElement)->getYMax());
		}
	}
	return y;
}

std::list<PositionedRectangle*>::iterator PlacementFactory::updateContour(std::list<PositionedRectangle*>* horizontalContour,
		std::list<PositionedRectangle*>::iterator firstHorizontalContourElementBelowNewElement, PositionedRectangle* newElement) {
	//TODO refactor
	if(firstHorizontalContourElementBelowNewElement == horizontalContour->end()){
		horizontalContour->push_back(newElement);
		return --horizontalContour->end();
	}

	auto currentHorizontalontourElementBelowNewElement = firstHorizontalContourElementBelowNewElement;
	while ((*currentHorizontalontourElementBelowNewElement)->getXMax() <= newElement->getXMax()) {
		if (horizontalContour->back() == *currentHorizontalontourElementBelowNewElement) {
			horizontalContour->pop_back();
			horizontalContour->push_back(newElement);
			return --horizontalContour->end();
		} else {
			currentHorizontalontourElementBelowNewElement = horizontalContour->erase(currentHorizontalontourElementBelowNewElement);
		}
	}
	return horizontalContour->insert(currentHorizontalontourElementBelowNewElement, newElement);
}

void PlacementFactory::buildPlacementRecursively(BStarTree* tree, std::shared_ptr<Placement> placement, BTreeNode* rootNode,
		PositionedRectangle* rootPositionedRecangle, std::list<PositionedRectangle*>* horizontalContour,
		std::list<PositionedRectangle*>::iterator currentHorizontalContourElement) {

	//Left child = rectangle to the right
	if (rootNode->hasLeftChild()) {
		auto leftChild = rootNode->getLeftChild();
		auto leftChildRectangle = tree->getRectangle(leftChild);
		auto firstHorizontalContourElementBelowNewElement = currentHorizontalContourElement;
		firstHorizontalContourElementBelowNewElement++;
		int x = rootPositionedRecangle->getXMax();
		int y = findMinY(horizontalContour, firstHorizontalContourElementBelowNewElement, leftChildRectangle->getWidth(), x);
		auto leftChildPositionedRectangle = new PositionedRectangle(leftChildRectangle, x, y);
		placement->add(leftChildPositionedRectangle);
		auto newCurrentHorizontalContourElement = updateContour(horizontalContour, firstHorizontalContourElementBelowNewElement,
				leftChildPositionedRectangle);
		buildPlacementRecursively(tree, placement, leftChild, leftChildPositionedRectangle, horizontalContour, newCurrentHorizontalContourElement);
	}

	//Right child = rectangle to the top
	if (rootNode->hasRightChild()) {
		auto rightChild = rootNode->getRightChild();
		auto rightChildRectangle = tree->getRectangle(rootNode->getRightChild());
		int x = rootPositionedRecangle->getXMin();
		int y = findMinY(horizontalContour, currentHorizontalContourElement, rightChildRectangle->getWidth(), x);
		auto rightChildPositionedRectangle = new PositionedRectangle(rightChildRectangle, x, y);
		placement->add(rightChildPositionedRectangle);
		auto newCurrentHorizontalContourElement = updateContour(horizontalContour, currentHorizontalContourElement, rightChildPositionedRectangle);
		buildPlacementRecursively(tree, placement, rightChild, rightChildPositionedRectangle, horizontalContour, newCurrentHorizontalContourElement);
	}

}

std::shared_ptr<Placement> PlacementFactory::create(BStarTree* tree) {
	auto placement = std::shared_ptr<Placement>(new Placement());
	auto horizontalContour = std::list<PositionedRectangle*>();

	auto rootPositionedRectangle = new PositionedRectangle(tree->getRectangle(tree->getRoot()), 0, 0);

	placement->add(rootPositionedRectangle);
	horizontalContour.push_back(rootPositionedRectangle);

	buildPlacementRecursively(tree, placement, tree->getRoot(), rootPositionedRectangle, &horizontalContour, horizontalContour.begin());

	return placement;
}

}
}

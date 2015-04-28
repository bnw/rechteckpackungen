#include "PlacementFactory.h"

namespace rechteckpackungen {
namespace bStarTree2Placement {

//TODO assert that y is not smaller than yMin - height (+-1?) of root and not too big either
int PlacementFactory::findMinY(std::list<PositionedRectangle>* horizontalContour,
		std::list<PositionedRectangle>::iterator firstHorizontalContourElementBelowNewElement, int width, int xMin) const {
	int y = 0;
	int xMax = xMin + width;
	if (horizontalContour->end() != firstHorizontalContourElementBelowNewElement) {
		y = std::max(y, firstHorizontalContourElementBelowNewElement->getYMax());
		while (firstHorizontalContourElementBelowNewElement != std::prev(horizontalContour->end()) && firstHorizontalContourElementBelowNewElement->getXMax() < xMax) {
			firstHorizontalContourElementBelowNewElement++;
			y = std::max(y, firstHorizontalContourElementBelowNewElement->getYMax());
		}
	}
	return y;
}

std::list<PositionedRectangle>::iterator PlacementFactory::updateContour(std::list<PositionedRectangle>* horizontalContour,
		std::list<PositionedRectangle>::iterator firstHorizontalContourElementBelowNewElement, PositionedRectangle newElement) const {
	//TODO refactor
	if (firstHorizontalContourElementBelowNewElement == horizontalContour->end()) {
		horizontalContour->push_back(newElement);
		return --horizontalContour->end();
	}

	auto currentHorizontalontourElementBelowNewElement = firstHorizontalContourElementBelowNewElement;
	while (currentHorizontalontourElementBelowNewElement->getXMax() <= newElement.getXMax()) {
		if (std::prev(horizontalContour->end()) == currentHorizontalontourElementBelowNewElement) {
			horizontalContour->pop_back();
			horizontalContour->push_back(newElement);
			return --horizontalContour->end();
		} else {
			currentHorizontalontourElementBelowNewElement = horizontalContour->erase(currentHorizontalontourElementBelowNewElement);
		}
	}
	return horizontalContour->insert(currentHorizontalontourElementBelowNewElement, newElement);
}

bool PlacementFactory::buildPlacementRecursively(const Rectangle& bounds, const BStarTree& tree, std::shared_ptr<Placement> placement,
		BTreeNode* rootNode, PositionedRectangle rootPositionedRecangle, std::list<PositionedRectangle>* horizontalContour,
		std::list<PositionedRectangle>::iterator currentHorizontalContourElement) const {

	//Left child = rectangle to the right
	if (rootNode->hasLeftChild()) {
		auto leftChild = rootNode->getLeftChild();
		auto leftChildRectangle = tree.getRectangle(leftChild);
		auto firstHorizontalContourElementBelowNewElement = currentHorizontalContourElement;
		firstHorizontalContourElementBelowNewElement++;
		int x = rootPositionedRecangle.getXMax();
		int y = findMinY(horizontalContour, firstHorizontalContourElementBelowNewElement, leftChildRectangle->getWidth(), x);
		auto leftChildPositionedRectangle = PositionedRectangle(*leftChildRectangle, x, y);
		placement->add(leftChildPositionedRectangle);
		if (!leftChildPositionedRectangle.getTopRightCoordinates().areWithin(bounds)) {
			return false;
		}
		auto newCurrentHorizontalContourElement = updateContour(horizontalContour, firstHorizontalContourElementBelowNewElement,
				leftChildPositionedRectangle);
		if (!buildPlacementRecursively(bounds, tree, placement, leftChild, leftChildPositionedRectangle, horizontalContour,
				newCurrentHorizontalContourElement)) {
			return false;
		}
	}

	//Right child = rectangle to the top
	if (rootNode->hasRightChild()) {
		auto rightChild = rootNode->getRightChild();
		auto rightChildRectangle = tree.getRectangle(rootNode->getRightChild());
		int x = rootPositionedRecangle.getXMin();
		int y = findMinY(horizontalContour, currentHorizontalContourElement, rightChildRectangle->getWidth(), x);
		auto rightChildPositionedRectangle = PositionedRectangle(*rightChildRectangle, x, y);
		placement->add(rightChildPositionedRectangle);
		if (!rightChildPositionedRectangle.getTopRightCoordinates().areWithin(bounds)) {
			return false;
		}
		auto newCurrentHorizontalContourElement = updateContour(horizontalContour, currentHorizontalContourElement, rightChildPositionedRectangle);
		if (!buildPlacementRecursively(bounds, tree, placement, rightChild, rightChildPositionedRectangle, horizontalContour,
				newCurrentHorizontalContourElement)) {
			return false;
		}
	}

	return true;
}

std::shared_ptr<Placement> PlacementFactory::create(const BStarTree& tree) const {
	auto bounds = Rectangle(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
	return createBounded(tree, bounds);
}

std::shared_ptr<Placement> PlacementFactory::createBounded(const BStarTree& tree, const Instance& instanceWithBounds) const {
	Rectangle bounds = instanceWithBounds.getBounds()->getRectangle();
	return createBounded(tree, bounds);
}

//TODO work with bounds that are PositionedRectangles
std::shared_ptr<Placement> PlacementFactory::createBounded(const BStarTree& tree, const Rectangle& bounds) const {
	auto placement = std::shared_ptr<Placement>(new Placement(tree.getSize()));
	auto horizontalContour = std::list<PositionedRectangle>();

	auto rootPositionedRectangle = PositionedRectangle(*tree.getRectangle(tree.getRoot()), 0, 0);

	placement->add(rootPositionedRectangle);
	horizontalContour.push_back(rootPositionedRectangle);

	bool success = buildPlacementRecursively(bounds, tree, placement, tree.getRoot(), rootPositionedRectangle, &horizontalContour,
			horizontalContour.begin());
	if (success) {
		return placement;
	} else {
		return nullptr;
	}
}
}
}

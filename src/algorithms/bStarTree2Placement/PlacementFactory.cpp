#include "PlacementFactory.h"

namespace rechteckpackungen {
namespace bStarTree2Placement {

int PlacementFactory::findMinY(std::list<PositionedRectangle> *horizontalContour,
		std::list<PositionedRectangle>::iterator firstHorizontalContourElementBelowNewElement, int width,
		int xMin) const {
	int y = 0;
	int xMax = xMin + width;
	if (firstHorizontalContourElementBelowNewElement != horizontalContour->end()) {
		y = std::max(y, firstHorizontalContourElementBelowNewElement->getYMax());
		while (firstHorizontalContourElementBelowNewElement != std::prev(horizontalContour->end()) &&
			   firstHorizontalContourElementBelowNewElement->getXMax() < xMax) {
			firstHorizontalContourElementBelowNewElement++;
			y = std::max(y, firstHorizontalContourElementBelowNewElement->getYMax());
		}
	}
	return y;
}

std::list<PositionedRectangle>::iterator PlacementFactory::updateContour(
		std::list<PositionedRectangle> *horizontalContour,
		std::list<PositionedRectangle>::iterator firstHorizontalContourElementBelowNewElement,
		const PositionedRectangle newElement) const {
	auto currentHorizontalContourElementBelowNewElement = firstHorizontalContourElementBelowNewElement;
	while (currentHorizontalContourElementBelowNewElement != horizontalContour->end()
		   && currentHorizontalContourElementBelowNewElement->getXMax() <= newElement.getXMax()) {
		currentHorizontalContourElementBelowNewElement = horizontalContour->erase(
				currentHorizontalContourElementBelowNewElement);
	}
	return horizontalContour->insert(currentHorizontalContourElementBelowNewElement, newElement);
}

bool PlacementFactory::buildPlacementRecursively(const Rectangle &bounds, const BStarTree &tree,
		std::shared_ptr<Placement> placement,
		BTreeNode *rootNode, PositionedRectangle rootPositionedRectangle,
		std::list<PositionedRectangle> *horizontalContour,
		std::list<PositionedRectangle>::iterator currentHorizontalContourElement) const {

	if(placement->getArea() > maxArea){
		return false;
	}

	//Left child = rectangle to the right
	if (rootNode->hasLeftChild()) {
		auto leftChild = rootNode->getLeftChild();
		auto leftChildRectangle = tree.getRectangle(leftChild);
		auto firstHorizontalContourElementBelowNewElement = currentHorizontalContourElement;
		firstHorizontalContourElementBelowNewElement++;
		int x = rootPositionedRectangle.getXMax();
		int y = findMinY(horizontalContour, firstHorizontalContourElementBelowNewElement,
						 leftChildRectangle->getWidth(), x);
		auto leftChildPositionedRectangle = PositionedRectangle(*leftChildRectangle, x, y);
		placement->add(leftChildPositionedRectangle);
		if (!leftChildPositionedRectangle.getTopRightCoordinates().areWithin(bounds)) {
			return false;
		}
		auto newCurrentHorizontalContourElement = updateContour(horizontalContour,
																firstHorizontalContourElementBelowNewElement,
																leftChildPositionedRectangle);
		if (!buildPlacementRecursively(bounds, tree, placement, leftChild, leftChildPositionedRectangle,
									   horizontalContour,
									   newCurrentHorizontalContourElement)) {
			return false;
		}
	}

	//Right child = rectangle to the top
	if (rootNode->hasRightChild()) {
		auto rightChild = rootNode->getRightChild();
		auto rightChildRectangle = tree.getRectangle(rootNode->getRightChild());
		int x = rootPositionedRectangle.getXMin();
		int y = findMinY(horizontalContour, currentHorizontalContourElement, rightChildRectangle->getWidth(), x);
		auto rightChildPositionedRectangle = PositionedRectangle(*rightChildRectangle, x, y);
		placement->add(rightChildPositionedRectangle);
		if (!rightChildPositionedRectangle.getTopRightCoordinates().areWithin(bounds)) {
			return false;
		}
		auto newCurrentHorizontalContourElement = updateContour(horizontalContour, currentHorizontalContourElement,
																rightChildPositionedRectangle);
		if (!buildPlacementRecursively(bounds, tree, placement, rightChild, rightChildPositionedRectangle,
									   horizontalContour, newCurrentHorizontalContourElement)) {
			return false;
		}
	}

	return true;
}

std::shared_ptr<Placement> PlacementFactory::create(const BStarTree &tree) const {
	auto bounds = Rectangle(std::numeric_limits<int>::max(), std::numeric_limits<int>::max());
	return createBounded(tree, bounds);
}

std::shared_ptr<Placement> PlacementFactory::createBounded(const BStarTree &tree,
		const Instance &instanceWithBounds) const {
	return createBounded(tree, *instanceWithBounds.getBounds());
}

std::shared_ptr<Placement> PlacementFactory::createBounded(const BStarTree &tree, const Rectangle &bounds) const {
	auto positionedRectangle = PositionedRectangle(bounds, 0, 0);
	return createBounded(tree, positionedRectangle);
}

std::shared_ptr<Placement> PlacementFactory::createBounded(const BStarTree &tree,
		const PositionedRectangle &bounds) const {
	auto placement = std::shared_ptr<Placement>(new Placement(tree.getSize()));
	auto horizontalContour = std::list<PositionedRectangle>();

	auto rootPositionedRectangle = PositionedRectangle(*tree.getRectangle(tree.getRoot()), 0, 0);

	placement->add(rootPositionedRectangle);
	horizontalContour.push_back(rootPositionedRectangle);

	bool success = buildPlacementRecursively(bounds.getRectangle(), tree, placement, tree.getRoot(),
											 rootPositionedRectangle, &horizontalContour, horizontalContour.begin());
	if (success) {
		placement->shift(bounds.getBottomeLeftCoordinates());
		return placement;
	} else {
		return nullptr;
	}
}

void PlacementFactory::setMaxArea(const int maxArea) {
	this->maxArea = maxArea;
}

}
}

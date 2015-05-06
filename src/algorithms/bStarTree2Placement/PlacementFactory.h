#ifndef SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_
#define SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_

#include "BTree/BStarTree.h"
#include "placement/Placement.h"
#include "placement/Coordinates.h"
#include "instance/Instance.h"
#include <list>
#include <iterator>
#include <math.h>
#include <memory>
#include <limits>

namespace rechteckpackungen {
namespace bStarTree2Placement {

class PlacementFactory {
public:
	std::shared_ptr<Placement> create(const BStarTree& tree) const;
	std::shared_ptr<Placement> createBounded(const BStarTree& tree, const Rectangle& bounds) const;
	std::shared_ptr<Placement> createBounded(const BStarTree& tree, const Instance& instanceWithBounds) const;
	/**
	 * Finds the minimum y-value a new rectangle of specified width can be inserted to at xMin.
	 * currentHorizontalContourElement is the leftmost element in the contour that is below the new rectangle.
	 * If non exists, currentHorizontalContourElement is equal to horizontalContour->end().
	 * Only public for testing.
	 */
	int findMinY(std::list<PositionedRectangle>* horizontalContour,
			std::list<PositionedRectangle>::iterator firstHorizontalContourElementBelowNewElement, int width, int xMin) const;
	std::list<PositionedRectangle>::iterator updateContour(std::list<PositionedRectangle>* horizontalContour,
			std::list<PositionedRectangle>::iterator firstHorizontalContourElementBelowNewElement, const PositionedRectangle newElement) const;
protected:
	bool buildPlacementRecursively(const Rectangle& bounds, const BStarTree& tree, std::shared_ptr<Placement> placement, BTreeNode* rootNode,
			PositionedRectangle rootPositionedRecangle, std::list<PositionedRectangle>* horizontalContour,
			std::list<PositionedRectangle>::iterator currentHorizontalContourElement) const;
};

}
}

#endif /* SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_ */

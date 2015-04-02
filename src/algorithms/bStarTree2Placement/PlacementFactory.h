#ifndef SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_
#define SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"
#include "arrangement/Coordinates.h"
#include <list>
#include <iterator>
#include <math.h>
#include <memory>
#include <limits>

namespace rechteckpackungen {
namespace bStarTree2Placement {

class PlacementFactory {
public:
	std::shared_ptr<Placement> create(BStarTree* tree);
	std::shared_ptr<Placement> createBounded(BStarTree* tree, Rectangle& bounds);
	/**
	 * Finds the minimum y-value a new rectangle of specified width can be inserted to at xMin.
	 * currentHorizontalContourElement is the leftmost element in the contour that is below the new rectangle.
	 * If non exists, currentHorizontalContourElement is equal to horizontalContour->end().
	 */
	int findMinY(std::list<PositionedRectangle*>* horizontalContour,
			std::list<PositionedRectangle*>::iterator firstHorizontalContourElementBelowNewElement, int width, int xMin);
	std::list<PositionedRectangle*>::iterator updateContour(std::list<PositionedRectangle*>* horizontalContour,
			std::list<PositionedRectangle*>::iterator firstHorizontalContourElementBelowNewElement, PositionedRectangle* newElement);
protected:
	bool buildPlacementRecursively(Rectangle& bounds, BStarTree* tree, std::shared_ptr<Placement> placement, BTreeNode* rootNode,
			PositionedRectangle* rootPositionedRecangle, std::list<PositionedRectangle*>* horizontalContour,
			std::list<PositionedRectangle*>::iterator currentHorizontalContourElement);
};

}
}

#endif /* SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_ */

#ifndef SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_
#define SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_

#include "BTree/BStarTree.h"
#include "arrangement/Placement.h"
#include "arrangement/Coordinates.h"
#include <list>
#include <iterator>
#include <math.h>

namespace rechteckpackungen {
namespace bStarTree2Placement {

class PlacementFactory {
public:
	Placement* create(BStarTree* tree);
	/**
	 * Finds the minimum y-value a new rectangle of specified width can be inserted to,
	 * if its xMin has to be equal to (*currentHorizontalContourElement)->getXMax().
	 */
	int findMinY(std::list<PositionedRectangle*>* horizontalContour, std::list<PositionedRectangle*>::iterator currentHorizontalContourElement,
			int width);
	std::list<PositionedRectangle*>::iterator updateContour(std::list<PositionedRectangle*>* horizontalContour,
			std::list<PositionedRectangle*>::iterator firstHorizontalContourElementBelowNewElement, PositionedRectangle* newElement);
protected:
	void buildPlacementRecursively(BStarTree* tree, Placement* placement, BTreeNode* rootNode, PositionedRectangle* rootPositionedRecangle,
			std::list<PositionedRectangle*>* horizontalContour, std::list<PositionedRectangle*>::iterator currentHorizontalContourElement);
};

}
}

#endif /* SRC_ALGORITHMS_BSTARTREE2PLACEMENT_PLACEMENTFACTORY_H_ */

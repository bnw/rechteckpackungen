#include "FindBestPlacementByEnumeration.h"

namespace rechteckpackungen {
namespace findBestPlacement {

/**
 * If a placement is found that optimal (i.e. area of placement = sum of area of rectangles) we stop.
 * This makes the algorithm really fast for instances that have an optimal solution.
 */
Placement::ptr FindBestPlacementByEnumeration::findBest(Instance *instance) {
    auto enumerator = enumerateBStarTrees::Enumerator();
    auto placementFactory = bStarTree2Placement::PlacementFactory();
    Placement::ptr cheapestPlacement = nullptr;
    int areaOfCheapestPlacement = std::numeric_limits<int>::max();
    int theoreticalOptimalArea = instance->getAreaSum();
    Rectangle bounds = instance->getBounds()->getRectangle();
    enumerator.forEachBStarTree(instance->getRectangles(), [&](rechteckpackungen::BStarTree *tree) -> bool {
        auto newPlacement = placementFactory.createBounded(*tree, bounds);
        if (newPlacement == nullptr) {
            return true; //continue
        }
        int newArea = newPlacement->getArea();
        if (newArea < areaOfCheapestPlacement) {
            cheapestPlacement = newPlacement;
            areaOfCheapestPlacement = newArea;
            if (theoreticalOptimalArea == areaOfCheapestPlacement) {
                //Found an optimal solution. We are done.
                return false; //break
            }
        }
        return true; //continue
    });
    return cheapestPlacement;
}

}
}
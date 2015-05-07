#include "FindBestPlacementByEnumeration.h"

namespace rechteckpackungen {
namespace findBestPlacement {

/**
 * If a placement is found that is optimal (i.e. area of placement = sum of area of rectangles) we stop.
 * This makes the algorithm really fast for instances that have an optimal solution.
 */
Placement::ptr FindBestPlacementByEnumeration::findBest(Instance *instance) {
    auto enumerator = enumerateBStarTrees::Enumerator();
    auto placementFactory = bStarTree2Placement::PlacementFactory();
    Placement::ptr cheapestPlacement = nullptr;
    int areaOfCheapestPlacement = std::numeric_limits<int>::max();
    int theoreticalOptimalArea = instance->getAreaSum();
    enumerator.forEachBStarTree(instance->getRectangles(), [&](rechteckpackungen::BStarTree *tree) -> bool {
        auto newPlacement = placementFactory.createBounded(*tree, *instance);
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

#ifndef RECHTECKPACKUNGEN_FINDBESTPLACEMENTBYENUMERATION_H
#define RECHTECKPACKUNGEN_FINDBESTPLACEMENTBYENUMERATION_H

#include "placement/Placement.h"
#include "instance/Instance.h"
#include "writer/PlacementWriter.h"
#include "algorithms/enumerateBStarTrees/Enumerator.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"

namespace rechteckpackungen {
namespace findBestPlacement {

class FindBestPlacementByEnumeration {
public:
    Placement::ptr findBest(Instance *instance);
};

}
}

#endif //RECHTECKPACKUNGEN_FINDBESTPLACEMENTBYENUMERATION_H

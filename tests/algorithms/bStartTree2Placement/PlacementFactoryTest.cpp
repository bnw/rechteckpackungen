#include "cute.h"
#include "PlacementFactoryTest.h"

#include "Rectangle.h"
#include "arrangement/PositionedRectangle.h"
#include "BTree/BStarTree.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"
#include <vector>
#include <list>

namespace rechteckpackungen {

/*
 *      d
 *      d
 *   cccd
 *   cccd
 * abcccde
 */
void testFindYMin() {
	auto factory = bStarTree2Placement::PlacementFactory();
	auto a = new Rectangle(1, 1);
	auto b = new Rectangle(1, 1);
	auto c = new Rectangle(3, 3);
	auto d = new Rectangle(1, 5);
	auto e = new Rectangle(1, 1);
	auto aPositioned = new PositionedRectangle(a, new Coordinates(0, 0));
	auto bPositioned = new PositionedRectangle(b, new Coordinates(1, 0));
	auto cPositioned = new PositionedRectangle(c, new Coordinates(2, 0));
	auto dPositioned = new PositionedRectangle(d, new Coordinates(5, 0));
	auto ePositioned = new PositionedRectangle(e, new Coordinates(6, 0));
	auto rectangles = new std::vector<Rectangle*>();
	rectangles->push_back(a); // index = 0
	rectangles->push_back(b); // index = 1
	rectangles->push_back(c); // index = 2
	rectangles->push_back(d); // index = 3
	rectangles->push_back(e); // index = 4
	auto contour = std::list<PositionedRectangle*>();
	contour.push_back(aPositioned);
	contour.push_back(bPositioned);
	contour.push_back(cPositioned);
	contour.push_back(dPositioned);
	contour.push_back(ePositioned);
	auto tree = BStarTree(rectangles);
	tree.setRoot(tree.at(0));
	tree.setRightChild(tree.at(0), tree.at(1));
	tree.setRightChild(tree.at(1), tree.at(2));
	tree.setRightChild(tree.at(2), tree.at(3));
	tree.setRightChild(tree.at(3), tree.at(4));

	ASSERT_EQUAL(1, factory.findMinY(&contour, contour.begin(), 1));
	ASSERT_EQUAL(3, factory.findMinY(&contour, contour.begin(), 2));
	ASSERT_EQUAL(3, factory.findMinY(&contour, contour.begin(), 4));
	ASSERT_EQUAL(5, factory.findMinY(&contour, contour.begin(), 5));
	ASSERT_EQUAL(5, factory.findMinY(&contour, contour.begin(), 10));
}

/*
 *      d
 * OOO  d
 *   cccd
 *   cccd
 * abcccde
 */
void testUpdateContour1() {
	auto factory = bStarTree2Placement::PlacementFactory();
	auto a = new Rectangle(1, 1);
	auto b = new Rectangle(1, 1);
	auto c = new Rectangle(3, 3);
	auto d = new Rectangle(1, 5);
	auto e = new Rectangle(1, 1);
	auto aPositioned = new PositionedRectangle(a, new Coordinates(0, 0));
	auto bPositioned = new PositionedRectangle(b, new Coordinates(1, 0));
	auto cPositioned = new PositionedRectangle(c, new Coordinates(2, 0));
	auto dPositioned = new PositionedRectangle(d, new Coordinates(5, 0));
	auto ePositioned = new PositionedRectangle(e, new Coordinates(6, 0));
	auto rectangles = new std::vector<Rectangle*>();
	rectangles->push_back(a); // index = 0
	rectangles->push_back(b); // index = 1
	rectangles->push_back(c); // index = 2
	rectangles->push_back(d); // index = 3
	rectangles->push_back(e); // index = 4
	auto contour = new std::list<PositionedRectangle*>();
	contour->push_back(aPositioned);
	contour->push_back(bPositioned);
	contour->push_back(cPositioned);
	contour->push_back(dPositioned);
	contour->push_back(ePositioned);

	auto newRectangle = new PositionedRectangle(0,3,3,4);

	auto result = factory.updateContour(contour, contour->begin(), newRectangle);

	auto iterator = contour->begin();
	ASSERT_EQUAL(result, iterator);
	ASSERT_EQUAL(4, contour->size());
	ASSERT_EQUAL(newRectangle, *iterator++);
	ASSERT_EQUAL(cPositioned, *iterator++);
	ASSERT_EQUAL(dPositioned, *iterator++);
	ASSERT_EQUAL(ePositioned, *iterator++);
}

/*
 *  OOOOOOO
 *      d
 *      d
 *   cccd
 *   cccd
 * abcccde
 */
void testUpdateContour2() {
	auto factory = bStarTree2Placement::PlacementFactory();
	auto a = new Rectangle(1, 1);
	auto b = new Rectangle(1, 1);
	auto c = new Rectangle(3, 3);
	auto d = new Rectangle(1, 5);
	auto e = new Rectangle(1, 1);
	auto aPositioned = new PositionedRectangle(a, new Coordinates(0, 0));
	auto bPositioned = new PositionedRectangle(b, new Coordinates(1, 0));
	auto cPositioned = new PositionedRectangle(c, new Coordinates(2, 0));
	auto dPositioned = new PositionedRectangle(d, new Coordinates(5, 0));
	auto ePositioned = new PositionedRectangle(e, new Coordinates(6, 0));
	auto rectangles = new std::vector<Rectangle*>();
	rectangles->push_back(a); // index = 0
	rectangles->push_back(b); // index = 1
	rectangles->push_back(c); // index = 2
	rectangles->push_back(d); // index = 3
	rectangles->push_back(e); // index = 4
	auto contour = new std::list<PositionedRectangle*>();
	contour->push_back(aPositioned);
	contour->push_back(bPositioned);
	contour->push_back(cPositioned);
	contour->push_back(dPositioned);
	contour->push_back(ePositioned);

	auto newRectangle = new PositionedRectangle(1,8,5,6);

	auto result = factory.updateContour(contour, contour->begin(), newRectangle);

	auto iterator = contour->begin();
	ASSERT_EQUAL(2, contour->size());
	ASSERT_EQUAL(aPositioned, *iterator++);
	ASSERT_EQUAL(result, iterator);
	ASSERT_EQUAL(newRectangle, *iterator++);
}


/**
 * TODO write testUpdateContour3 for:
 *
 * bbOOO
 * aaaa
 */


cute::suite make_suite_PlacementFactoryTest() {
	cute::suite s;
	s.push_back(CUTE(testFindYMin));
	s.push_back(CUTE(testUpdateContour1));
	s.push_back(CUTE(testUpdateContour2));
	return s;
}

}

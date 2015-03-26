#include "cute.h"
#include "PlacementFactoryTest.h"

#include "Rectangle.h"
#include "arrangement/PositionedRectangle.h"
#include "BTree/BStarTree.h"
#include "algorithms/bStarTree2Placement/PlacementFactory.h"
#include <vector>
#include <list>
#include <unordered_set>
#include <memory>

namespace rechteckpackungen {

void assertPlacementsEqual(std::shared_ptr<Placement> expected, std::shared_ptr<Placement> actual) {
	ASSERT_EQUAL(expected->getPositionedRectangles()->size(), actual->getPositionedRectangles()->size());
	for (auto expectedPositionedRectangle : *expected->getPositionedRectangles()) {
		bool foundExpectedPositionedRectangle = false;
		for (auto actualPositionedRectangle : *actual->getPositionedRectangles()) {
			if (*expectedPositionedRectangle == *actualPositionedRectangle) {
				foundExpectedPositionedRectangle = true;
				break;
			}
		}
		ASSERT(foundExpectedPositionedRectangle);
	}
}

/*
 *      d
 *      d
 *   cccd
 *   cccd
 * abcccde
 */
void testFindYMin() {
	auto factory = bStarTree2Placement::PlacementFactory();
	auto a = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto c = std::shared_ptr<Rectangle>(new Rectangle(3, 3));
	auto d = std::shared_ptr<Rectangle>(new Rectangle(1, 5));
	auto e = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto aPositioned = new PositionedRectangle(a, std::shared_ptr<Coordinates>(new Coordinates(0, 0)));
	auto bPositioned = new PositionedRectangle(b, std::shared_ptr<Coordinates>(new Coordinates(1, 0)));
	auto cPositioned = new PositionedRectangle(c, std::shared_ptr<Coordinates>(new Coordinates(2, 0)));
	auto dPositioned = new PositionedRectangle(d, std::shared_ptr<Coordinates>(new Coordinates(5, 0)));
	auto ePositioned = new PositionedRectangle(e, std::shared_ptr<Coordinates>(new Coordinates(6, 0)));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());
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

	ASSERT_EQUAL(1, factory.findMinY(&contour, ++contour.begin(), 1, 1));
	ASSERT_EQUAL(3, factory.findMinY(&contour, ++contour.begin(), 2, 1));
	ASSERT_EQUAL(3, factory.findMinY(&contour, ++contour.begin(), 4, 1));
	ASSERT_EQUAL(5, factory.findMinY(&contour, ++contour.begin(), 5, 1));
	ASSERT_EQUAL(5, factory.findMinY(&contour, ++contour.begin(), 10, 1));
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
	auto a = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto c = std::shared_ptr<Rectangle>(new Rectangle(3, 3));
	auto d = std::shared_ptr<Rectangle>(new Rectangle(1, 5));
	auto e = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto aPositioned = new PositionedRectangle(a, std::shared_ptr<Coordinates>(new Coordinates(0, 0)));
	auto bPositioned = new PositionedRectangle(b, std::shared_ptr<Coordinates>(new Coordinates(1, 0)));
	auto cPositioned = new PositionedRectangle(c, std::shared_ptr<Coordinates>(new Coordinates(2, 0)));
	auto dPositioned = new PositionedRectangle(d, std::shared_ptr<Coordinates>(new Coordinates(5, 0)));
	auto ePositioned = new PositionedRectangle(e, std::shared_ptr<Coordinates>(new Coordinates(6, 0)));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());
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

	auto newRectangle = new PositionedRectangle(0, 3, 3, 4);

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
	auto a = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto c = std::shared_ptr<Rectangle>(new Rectangle(3, 3));
	auto d = std::shared_ptr<Rectangle>(new Rectangle(1, 5));
	auto e = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto aPositioned = new PositionedRectangle(a, std::shared_ptr<Coordinates>(new Coordinates(0, 0)));
	auto bPositioned = new PositionedRectangle(b, std::shared_ptr<Coordinates>(new Coordinates(1, 0)));
	auto cPositioned = new PositionedRectangle(c, std::shared_ptr<Coordinates>(new Coordinates(2, 0)));
	auto dPositioned = new PositionedRectangle(d, std::shared_ptr<Coordinates>(new Coordinates(5, 0)));
	auto ePositioned = new PositionedRectangle(e, std::shared_ptr<Coordinates>(new Coordinates(6, 0)));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());
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

	auto newRectangle = new PositionedRectangle(1, 8, 5, 6);

	auto result = factory.updateContour(contour, ++contour->begin(), newRectangle);

	auto iterator = contour->begin();
	ASSERT_EQUAL(2, contour->size());
	ASSERT_EQUAL(aPositioned, *iterator++);
	ASSERT_EQUAL(newRectangle, *result);
	ASSERT_EQUAL(newRectangle, *iterator);
}

/**
 * bbOOO
 * aaaa
 */
void testUpdateContour3() {
	auto factory = bStarTree2Placement::PlacementFactory();
	auto a = std::shared_ptr<Rectangle>(new Rectangle(4, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(2, 1));
	auto aPositioned = new PositionedRectangle(a, std::shared_ptr<Coordinates>(new Coordinates(0, 0)));
	auto bPositioned = new PositionedRectangle(b, std::shared_ptr<Coordinates>(new Coordinates(0, 1)));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());
	rectangles->push_back(a); // index = 0
	rectangles->push_back(b); // index = 1
	auto contour = new std::list<PositionedRectangle*>();
	contour->push_back(bPositioned);
	contour->push_back(aPositioned);

	auto newRectangle = new PositionedRectangle(3, 6, 1, 2);

	auto result = factory.updateContour(contour, ++contour->begin(), newRectangle);

	auto iterator = contour->begin();
	ASSERT_EQUAL(2, contour->size());
	ASSERT_EQUAL(bPositioned, *iterator++);
	ASSERT_EQUAL(newRectangle, *iterator);
}

/*
 *      d
 *      d
 *   cccd
 *   cccd
 * abcccde
 */
void testCreateHorizontal() {
	auto factory = bStarTree2Placement::PlacementFactory();

	auto a = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto c = std::shared_ptr<Rectangle>(new Rectangle(3, 3));
	auto d = std::shared_ptr<Rectangle>(new Rectangle(1, 5));
	auto e = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto aPositionedExpected = new PositionedRectangle(a, std::shared_ptr<Coordinates>(new Coordinates(0, 0)));
	auto bPositionedExpected = new PositionedRectangle(b, std::shared_ptr<Coordinates>(new Coordinates(1, 0)));
	auto cPositionedExpected = new PositionedRectangle(c, std::shared_ptr<Coordinates>(new Coordinates(2, 0)));
	auto dPositionedExpected = new PositionedRectangle(d, std::shared_ptr<Coordinates>(new Coordinates(5, 0)));
	auto ePositionedExpected = new PositionedRectangle(e, std::shared_ptr<Coordinates>(new Coordinates(6, 0)));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());

	rectangles->push_back(a); // index = 0
	rectangles->push_back(b); // index = 1
	rectangles->push_back(c); // index = 2
	rectangles->push_back(d); // index = 3
	rectangles->push_back(e); // index = 4
	auto tree = BStarTree(rectangles);
	tree.setRoot(tree.at(0));
	tree.setLeftChild(tree.at(0), tree.at(1));
	tree.setLeftChild(tree.at(1), tree.at(2));
	tree.setLeftChild(tree.at(2), tree.at(3));
	tree.setLeftChild(tree.at(3), tree.at(4));

	auto expected = std::shared_ptr<Placement>(new Placement());
	expected->add(aPositionedExpected);
	expected->add(bPositionedExpected);
	expected->add(cPositionedExpected);
	expected->add(dPositionedExpected);
	expected->add(ePositionedExpected);

	auto result = factory.create(&tree);

	assertPlacementsEqual(expected, result);
}

/*
 *     gd
 *  fffgd
 *   cccdhh
 *   cccdhh
 * abcccde
 */
void testCreateComplete() {
	auto factory = bStarTree2Placement::PlacementFactory();
	auto a = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto b = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto c = std::shared_ptr<Rectangle>(new Rectangle(3, 3));
	auto d = std::shared_ptr<Rectangle>(new Rectangle(1, 5));
	auto e = std::shared_ptr<Rectangle>(new Rectangle(1, 1));
	auto f = std::shared_ptr<Rectangle>(new Rectangle(3, 1));
	auto g = std::shared_ptr<Rectangle>(new Rectangle(1, 2));
	auto h = std::shared_ptr<Rectangle>(new Rectangle(1, 2));
	auto rectangles = std::shared_ptr<std::vector<std::shared_ptr<Rectangle>>>(new std::vector<std::shared_ptr<Rectangle>>());
	rectangles->push_back(a); // index = 0
	rectangles->push_back(b); // index = 1
	rectangles->push_back(c); // index = 2
	rectangles->push_back(d); // index = 3
	rectangles->push_back(e); // index = 4
	rectangles->push_back(f); // index = 5
	rectangles->push_back(g); // index = 6
	rectangles->push_back(h); // index = 7
	auto aPositionedExpected = new PositionedRectangle(a, std::shared_ptr<Coordinates>(new Coordinates(0, 0)));
	auto bPositionedExpected = new PositionedRectangle(b, std::shared_ptr<Coordinates>(new Coordinates(1, 0)));
	auto cPositionedExpected = new PositionedRectangle(c, std::shared_ptr<Coordinates>(new Coordinates(2, 0)));
	auto dPositionedExpected = new PositionedRectangle(d, std::shared_ptr<Coordinates>(new Coordinates(5, 0)));
	auto ePositionedExpected = new PositionedRectangle(e, std::shared_ptr<Coordinates>(new Coordinates(6, 0)));
	auto fPositionedExpected = new PositionedRectangle(f, std::shared_ptr<Coordinates>(new Coordinates(1, 3)));
	auto gPositionedExpected = new PositionedRectangle(g, std::shared_ptr<Coordinates>(new Coordinates(4, 3)));
	auto hPositionedExpected = new PositionedRectangle(h, std::shared_ptr<Coordinates>(new Coordinates(6, 1)));
	auto tree = BStarTree(rectangles);
	tree.setRoot(tree.at(0));
	tree.setLeftChild(tree.at(0), tree.at(1));
	tree.setLeftChild(tree.at(1), tree.at(2));
	tree.setLeftChild(tree.at(2), tree.at(3));
	tree.setLeftChild(tree.at(3), tree.at(4));
	tree.setRightChild(tree.at(1), tree.at(5));
	tree.setLeftChild(tree.at(5), tree.at(6));
	tree.setRightChild(tree.at(4), tree.at(7));

	auto expected = std::shared_ptr<Placement>(new Placement());
	expected->add(aPositionedExpected);
	expected->add(bPositionedExpected);
	expected->add(cPositionedExpected);
	expected->add(dPositionedExpected);
	expected->add(ePositionedExpected);
	expected->add(fPositionedExpected);
	expected->add(gPositionedExpected);
	expected->add(hPositionedExpected);

	auto result = factory.create(&tree);

	assertPlacementsEqual(expected, result);
}

cute::suite make_suite_PlacementFactoryTest() {
	cute::suite s;
	s.push_back(CUTE(testFindYMin));
	s.push_back(CUTE(testUpdateContour1));
	s.push_back(CUTE(testUpdateContour2));
	s.push_back(CUTE(testUpdateContour3));
	s.push_back(CUTE(testCreateHorizontal));
	s.push_back(CUTE(testCreateComplete));
	return s;
}

}

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../../../../GitHub/C-Data-structures/Binary Search Tree/binSearchTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinarySearchTree
{
	TEST_CLASS(BinarySearchTreeUnitTest)
	{
	public:
        BinSearchTree tree;

        BinarySearchTreeUnitTest() {
            // Empty Constructor
        }

        TEST_METHOD_INITIALIZE(InitializeTree) {
            tree.insert(10);
            tree.insert(5);
            tree.insert(8);
            tree.insert(6);
            tree.insert(7);
            tree.insert(16);
            tree.insert(20);
            tree.insert(14);
            tree.insert(15);
            tree.insert(5);
            tree.insert(2);
            tree.insert(4);
            tree.insert(1);
            tree.insert(12);
            tree.insert(13);
        }
		
		TEST_METHOD(Test_LeastCommonAncestor) {
			// TODO: Your test code here
            int actual = tree.LCA(13, 7);
            int expected = 10;
            Assert::AreEqual(actual, expected);
        }

        TEST_METHOD(Test_TreeIsNotWellFormed) {
            bool actual = tree.WellFormed();
            bool expected = false;
            Assert::AreEqual(actual, expected);
        }

        /*BEGIN_TEST_METHOD_ATTRIBUTE(Test_RemoveRoot)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()*/
        TEST_METHOD(Test_RemoveRoot) {
            tree.removeItem(10);
            bool actual = tree.lookup(10);
            Assert::IsFalse(actual);
        }

        /*BEGIN_TEST_METHOD_ATTRIBUTE(Test_Remove2Node)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()*/
        TEST_METHOD(Test_Remove2Node) {
            tree.removeItem(10);
            tree.removeItem(16);
            bool actual = tree.lookup(16);
            tree.BFSPrint(cout);
            Assert::IsFalse(actual);
        }

        /*BEGIN_TEST_METHOD_ATTRIBUTE(Test_TreeIsNotWellFormed2)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()*/
        TEST_METHOD(Test_TreeIsNotWellFormed2) {
            tree.removeItem(10);
            tree.removeItem(16);
            tree.removeItem(6);
            tree.removeItem(15);
            tree.removeItem(8);
            tree.removeItem(5);
            bool actual = tree.WellFormed();
            Assert::IsFalse(actual);
        }

        TEST_METHOD(Test_FindMinimum1) {
            BinSearchTree tree2;

            tree2.insert(10);
            tree2.insert(14);
            Assert::AreEqual(tree2.min(), 10);
        }

        TEST_METHOD(Test_FindMinimum2) {
            Assert::AreEqual(tree.min(), 1);
        }

        TEST_METHOD(Test_DeleteMinimum1) {
            tree.deleteMin();
            Assert::IsFalse(tree.lookup(1));
        }

        TEST_METHOD(Test_DeleteMinimum2) {
            BinSearchTree tree2;
            tree2.insert(10);
            tree2.insert(5);
            tree2.insert(8);
            tree2.insert(6);
            tree2.insert(7);
            tree2.insert(16);
            tree2.insert(20);
            tree2.insert(14);
            tree2.insert(15);
            tree2.insert(2);
            tree2.insert(4);
            tree2.deleteMin();
            Assert::IsFalse(tree2.lookup(2));
            Assert::IsTrue(tree2.lookup(4));
        }

        /*BEGIN_TEST_METHOD_ATTRIBUTE(Test_SimpleCompleteDeletion1)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()*/

        TEST_METHOD(Test_SimpleCompleteDeletion1) {
            BinSearchTree tree2;

            tree2.insert(10);
            tree2.removeItem(10);
            Assert::IsTrue(tree2.isEmpty());
        }

        /*BEGIN_TEST_METHOD_ATTRIBUTE(Test_SimpleCompleteDeletion2)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()*/

        TEST_METHOD(Test_SimpleCompleteDeletion2) {
            BinSearchTree tree2;

            tree2.insert(13);
            tree2.insert(14);
            tree2.removeItem(13);
            tree2.removeItem(14);
            Assert::IsTrue(tree2.isEmpty());
        }

        /*BEGIN_TEST_METHOD_ATTRIBUTE(Test_ComplexCompleteDeletion1)
            TEST_IGNORE()
        END_TEST_METHOD_ATTRIBUTE()*/

        TEST_METHOD(Test_ComplexCompleteDeletion1) {
            tree.removeItem(10);
            tree.removeItem(16);
            tree.removeItem(6);
            tree.removeItem(15);
            tree.removeItem(8);
            tree.removeItem(5);
            tree.removeItem(12);
            tree.removeItem(20);
            tree.removeItem(2);
            tree.removeItem(1);
            tree.removeItem(7);
            tree.removeItem(4);
            tree.removeItem(13);
            tree.removeItem(14);

            Assert::IsTrue(tree.isEmpty());
        }
	};
}
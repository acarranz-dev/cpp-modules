#include <iostream>
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"
#include "set.hpp"

int main() {
    std::cout << "=== Testing SearchableArrayBag ===" << std::endl;
    SearchableArrayBag<int> arrayBag;
    
    // Add items (including duplicates)
    arrayBag.add(5);
    arrayBag.add(2);
    arrayBag.add(8);
    arrayBag.add(2);
    arrayBag.add(5);
    arrayBag.add(9);
    
    std::cout << "ArrayBag size: " << arrayBag.size() << std::endl;
    arrayBag.display();
    
    // Test search
    int* found = arrayBag.search(2);
    if (found) {
        std::cout << "Found: " << *found << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    int* notFound = arrayBag.search(100);
    if (notFound) {
        std::cout << "Found: " << *notFound << std::endl;
    } else {
        std::cout << "100 not found (as expected)" << std::endl;
    }
    
    std::cout << "\n=== Testing SearchableTreeBag ===" << std::endl;
    SearchableTreeBag<int> treeBag;
    
    // Add items (including duplicates)
    treeBag.add(5);
    treeBag.add(2);
    treeBag.add(8);
    treeBag.add(2);
    treeBag.add(5);
    treeBag.add(9);
    
    std::cout << "TreeBag size: " << treeBag.size() << std::endl;
    treeBag.display();
    
    // Test search
    found = treeBag.search(8);
    if (found) {
        std::cout << "Found: " << *found << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
    
    std::cout << "\n=== Testing Set with ArrayBag ===" << std::endl;
    Set<int> arraySet(new SearchableArrayBag<int>());
    
    // Add items (duplicates should be ignored)
    arraySet.insert(5);
    arraySet.insert(2);
    arraySet.insert(8);
    arraySet.insert(2);  // Duplicate, should not be added
    arraySet.insert(5);  // Duplicate, should not be added
    arraySet.insert(9);
    
    std::cout << "Set size: " << arraySet.size() << " (should be 4)" << std::endl;
    arraySet.display();
    
    std::cout << "Contains 2: " << (arraySet.contains(2) ? "yes" : "no") << std::endl;
    std::cout << "Contains 100: " << (arraySet.contains(100) ? "yes" : "no") << std::endl;
    
    std::cout << "\n=== Testing Set with TreeBag ===" << std::endl;
    Set<int> treeSet(new SearchableTreeBag<int>());
    
    // Add items (duplicates should be ignored)
    treeSet.insert(5);
    treeSet.insert(2);
    treeSet.insert(8);
    treeSet.insert(2);  // Duplicate, should not be added
    treeSet.insert(5);  // Duplicate, should not be added
    treeSet.insert(9);
    
    std::cout << "Set size: " << treeSet.size() << " (should be 4)" << std::endl;
    treeSet.display();
    
    // Test copy constructor
    std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
    Set<int> copySet(treeSet);
    std::cout << "Copy set size: " << copySet.size() << std::endl;
    copySet.display();
    
    // Test assignment operator
    std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
    Set<int> assignSet(new SearchableArrayBag<int>());
    assignSet = copySet;
    std::cout << "Assigned set size: " << assignSet.size() << std::endl;
    assignSet.display();
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}

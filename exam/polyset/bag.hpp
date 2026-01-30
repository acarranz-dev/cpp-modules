#ifndef BAG_HPP
#define BAG_HPP

template <typename T>
class Bag {
public:
    virtual ~Bag() {}
    
    // Add an item to the bag
    virtual void add(const T& item) = 0;
    
    // Remove an item from the bag
    virtual void remove(const T& item) = 0;
    
    // Check if the bag contains an item
    virtual bool contains(const T& item) const = 0;
    
    // Get the number of items in the bag
    virtual int size() const = 0;
    
    // Check if the bag is empty
    virtual bool isEmpty() const = 0;
    
    // Clear all items from the bag
    virtual void clear() = 0;
};

#endif

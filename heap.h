#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int m_;
  PComparator comp_; 
  std::vector<T> heap_;
};

// Add implementation of member functions here

// constructor
template <typename T, typename Comparator>
Heap<T,Comparator>::Heap(int m, Comparator c) : m_(m), comp_(c), heap_() {}

// destructor
template <typename T, typename Comparator>
Heap<T, Comparator>::~Heap(){}

template <typename T, typename Comparator>
bool Heap<T, Comparator>::empty() const { return heap_.size() < 1; }


template <typename T, typename Comparator>
void Heap<T,Comparator>::push(const T& item) {
  
  // add to back
  heap_.push_back(item);
  
  // heapify up the heap
  int i = heap_.size() - 1;

  while(i > 0){
    int parent = (i - 1) / m_;
    
    // check heap condition
    if(comp_(heap_[i], heap_[parent])){ 
      std::swap(heap_[i], heap_[parent]);
      i = parent;
    } else {
      break;
    }
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty (top)");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_.front();
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty (pop)");
  }
  
  // swap front and back, pop back
  std::swap(heap_.front(), heap_.back());
  heap_.pop_back();

  // heapify down
  int i = 0;
  while(i < heap_.size()){
    
    // find bestChild
    int bestChild = m_ * i + 1;
    // if no more children, break
    if(bestChild >= heap_.size()){
      break;
    }


    for (size_t j = 2; j <= m_; j++){
      int childId = m_ * i + j;
      // check if better than bestChild
      if(childId < heap_.size() && comp_(heap_[childId], heap_[bestChild])){
        bestChild = childId;
      }
    }

    // with best child, now swap if child is better
    // check if better than bestChild
    if(comp_(heap_[i], heap_[bestChild])){
      std::swap(heap_[i], heap_[bestChild]);
      i = bestChild;
    } else {
      break;
    }
  }
}

#endif


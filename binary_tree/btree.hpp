#ifndef __ED_BTree_HPP__
#define __ED_BTree_HPP__

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <sstream>

/** @brief a BTree's Node.*/
template <class T>
class BTNode
{
public:

    /** @brief Define a shared reference to a BTNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< BTNode<T> > Ref;

    /** @name Life cicle.*/
    /** @{*/

    /** @brief Create a BTNode.
     * @post n_children() == 0
     */
    BTNode (T const& it=T(), BTNode<T>::Ref left=nullptr, BTNode<T>::Ref right=nullptr)
    {
        //TODO
        item_ = it;
        left_ = left;
        right_ = right;
    }

    /**
     * @brief Create a BTNode using dynamic memory.
     * @param it the value save in the node.
     * @param left links to the left child.
     * @param right links to the right child.
     * @return a shared referente to the new node.
     */
    static typename BTNode<T>::Ref create(T const& it, BTNode<T>::Ref left=nullptr, BTNode<T>::Ref right=nullptr)
    {
        return std::make_shared<BTNode<T>> (it, left, right);
    }

    

    /** @brief Destroy a BTNode. **/
    ~BTNode()
    {}

    /** @}*/

    /** @name Observers.*/
    /** @{*/

    /** @brief Get the data item.*/
    const T& item() const
    {
        //TODO
        return item_;
    }

    /** @brief Has it a left child?*/
    bool has_left() const
    {
        //TODO
        if (left_ == nullptr) return false;
        else return true;
    }

    /** @brief get the left child.*/
    BTNode<T>::Ref left() const
    {
        //TODO
        return left_;
    }

    /** @brief Has it a right child? */
    bool has_right() const
    {
        //TODO
        if (right_ == nullptr) return false;
        else return true;
    }

    /** @brief get the right child.*/
    BTNode<T>::Ref right() const
    {
        //TODO
        return right_;
    }
    /** @}*/

    /** @name Modifiers.*/
    /** @{*/

    /** @brief Set the data item.*/
    void set_item(const T& new_it)
    {
        //TODO
        item_ = new_it;
    }

    /** @brief Set the left child.*/
    void set_left(BTNode<T>::Ref new_child)
    {
        //TODO
        left_ = new_child;
    }

    /** @brief Remove link to the left child. */
    void remove_left()
    {
        //TODO: hint see std::share_ptr doc.
        left_ = nullptr;
    }

    /** @brief Set the right child.*/
    void set_right(BTNode<T>::Ref new_child)
    {
        //TODO
        right_ = new_child;
    }

    /** @brief Remove linkt to the right child. */
    void remove_right()
    {
        //TODO: hint see std::share_ptr doc.
        right_ = nullptr;
    }

protected:
    //TODO
    //Hint: use typename SNode<T>::Ref for the link to other nodes.
    T item_;
    BTNode<T>::Ref left_, right_;
};

/**
 * @brief ADT BTree.
 * Models a BTree of T.
 */
template<class T>
class BTree
{
  public:

    /** @brief Define a shared reference to a BTNode.
     * Manages the storage of a pointer, providing a limited garbage-collection
     * facility, possibly sharing that management with other objects.
     * @see http://www.cplusplus.com/reference/memory/shared_ptr/
     */
    typedef std::shared_ptr< BTree<T> > Ref;

  /** @name Life cicle.*/
  /** @{*/

    /** @brief Create an empty BTree.
     * @post is_empty()
     */
    BTree ()
    {
        //TODO
        root_ = nullptr;
        assert(is_empty());
    }

  /** @brief Create Leaf BTree.
   * @post not is_empty()
   */
  BTree (const T& item)
  {
      //TODO
      root_ = BTNode<T>::create(item);
  }

  /**
   * @brief Create an empty BTree.
   * @return a shared referente to the new tree.
   */
  static typename BTree<T>::Ref create()
  {
      return std::make_shared<BTree<T>> ();
  }

  /**
   * @brief Create a leaf BTree.
   * @param item is the root's item.
   * @return a shared referente to the new tree.
   */
  static typename BTree<T>::Ref create(T const& item)
  {
      return std::make_shared<BTree<T>>(item);
  }

  /**
   * @brief Load a tree from a input stream.
   *
   * The input format will be:
   * '[]' for the empty tree.
   * '[ <item> <left-subtree> <right-subtree> ']'
   *
   * For example a tree with three nodes:
   * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
   *
   * @return a reference to the tree created.
   * @warning runtime_error will throw if worng input format was found.
   */
  static typename BTree<T>::Ref create (std::istream& in) noexcept(false)
  {
      std::string token;
      in >> token;

      auto tree = BTree<T>::create();

      if (!in)
      {
              throw std::runtime_error("Wrong input format.");
      }

      //TODO

      char aux;
      T item;
      
      if (token == "[]") { 
        return tree;
      }

        if (!in){ throw std::runtime_error("Wrong input format.");}

        in>>token;
        std::istringstream translater(token);


        
        translater >> item;
        tree->create_root(item);

        if (!in){ throw std::runtime_error("Wrong input format."); }

        auto left_tree = BTree<T>::create(in);
        tree->set_left(left_tree);

        auto right_tree = BTree<T>::create(in);
        tree->set_right(right_tree);


        in>>aux;
        return tree;

      }


  /** @brief Destroy a BTree.**/
  ~BTree()
  {}

  /** @}*/

  /** @name Observers*/

  /** @{*/

  /** @brief is the list empty?.*/
  bool is_empty () const
  {
      //TODO
      if (root_ == nullptr) return true;
      else return false;
  }

  /** @brief Get the root item.
   * @pre not is_empty();
   */
  T const& item() const
  {
      assert(!is_empty());
      //TODO
      return root_->item();
  }

  /**
   * @brief Get the left subtree.
   * @return a reference to the left subtree.
   * @pre !is_empty()
   */
  typename BTree<T>::Ref left() const
  {
      assert(!is_empty());
      //BTree<T>::Ref l_subtree;
      auto l_subtree = BTree<T>::create();


      //TODO
 
          l_subtree->root_ = root_->left();
          return l_subtree;
      
      //

      
  }

  /**
   * @brief Get the right subtree.
   * @return a reference to the right subtree.
   * @pre !is_empty()   
   */
  typename BTree<T>::Ref right() const
  {
      assert(!is_empty());
      //BTree<T>::Ref r_subtree;
      auto r_subtree = BTree<T>::create();

      //TODO

          r_subtree->root_ = root_->right();
          return r_subtree;
  
      //
  }

  /**
   * @brief Fold a binary tree.
   *
   * The output format will be:
   * '[]' for the empty tree.
   * '[ <item> <left-subtree> <right-subtree> ']'
   *
   * For example a tree with three nodes:
   * "[ 2 [ 1 [] [] ] [ 3 [] [] ] ]"
   *
   * @param out is the output stream.
   * @param tree is the tree.
   * @return the output stream.
   * @pre tree!=nullptr
   */
  std::ostream& fold(std::ostream& out) const
  {

      if(is_empty()){ out << "[]";}

      else{

          out<<"[ ";
          out<< root_->item();
          out<<" ";
          auto l_tree = BTree<T>::left();
          auto r_tree = BTree<T>::right();

          l_tree->fold(out); 
          out<<" ";
          r_tree->fold(out);
          out<<" ]";
      }
  }

  /** @}*/

  /** @name Modifiers*/

  /** @{*/

  /**
   * @brief set the roor's item.
   * @pre not is_empty()
   */
  void set_item(const T& new_it)
  {
      assert(!is_empty());
      //TODO
      root_->set_item(new_it);
  }

  /**
   * @brief Create the root node.
   * item is the new root item.
   * @post !is_empty()
   */
  void create_root(T const& item)
  {
      //TODO
      
      root_ = BTNode<T>::create(item);
      assert(!is_empty());
  }

  /**
   * @brief Remove the link to the root node.
   * @post is_empty()
   */
  void remove_root()
  {
      //TODO
      assert(is_empty());
      root_ = nullptr;
  }

  /**
   * @brief Attach a new subtree as left child of root.
   * @param new_left is the new left subtree.
   * @pre !is_empty()
   */
  void set_left(typename BTree<T>::Ref new_left)
  {
      assert(!is_empty());
      //TODO
      root_->set_left(new_left->root_);
    

      
  }

  /**
   * @brief Detach the left child of root.
   * @pre !is_empty()
   */
  void remove_left()
  {
      assert(!is_empty());
      //TODO
      root_->set_left(nullptr);
  }

  /**
   * @brief Attach a new subtree as right child of root.
   * @param t is the new right subtree.
   */
  void set_right(typename BTree<T>::Ref t)
  {
      assert(!is_empty());
      //TODO
      root_->set_right(t->root_);
  }

  /**
   * @brief Detach the right child of root.
   * @pre !is_empty()
   */
  void remove_right()
  {
      assert(!is_empty());
      //TODO
      root_->set_right(nullptr);
  }

  /** @}*/

protected:

  //TODO
  typename BTNode<T>::Ref root_;


};
#endif

#ifndef __ED_BTree_Utils_HPP__
#define __ED_BTree_Utils_HPP__

#include <cassert>
#include <exception>
#include <memory>
#include <iostream>
#include <queue>

#include "btree.hpp"

/**
 * @brief Compute the height of a tree.
 * The tree's height is the longitude of the longest branch connecting the root
 * node with a leaf node, or -1 if the tree was empty.
 *
 * @param t is the tree.
 * @return the tree's height or -1 if it is a empty tree.
 * @pre t!=nullptr
 */
template<class T>
int compute_height (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    int ret_val = 0;

    //TODO
    int left, right;

    if (t->is_empty())
    {
        return -1;

    }
    else
    {
        left = compute_height<T>(t->left());
        right = compute_height<T>(t->right());

        if(left>right){
            ret_val = left+1;
            return ret_val;
        }

        else{
            ret_val = right+1;
            return ret_val;
        }
    }


}

/**
 * @brief Compute the number of nodes in the tree.
 *
 * @param t is the tree.
 * @return the number of nodes in the tree.
 * @pre t!=nullptr
 * @post t->is_empty() and ret_val==0
 * @post !t->is_empty() and ret_val>0
 */
template<class T>
size_t compute_size (typename BTree<T>::Ref t)
{
    assert(t != nullptr);
    size_t ret_val = 0;
    typename BTree<T>::Ref l_tree;
    typename BTree<T>::Ref r_tree;


    //TODO
    if(t->is_empty()){ return 0; }

    else{
        l_tree = t->left();
        r_tree = t->right();
        ret_val++;

        if(!l_tree->is_empty()){
            ret_val = ret_val + compute_size<T>(l_tree);
        }

        if(!r_tree->is_empty()){
            ret_val = ret_val + compute_size<T>(r_tree);
        }
    }

    assert(!t->is_empty() || ret_val==0);
    assert(t->is_empty() || ret_val>0);
    return ret_val;
}

/**
 * @brief Prefix processing of a binary tree
 * The template class Processor must have an closure interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree!=nullptr
 */
template <class T, typename Processor>
bool
prefix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;

    //TODO
    if (!tree->is_empty())
    {
        retVal = p(tree->item());
        retVal = retVal * prefix_process<T>(tree->left(), p);
        retVal = retVal * prefix_process<T>(tree->right(), p);

    }
    return retVal;
}

/**
 * @brief Infix processing of a binary tree.
 * The template class Processor must have an apply interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree!=nullptr
 */
template <class T, class Processor>
bool
infix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;

    //TODO
    if (!tree->is_empty())
    {
        
        retVal = infix_process<T>(tree->left(), p);
        retVal = retVal * p(tree->item());
        retVal = retVal * infix_process<T>(tree->right(), p);
    }
    return retVal;
}

/**
 * @brief Postfix processing of a binary tree.
 * The template class Processor must have an apply interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree!=nullptr
 */
template <class T, class Processor>
bool
postfix_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool retVal = true;

    //TODO
    if (!tree->is_empty())
    {
        
        retVal = postfix_process<T>(tree->left(), p);
        retVal = retVal * postfix_process<T>(tree->right(), p);
        retVal = retVal * p(tree->item());

    }

    return retVal;
}


/**
 * @brief Bread-first processing of a btree.
 * The template class Processor must have an apply interface:
 *
 * bool Processor::operator()(T const& item).
 *
 * that makes something with item and returning true when the processing must
 * continue or false to stop it.
 *
 * A lambda expression can be used too.
 *
 * @return true if all nodes were processed.
 * @pre tree!=nullptr
 */
template <class T, class Processor>
bool
breadth_first_process(typename BTree<T>::Ref tree, Processor& p)
{
    assert(tree != nullptr);
    bool ret_val = true;
    typename BTree<T>::Ref aux;

    //TODO
    //Hint: may be you need to use std::queue

    std::queue<typename BTree<T>::Ref> _cola;


    _cola.push(tree);

    while(!_cola.empty() && ret_val){
        aux = _cola.front();

        if(!aux->is_empty()){
            ret_val = p(aux->item());
            _cola.push(aux->left());
            _cola.push(aux->right());
        }

        _cola.pop();
    }

    return ret_val;
}

/**
 * @brief Check is a binary tree is in order.
 * A binary tree is in order whether it is the empty tree or
 * when for each subtree, the root node is greater than all its proper left
 * descendants and less than all its proper right descendants.
 *
 * @param tree is the tree to be checked.
 * @return true if the input tree is in order.
 */

template<class T>
int minValue(typename BTree<T>::Ref const& tree){

    T res;

    if (tree->is_empty())

        return 99999;
  
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    res = tree->item();
    T lres = minValue<T>(tree->left());
    T rres = minValue<T>(tree->right());
    if (lres < res)
        res = lres;
    if (rres < res)
        res = rres;

    return res;

}

template<class T>
int maxValue(typename BTree<T>::Ref const& tree){

   if (tree->is_empty())

        return -99999;
  
    T res = tree->item();
    T lres = maxValue<T>(tree->left());
    T rres = maxValue<T>(tree->right());
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;

    return res;

}

template<class T>
bool check_btree_in_order(typename BTree<T>::Ref const& tree)
{
    bool ret_val = true;
    //T aux;

    //TODO
    if (tree->is_empty())
    {
        return true;

    }



    if (tree->right()->is_empty() == false && minValue<T>(tree->right()) < tree->item()){

        return false;

    }
    
    if (tree->left()->is_empty() == false && maxValue<T>(tree->left()) > tree->item())
    {
        return false;
    }

    if (check_btree_in_order<T>(tree->left()) == false || check_btree_in_order<T>(tree->right()) == false){

        return false;

    }
   

    return true;
}

/**
 * @brief Search a item into the tree.
 *
 * The input tree must be in order, a optimized search process can be used.
 *
 * @param tree is a in order binary tree.
 * @param v is the value to be found.
 * @pre check_btree_in_order(tree)
 * @return true if the value is in the tree.
 */
template<class T>
bool has_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));
    bool ret_val = true;

    //TODO
    if(tree->is_empty()){
        return false;
    }

    else{
        if(v > tree->item()){
            return has_in_order<T>(tree->right(), v);
        }

        else if(v < tree->item()){
            return has_in_order<T>(tree->left(), v);
        }
    }


    //

    return ret_val;
}

/**
 * @brief Insert in orde a value intro a binary tree.
 * @see check_btree_in_order to know what is mean this.
 * If the value is already in tree, nothing is inserted.
 *
 * @param tree is the tree where inserting.
 * @param v is the value to be inserted.
 *
 * @pre check_btree_in_order(tree)
 * @post has_in_order(tree, v)
 */
template <class T>
void insert_in_order(typename BTree<T>::Ref tree, T const& v)
{
    assert(check_btree_in_order<T>(tree));

    //TODO
   if(tree->is_empty()){
       tree->create_root(v);
   }

   else if(v < tree->item()){
       if(tree->left()->is_empty()){
           tree->set_left(BTree<T>::create(v));
       }

       else{
           insert_in_order<T>(tree->left(), v);
       }
   }

   else if( v > tree->item() ){
       if(tree->right()->is_empty()){
           tree->set_right(BTree<T>::create(v));
       }

       else{
           insert_in_order<T>(tree->right(), v);
       }
   }
    assert(has_in_order<T>(tree, v));
}



#endif

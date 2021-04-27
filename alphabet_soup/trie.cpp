#include <cassert>
#include "trie.hpp"

#ifdef assert
//We undefined this macro to not shadow our implementation of assert.
#undef assert
#endif

/**
 * @brief Check an assertion.
 * In Debug mode, if the assertion is not met, a segfault is generated.
 * @param assertion
 */
inline void assert(bool assertion)
{
#ifndef NDEBUG
    (void)((assertion) || (__assert ("Assert violation!", __FILE__, __LINE__),0));
#endif
}


TrieNode::TrieNode ()
{
    //TODO
    //Hint: Do you need to do something?
};

TrieNode::Ref TrieNode::create()
{
    return std::make_shared<TrieNode>();
}

bool
TrieNode::has(char k) const
{
    bool ret_v = false;
    //TODO
    if( children_.find(k) != children_.end()) ret_v = true;

    //
    return ret_v;
}

TrieNode::Ref
TrieNode::child(char k) const
{
    assert(has(k));
    TrieNode::Ref ret_v;
    //TODO

    //
    return ret_v;
}

std::string const&
TrieNode::value() const
{
    return value_;
}

const std::map<char, TrieNode::Ref> &TrieNode::children() const
{
    return children_;
}

void
TrieNode::set_value(std::string const& new_v)
{
    value_ = new_v;
}

void
TrieNode::insert(char k, Ref node)
{
    //TODO

    //
}

Trie::Trie()
{
    //TODO
    //Hint: Do you need to do something?
}

Trie::Ref Trie::create()
{
    return std::make_shared<Trie>();
}

TrieNode::Ref Trie::root() const
{
    //TODO
    return root_;
    //
}

bool
Trie::has(std::string const& k) const
{
    bool found = false;
    //TODO
    //Remember: The Trie can have a prefix==k but does not store the key k.
    auto aux = TrieNode::create();

    aux = find_node(k);
    found = (aux != nullptr) and (aux->value() == k);
    //
    return found;
}

std::vector<std::string>
Trie::keys(std::string const& pref) const
{
    std::vector<std::string> keys;
    //TODO

    //
    return keys;
}


void
Trie::insert(std::string const& k)
{
    //TODO
    if (root_ == nullptr){
        root_ = TrieNode::create();
    }

    auto node = root_;

    for(int i = 0; i< k.size(); i++){
        if(node->has(k[i])){
            node = node->child(k[i]);
        }

        else{
            auto newNode = TrieNode::create();
            node->insert(k[i], newNode);
            node = newNode;
        }   
    }

    node->set_value(k);

    //
    assert(has(k));
}

TrieNode::Ref
Trie::find_node(std::string const& pref) const
{
    TrieNode::Ref node;
    //TODO
    auto node = root_;
    int i = 0;
    while(i<pref.size() and node != nullptr){
        if(node->has(pref[i])){
            node = node->child(pref[i]);
            i++;
        }

        else{
            node = nullptr;
        }
    }

    //
    return node;
}

void
Trie::preorder_traversal(TrieNode::Ref const& node,
                         std::vector<std::string> & keys) const
{
    //TODO
    char aux;

    if(node->value() == ""){
        keys.push_back(node->value());
    }

    for(aux In node->children()){
        preorder_traversal(node->child(aux), keys);
    }

    //
}

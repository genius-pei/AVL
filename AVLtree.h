#pragma once
template<class K,class V>
struct AVLtreeNode
{
	pair<K,V> _kv;
	AVLtreeNode<K, V>* _left;
	AVLtreeNode<K, V>* _right;
	AVLtreeNode<K, V>* _parent;
	int _bf;//balance factor;
	AVLtreeNode(const pair<K, V>& kv)
		:kv(_kv)
		,_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_bf(0)
	{

	}
};

template<class K,class V>
class AVLtree
{
	typedef()
};


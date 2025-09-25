#pragma once
#include<assert.h>
using namespace std;
template<class K,class V>
struct AVLtreeNode
{
	pair<K, V> _kv;
	AVLtreeNode<K, V>* _left;
	AVLtreeNode<K, V>* _right;
	AVLtreeNode<K, V>* _parent;
	int _bf;//balance factor;
	AVLtreeNode(const pair<K, V>& kv)
		:_kv(kv)
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
	typedef AVLtreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);

			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)//走到最下端
		{
			if (cur->_kv.first<kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}


		cur = new Node(kv);
		cur->_bf = 0;

		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;//更改新插入节点的parent

		while ()
		{
			if (cur == parent->_right)
			{
				parent->_bf++;
			}
			else
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 旋转处理
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RoatateR(parent);
				}

				break;
			}
			else//超过2
			{
				assert(false);
			}
		}

		return true;
	}
	
		void RoatateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
           
			parent->_left = subLR;
			if (subLR)
			{
				subLR->_parent = parent;
	        }
			Node* parentParent = parent->_parent;
			subL->_right = parent;
			parent->_parent = subL;
			if (parent == _root)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subL;
				}
				else
				{
					parentParent->_right = subL;
				}
				subL->_parent=parentParent
			}
			parent->_bf = subL->_bf = 0;
		}
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			parent->_right = subRL;
			if (subRL)
			{
				subRL->_left = parent;
			}	Node* parentParent = parent->_parent;
			subR->_left = parent;
			parent->_parent = subR;
			if (parent == _root)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (parentParent->_left == parent)
				{
					parentParent->_left = subR;
				}
				else
				{
					parentParent->_right = subR;
				}

				subR->_parent = parentParent;
			}

			subR->_bf = parent->_bf = 0;
		
		}
		private:
			Node* _root = nullptr;
	};

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
	typedef AVLtreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(key, value);

			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)//走到最下端
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}


		cur = new Node(key, value);
		cur->_bf = 0;

		if (parent->_key < key)
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
			}
			else
			{
				assert(false);
			}
		}

		return true;
	}
	private: 
	};

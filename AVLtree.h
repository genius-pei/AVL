#pragma once
#include<assert.h>
#include<iostream>
#include<utility>
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
		while (cur)//�ߵ����¶�
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

		cur->_parent = parent;//�����²���ڵ��parent

		 while (parent)
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
				// �������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ��ת����
				if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				
				

				break;
			}
			
			else//����2
			{
				assert(false);
			}
		 }

		return true;
	}
	
		void RotateR(Node* parent)
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
				subL->_parent = parentParent;
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
				subRL->_parent = parent;
			}	
			Node* parentParent = parent->_parent;
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
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			if (subL == nullptr)
				return;
		
			Node* subLR = subL->_right;
			if (subLR == nullptr)
				return;

			int bf = subLR->_bf;//����subLR��ֵ�жϲ���λ��
			RotateL(subL);
			RotateR(parent);
			if (bf == 0)
			{
				subL->_bf = 0;
				parent->_bf = 0;
				subLR->_bf = 0;
			}
			else if (bf == 1)
			{
				subL->_bf = -1;
				parent->_bf = 0;
				subLR->_bf= 0;
			}
			else if(bf==-1)
			{
				subL->_bf = 0;
				parent->_bf = 1;
				subLR->_bf = 0;
			}
			else
			{
				assert(false);
			}

		}
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			if (subR == nullptr)
				return;
	
			Node* subRL = subR->_left;
			if (subRL == nullptr)
				return;



			int bf = subRL->_bf;
			RotateR(parent->_right);
			RotateL(parent);
			if (bf == 0)
			{
				subR->_bf = 0;
				subRL->_bf = 0;
				parent->_bf = 0;
			}
			else if (bf == 1)
			{
				subR->_bf = 0;
				subRL->_bf = 0;
				parent->_bf = -1;
			}
			else if (bf == -1)
			{
				subR->_bf = 1;
				subRL->_bf = 0;
				parent->_bf = 0;
			}
			else
			{
				assert(false);
			}
		}
		/*bool _IsBalanceTree(Node* root)
		{
			if (root == nullptr)
				return true;

			int leftHeight = _Height(root->_left);
			int rightHeight = _Height(root->_right);
			int bf = rightHeight - leftHeight;
			if (abs(bf) >= 2 || bf != root->_bf)
			{
				cout << root->_kv.first << "ƽ�������쳣" << endl;
				return false;
			}

			return _IsBalanceTree(root->_left)
				&& _IsBalanceTree(root->_right);

		}*/
		void InOrder()
		{
			_InOrder(_root);
		     cout << endl;
		}

		private:
			void _InOrder(Node* root)
			{
				if (root == nullptr)
					return;

				_InOrder(root->_left);
				cout << root->_kv.first << " ";
				//cout << root->_kv.first << ":" << root->_kv.second << endl;
				_InOrder(root->_right);
			}

			Node* _root = nullptr;
	};

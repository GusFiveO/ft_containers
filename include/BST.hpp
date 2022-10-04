/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:25:43 by alorain           #+#    #+#             */
/*   Updated: 2022/10/04 18:23:30 by alorain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

namespace ft
{
	
	template<typename T>

	struct s_data
	{
		T value;
		struct s_data* parent;
		struct s_data* right;
		struct s_data* left;

		//struct s_data(const struct s_data& copy)
		//{
		//	std::allocator<struct s_data<T> >.construct(this->parent, copy,parent);
		//}
	};

template<typename T, typename Allocator = std::allocator<struct s_data<T> > >
class Node
{
	public:
		typedef  Allocator			allocator_type;
		typedef  T 					value_type;
		typedef  T&					reference;
		typedef  T*					pointer;
		typedef struct s_data<T>	t_data;
		

	private:
		t_data*	 		_data;
		allocator_type	_alloc;

	public:
		Node(void)
		{
			this->_data = this->_alloc.allocate(1);
			this->_data->value = T();
			//this->_data->right = this->_alloc.allocate(0);
			//this->_data->left = this->_alloc.allocate(0);
			//this->_data->parent = this->_alloc.allocate(0);
			this->_data->right = NULL;
			this->_data->left = NULL;
			this->_data->parent = NULL;
			std::cout << _data->parent << std::endl;
		}

		Node(value_type& val)
		{
			this->_data = this->_alloc.allocate(1);
			this->_data->value = val;
			//this->_data->right = this->_alloc.allocate(0);
			//this->_data->left = this->_alloc.allocate(0);
			//this->_data->parent = this->_alloc.allocate(0);
			this->_data->right = NULL;
			this->_data->left = NULL;
			this->_data->parent = NULL;
		}

		Node(const t_data& data)
		{
			this->_data = this->_alloc.allocate(1);
			this->_data->value = data.value;
			this->_data->right = this->_alloc.allocate(1);
			this->_data->left = this->_alloc.allocate(1);
			this->_data->parent = this->_alloc.allocate(1);
			if (data->right)
				this->_alloc.construct(this->_data->right, *(data->right));
			else
				this->_data->right = NULL;
			if (data->left)
				this->_alloc.construct(this->_data->left, *(data->left));
			else
				this->_data->left = NULL;
			if (data->parent)
				this->_alloc.construct(this->_data->parent, *(data->parent));
			else
				this->_data->parent = NULL;
		}

		Node(const Node& node)
		{
			this->_data = this->_alloc.allocate(1);
			this->_data->value = node._data->value;
			this->_data->left = this->_alloc.allocate(1);
			this->_data->right = this->_alloc.allocate(1);
			this->_data->parent = this->_alloc.allocate(1);
			if (node._data->right)
				this->_alloc.construct(this->_data->right, *(node._data->right));
			else
				this->_data->right = NULL;
			if (node._data->left)
				this->_alloc.construct(this->_data->left, *(node._data->left));
			else
				this->_data->left = NULL;
			if (node._data->parent)
				this->_alloc.construct(this->_data->parent, *(node._data->parent));
			else
				this->_data->parent = NULL;
		}

		~Node(void)
		{
			this->_alloc.deallocate(this->_data->right, 1);
			this->_alloc.deallocate(this->_data->left, 1);
			this->_alloc.deallocate(this->_data->parent, 1);
			this->_alloc.deallocate(this->_data, 1);
			std::cout << "SALUT LES NULS" << std::endl;
		}

		value_type
		getValue(void)
		{
			return this->_data->value;
		}

		t_data*
		getParent(void)
		{
			return this->_data->parent;
		}

};

template<typename T, typename Allocator = std::allocator<Node<T> > >
class BST
{
	public:
		typedef Allocator			allocator_type;
		typedef T 					value_type;
		typedef T&					reference;
		typedef T*					pointer;
		typedef Node<T>				node_type;
		typedef struct s_data<T>	t_data;

	private:
		node_type* 		_root;
		allocator_type	_alloc;

	public:

		BST(void)
		{
			this->_root = this->_alloc.allocate(1);
			this->_alloc.construct(this->_root, node_type());
		}

		BST(const node_type& node)
		: _root(node) {}

		~BST(void)
		{
			this->_alloc.destroy(this->_root);
			this->_alloc.deallocate(this->_root, 1);
		}

		void
		insert(value_type val)
		{
			node_type* tmp = this->_root;
			bool end = false;
			while (!end)
			{
				if (tmp == this->_root)
				{
					this->_alloc.destroy(tmp);
					this->_alloc.construct(tmp, node_type(val));
				}
				end = true;
			}
		}

		void
		display(void)
		{
			std::cout << this->_root->getValue() << std::endl;
		}
		
};

}

#endif

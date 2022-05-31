/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmonbeig <fmonbeig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:32:52 by fmonbeig          #+#    #+#             */
/*   Updated: 2022/05/31 16:37:40 by fmonbeig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <limits>
#include <string>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <functional>
#include "pair.hpp"
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "avl_tree.hpp"

namespace ft
{
template<
	typename Key,
	typename T,
	typename Compare = std::less<Key>,// Function object for performing comparisons. ex : Compare(x, y)
	typename Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef typename ft::pair<const Key, T>			value_type;

		typedef std::size_t 							size_type;
		typedef std::ptrdiff_t							difference_type;

		typedef Compare									key_compare;
		typedef Allocator								Allocator_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;

		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		//typedef 										iterator;
		//typedef 										const_iterator;
		// typedef ft::reverse_iterator<iterator>			reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	public:

		/*	std::map::value_compare is a function object that compares objects of type
			std::map::value_type (key-value pairs) by comparing of the first components of the pairs.
			binary_function is a base class for creating function objects with two arguments.*/
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			//friend class map<Key, T, Compare, Allocator>;
			protected :
				Compare comp;
				value_compare(Compare c): comp(c) {}

			public :
				bool operator()( const value_type& lhs, const value_type& rhs ) const
				{ return comp(lhs.first, rhs.first); }
		};

		// +------------------------------------------+ //
		//   MEMBER FUNCTIONS							//
		// +------------------------------------------+ //

		explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
			_tree(comp, alloc), _size(0) {} // construction de l'arbre

		// template< class InputIt >
		// map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ):
		// _ptr(comp, alloc)
		// {

		// }
		// map( const map& other )
		// {

		// }

		// +------------------------------------------+ //
		//   MODIFIERS									//
		// +------------------------------------------+ //

		// std::pair<iterator, bool> insert( const value_type& value );
		void	insert( const value_type& value )
		{
			_tree.insert(value);
			_size++;
		}

		value_type *rootKey() // renvoie une value const Key, a voir si on doit le changer ( phase iterateur)
		{
			return _tree.rootKey();
		}

	protected:
		avl_tree<value_type, Compare, Allocator>	_tree;
		size_t										_size;


};

}
#endif

// Map utilise des arbres pour equilibré l'acces a ses données
// A verifier
// Map ne peut avoir que des cles unique
// Les elements vont etre choisi par une fonction (autre classe ?) Compare
// Dans un arbre binaire on range les elements comme suit : si nouveau mot et au dessus du dernier alors on le met a droite sinon c'est a gauche
// Pas opti car si toujours d'un cote alors l'arbre est desequilibré

/*  https://fr.wikipedia.org/wiki/Arbre_bicolore
les règles suivantes sont utilisées :

1 - Un nœud est soit rouge soit noir ;
2 - La racine est noire ;
3 - Les enfants d'un nœud rouge sont noirs;
4 - Tous les nœuds ont 2 enfants. Ce sont d'autres nœuds ou des feuilles NIL, qui ne possèdent pas de valeur et qui sont les seuls nœuds sans enfants. Leur couleur est toujours noire et rentre donc en compte lors du calcul de la hauteur noire.
5 - Le chemin de la racine à n'importe quelle feuille (NIL) contient le même nombre de nœuds noirs. On peut appeler ce nombre de nœuds noirs la hauteur noire.

	https://fr.wikipedia.org/wiki/Arbre_binaire_de_recherche
	https://fr.wikipedia.org/wiki/Arbre_AVL
*/


// S'il y a des duplications alors on ne les prends pas en compte

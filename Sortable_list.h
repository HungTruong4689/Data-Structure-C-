#pragma once
#include "List.h"
#include "Key.h"
//#include "Ordered_list.h"
typedef Key Record;
template <class Record>
class Sortable_list :public List<Record> {
public:   //  Add prototypes for sorting methods here.
    Sortable_list();
    //void insertion_sort();
    void selection_sort();
    void insertion_sort_node();
    void quick_sort();

private: //  Add prototypes for auxiliary functions here.
    int max_key(int low, int high);
    void swap(int low, int high);
    void recursive_quick_sort(Node<Record>*& first_node,
        Node<Record>*& last_node);
    void partition(Node<Record>* sub_list,
        Node<Record>*& first_small, Node<Record>*& last_small,
        Node<Record>*& first_large, Node<Record>*& last_large);
};

template<class Record>
inline Sortable_list<Record>::Sortable_list()
{
}

//template <class Record>
//void Sortable_list<Record>::insertion_sort()
///*
//Post: The entries of the Sortable_list have been rearranged so that
//      the keys in all the  entries are sorted into nondecreasing order.
//Uses: Methods for the class Record; the contiguous List implementation of
//      Chapter 6
//*/
//{
//    int first_unsorted;    //  position of first unsorted entry
//    int position;          //  searches sorted part of list
//    Record current;        //  holds the entry temporarily removed from list
//    //Node entry;
//    for (first_unsorted = 1; first_unsorted < count; first_unsorted++)
//        if (entry[first_unsorted] < entry[first_unsorted - 1]) {
//            position = first_unsorted;
//            current = entry[first_unsorted];         //  Pull unsorted entry out of the list.
//            do {               //  Shift all entries until the proper position is found.
//                entry[position] = entry[position - 1];
//                position--;                           //  position is empty.
//            } while (position > 0 && entry[position - 1] > current);
//            entry[position] = current;
//        }
//}
template <class Record>
void Sortable_list<Record>::selection_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
      the keys in all the entries are sorted into nondecreasing order.
Uses: max_key, swap.
*/
{
    for (int position = this->count - 1; position > 0; position--) {
        int max = max_key(0, position);
        swap(max, position);
    }
}
template <class Record>
int Sortable_list<Record>::max_key(int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list and low <= high.
Post: The position of the entry between low and high with the largest
      key is returned.
Uses: The class Record, the contiguous List implementation of Chapter 6.
*/
{
    int largest, current;
    largest = low;
    Record big, consider;
    this->retrieve(low, big);
    for (current = low + 1; current <= high; current++) {
        this->retrieve(current, consider);
        if (big < consider) {
            largest = current;
            big = consider;
        }
    }
    return largest;
}
template <class Record>
void Sortable_list<Record>::swap(int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list.
Post: The entry at position low is swapped with the entry at position high.
Uses: The contiguous List implementation of Chapter 6.
*/
{
    Record low_r,high_r;
    this->retrieve(low, low_r);
    this->retrieve(high, high_r);
    this->replace(low, high_r);
    this->replace(high, low_r);
}
template <class Record>
void Sortable_list<Record>::insertion_sort_node()
/*
Post: The entries of the Sortable_list have been rearranged so that
      the keys in all the entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the linked List implementation of Chapter 6.
*/
{
    Node <Record>* first_unsorted,  //  the first unsorted node to be inserted
        * last_sorted,     //  tail of the sorted sublist
        * current,         //  used to traverse the sorted sublist
        * trailing;        //  one position behind current

    if (this->head != NULL) {          //  Otherwise, the empty list is already sorted.
        last_sorted = this->head;       //  The first node alone makes a sorted sublist.
        while (last_sorted->next != NULL) {
            first_unsorted = last_sorted->next;
            if (first_unsorted->entry < this->head->entry) {
                //  Insert *first_unsorted at the head of the sorted list:
                last_sorted->next = first_unsorted->next;
                first_unsorted->next = this->head;
                this->head = first_unsorted;
            }
            else {
                //  Search the sorted sublist to insert *first_unsorted:
                trailing = this->head;
                current = trailing->next;
                while (first_unsorted->entry > current->entry) {
                    trailing = current;
                    current = trailing->next;
                }

                //  *first_unsorted now belongs between *trailing and *current.

                if (first_unsorted == current)
                    last_sorted = first_unsorted;  //  already in right position
                else {
                    last_sorted->next = first_unsorted->next;
                    first_unsorted->next = current;
                    trailing->next = first_unsorted;
                }
            }
        }
    }
}
template <class Record>
void Sortable_list<Record>::quick_sort()
/*
Post: The entries of the Sortable_list have been rearranged so
      that their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6, recursive_quick_sort.
*/
{
    if (this->head == NULL || this->head->next == NULL) return;
    recursive_quick_sort(this->head, this->head->next);
}
template <class Record>
void Sortable_list<Record>::recursive_quick_sort(Node<Record>*& first_node,
    Node<Record>*& last_node)
/*
Pre:  low and high are valid positions in the Sortable_list.
Post: The entries of the Sortable_list have been
      rearranged so that their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6,
      recursive_quick_sort, and partition.
*/
{
    if (first_node != NULL && first_node != last_node) {
        Node<Record>* first_small, * last_small, * first_large, * last_large;
        partition(first_node, first_small, last_small, first_large, last_large);
        recursive_quick_sort(first_small, last_small);
        recursive_quick_sort(first_large, last_large);
        if (last_large != NULL) last_node = last_large;
        else last_node = first_node;

        first_node->next = first_large;

        if (first_small != NULL) {
            last_small->next = first_node;
            first_node= first_small;
        }
    }
}
template <class Record>
void Sortable_list<Record>::partition(Node<Record>* sub_list,
    Node<Record>*& first_small, Node<Record>*& last_small,
    Node<Record>*& first_large, Node<Record>*& last_large)

{
    Record pivot = sub_list->entry;
    sub_list = sub_list->next;
    Node<Record> small, large;
    last_small = &small;
    last_large = &large;
    while (sub_list != NULL) {
        if (sub_list->entry > pivot)
            last_large = last_large->next = sub_list;
        else
            last_small = last_small->next = sub_list;
        sub_list = sub_list->next;
    }
    last_large->next = last_small->next = NULL;
    if ((first_small = small.next) == NULL) last_small = NULL;
    if ((first_large = large.next) == NULL) last_large = NULL;
}
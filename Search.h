
#pragma once
//#include "Record.h"
#include "Key.h"
#include "List.h"
#include "Utility.h"
#include "Ordered_list.h"
typedef Key Record;

Error_code sequential_search(const List<Record>& the_list,
    const Key& target, int& position)
{
    int s = the_list.size();
    for (position = 0; position < s; position++) {
        Record data;
        the_list.retrieve(position, data);
        if (data == target) return success;
    }
    return not_present;
}
Error_code binary_search_1(const Ordered_list& the_list,
    const Key& target, int& position)
    /*
    Post: If a Record in the_list  has Key equal to target, then position locates
          one such entry and a code of success is returned.
          Otherwise, not_present is returned and position is undefined.
    Uses: Methods for classes List and Record.
    */
{
    Record data;
    int bottom = 0, top = the_list.size() - 1;

    while (bottom < top) {
        int mid = (bottom + top) / 2;
        the_list.retrieve(mid, data);
        if (data < target)
            bottom = mid + 1;
        else
            top = mid;
    }
    if (top < bottom) return not_present;
    else {
        position = bottom;
        the_list.retrieve(bottom, data);
        if (data == target) return success;
        else return not_present;
    }
}
Error_code binary_search_2(const Ordered_list& the_list,
    const Key& target, int& position)
    /*
    Post: If a Record in the_list has key equal to target, then position locates
          one such entry and a code of success is returned.
          Otherwise, not_present is returned and position is undefined.
    Uses: Methods for classes Ordered_list and Record.
    */
{
    Record data;
    int bottom = 0, top = the_list.size() - 1;
    while (bottom <= top) {
        position = (bottom + top) / 2;
        the_list.retrieve(position, data);
        if (data == target) return success;
        if (data < target) bottom = position + 1;
        else top = position - 1;
    }
    return not_present;
}

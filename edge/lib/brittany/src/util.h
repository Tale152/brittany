#ifndef BRITTANY_UTIL_H
#define BRITTANY_UTIL_H

#include "hw/ComponentHw.h"
#include <list>
#include <string>

/**
 * @tparam T The class of elements contained in the list.
 */
template <class T>

/**
 * @brief Return the T pointer with the chosen id if present.
 * 
 * @param list the list of T.
 * @param id the id of the T to find.
 * @return T a pointer to the T class with the selected id, NULL otherwise.
 */
T find_by_id(std::list<T> list, std::string id) {
    for(T c : list) {
        if(c->id() == id) {
            return c;
        }
    }
    return NULL;
}

#endif //BRITTANY_UTIL_H
#ifndef BRITTANY_UTIL_H
#define BRITTANY_UTIL_H

#include "hw/ComponentHw.h"
#include <list>
#include <string>

/**
 * @brief Return the ComponentHw pointer with the chosen id if present.
 * 
 * @param list the list of components.
 * @param id the id of the ComponentHw to find.
 * @return ComponentHw* a pointer to the ComponentHw with the selected id, NULL otherwise.
 */
ComponentHw* find_by_id(std::list<ComponentHw*> list, std::string id) {
    for(ComponentHw* c : list) {
        if(c->id() == id) {
            return c;
        }
    }
    return NULL;
}

#endif //BRITTANY_UTIL_H
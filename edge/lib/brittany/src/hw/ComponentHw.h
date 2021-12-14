#ifndef BRITTANY_COMPONENTHW_H
#define BRITTANY_COMPONENTHW_H

#include <string>

/**
 * @brief Class representing a hardware component.
 * 
 */
class ComponentHw {

public:

    /**
     * @brief Construct a new Component Hw object.
     * 
     * @param id the unique id of the component.
     */
    ComponentHw(std::string id);

    /**
     * @brief get the id of the component.
     * 
     * @return std::string the component id.
     */
    std::string id();

private:

    std::string _id;

};


#endif //BRITTANY_COMPONENTHW_H

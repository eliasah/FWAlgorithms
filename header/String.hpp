#ifndef String_hpp
#define String_hpp

#include "Stat.hpp"
#include "Object.hpp"

/**
 * @class String
 * La classe String répresente une
 * classe de type string et une réference 
 * vers une instance de statistique.
 * La classe String hérite de la spécification de Object<string,stat>
 */
template<Stat *stat> class String : public Object<string,stat> {
public:
    String<stat>() {}
    String<stat>(const string &s) : Object<string,stat>(s) {}

    // TODO
};

#endif

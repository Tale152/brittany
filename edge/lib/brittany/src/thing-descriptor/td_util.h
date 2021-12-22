#include <string>
#include <tuple>

namespace TD {

    enum Key {
        CONTEXT = 0,
        SECURITY_DEFINITIONS = 1,
        SECURITY_DEFINITIONS_SCHEME = 2,
        SECURITY_DEFINITIONS_IN = 3,
        SECURITY = 4
    };

    std::tuple<const char *, const char*> td[] = {
        std::make_tuple("@context", "https://www.w3.org/2019/wot/td/v1"),
        std::make_tuple("securityDefinitions", "no_sec"),
        std::make_tuple("scheme", "nosec"),
        std::make_tuple("in", "header"),
        std::make_tuple("security", "no_sec")
    };

    std::string key(Key key) {
        return std::get<0>(td[key]);
    }
        
    std::string value(Key key) {
        return std::get<1>(td[key]);
    } 

}

#include "../external/nlohmann/json.hpp"

using json = nlohmann::json;

class JSONify
{
public:
    virtual json getJSON() const = 0;
};

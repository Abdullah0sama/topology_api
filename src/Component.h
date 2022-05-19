#include <vector>

class Component
{
private:
    /* data */
public:
    typedef std::vector<Component> ComponentList; 
    Component(/* args */);
    ~Component();
};

Component::Component(/* args */)
{
}

Component::~Component()
{
}

#pragma once
#include <loki/Factory.h>

template
<
    class AbstractProduct,
    typename IdentifierType,
    typename ProductCreator
>
class Factory
{
public:
    using AssocMap = std::map<IdentifierType, AbstractProduct>;
public:
    bool Register(const IdentifierType& id, ProductCreator creator)
    {
        return associations_.insert(
            AssocMap::value_type(id, creator)).second;
    }
    bool Unregister(const IdentifierType& id)
    {
        return associations_.erase(id) == 1;
    }
    AbstractProduct* CreateObject(const IdentifierType& id)
    {
        typename AssocMap::const_iterator i =
            associations_.find(id);
        if (i != associations_.end())
        {
            return (i->second)();
        }

    }
private:
    AssocMap associations_;
};


template
<
    class AbstractProduct,
    class ProductCreator =
    AbstractProduct * (*)(const AbstractProduct*),
    template<typename, class>
class FactoryErrorPolicy = Loki::DefaultFactoryError
>
class CloneFactory
    : public FactoryErrorPolicy<TypeInfo, AbstractProduct>
{
public:
    bool Register(const TypeInfo& ti, ProductCreator creator)
    {
        return associations_.insert(
            typename IdToProductMap::value_type(ti, creator)).second != 0;
    }

    bool Unregister(const TypeInfo& id)
    {
        return associations_.erase(id) != 0;
    }

    AbstractProduct* CreateObject(const AbstractProduct* model)
    {
        if (model == NULL)
        {
            return NULL;
        }

        typename IdToProductMap::iterator i =
            associations_.find(typeid(*model));

        if (i != associations_.end())
        {
            return (i->second)(model);
        }
        return this->OnUnknownType(typeid(*model));
    }

private:
    typedef AssocVector<TypeInfo, ProductCreator> IdToProductMap;
    IdToProductMap associations_;
};
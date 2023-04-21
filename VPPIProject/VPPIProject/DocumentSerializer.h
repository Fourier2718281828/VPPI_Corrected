#pragma once
#include "ISerializer.h"
#include "DeserializeException.h"
#include "IDocument.h"
#include <map>
#include <functional>

template
<
	typename IdentifierType, 
	typename ProductCreator 
	= std::function<ISerializer::ptr<ISerializable>(std::ifstream&)>
>
class ConcreteSerializer : public ISerializer
{
private:
	using AssocMap = std::map<IdentifierType, ProductCreator>;

public:

	bool register_product(const IdentifierType& id, ProductCreator creator)
	{
		return associations_.insert({ id, creator }).second;
	}

	bool unregister_product(const IdentifierType& id) const
	{
		return associations_.erase(id) == 1;
	}

	void serialize(std::ofstream& of, const ISerializable& product) const override
	{
		product.serialize(of);
	}

	ptr<ISerializable> deserialize(std::ifstream& fs) override
	{
		int buf;
		fs >> buf;

		IdentifierType id = static_cast<IdentifierType>(buf);

		auto i = associations_.find(id);

		if (i != associations_.end())
		{
			return (i->second)(fs);
		}

		throw DecerializeException("Unknown Type");
	}

private:
	AssocMap associations_;
};

using DocumentSerializer = ConcreteSerializer<IDocument::Type>;
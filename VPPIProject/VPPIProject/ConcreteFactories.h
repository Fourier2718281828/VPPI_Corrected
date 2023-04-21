#ifndef CONCRETE_FACTORIES_
#define CONCRETE_FACTORIES_
#include "IFactories.h"
#include "loki/TypeManip.h"
#include "loki/Sequence.h"
#include "PlainTextDocument.h"
#include "MathTextDocument.h"
#include "MathTextHeader.h"
#include "TextHeader.h"

template <class ConcreteProduct, class Base>
class ConcreteFactoryUnit : public Base
{
private:
	using BaseProductList = typename Base::ProductList;
protected:
	using ProductList = typename BaseProductList::Tail;
public:
	using AbstractProduct = typename BaseProductList::Head;
	using abstract_product_ptr = std::unique_ptr<AbstractProduct>;
public:
	abstract_product_ptr Create(Dispatcher<AbstractProduct>) const override
	{
		return std::make_unique<ConcreteProduct>();
	}
};

template
<
	typename AbstractFact,
	typename ProductTypes,
	template <typename, typename> typename Unit = ConcreteFactoryUnit
>
class ConcreteFactory : 
	public Loki::GenLinearHierarchy 
	<
		typename Loki::TL::Reverse<ProductTypes>::Result,
		Unit,
		AbstractFact
	>
{
public:
	using ProductList = typename AbstractFact::ProductList;
	using ConcreteProductList = ProductTypes;
};

using PlainTextFactory = ConcreteFactory
<
	IDocHeaderFactory,
	LOKI_TYPELIST_2(PlainTextDocument, TextHeader),
	ConcreteFactoryUnit
>;

using MathTextFactory = ConcreteFactory
<
	IDocHeaderFactory,
	LOKI_TYPELIST_2(MathTextDocument, MathTextHeader),
	ConcreteFactoryUnit
>;

//#include "ConsoleDocumentEditor.h"
//namespace
//{
//
//	class FactoryRegistrator
//	{
//	private:
//		static const bool PLAIN_TEXT_FACTORY;
//		static const bool MATH_TEXT_FACTORY;
//	};

////#define PROTOTYPE_BASED_FACTORIES
//#ifndef PROTOTYPE_BASED_FACTORIES
//	const bool FactoryRegistrator::PLAIN_TEXT_FACTORY =
//		ConsoleDocumentEditor::get_instance().register_factory<PlainTextFactory>(IDocument::Type::PLAIN_TEXT);
//	const bool FactoryRegistrator::MATH_TEXT_FACTORY =
//		ConsoleDocumentEditor::get_instance().register_factory<MathTextFactory>(IDocument::Type::MATH_TEXT);
//#else
//
//#endif // !PROTOTYPE_BASED_FACTORIES
//}


#endif // !CONCRETE_FACTORIES_

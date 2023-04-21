#include <iostream>
#include <memory>
#include "ConsoleDocumentEditor.h"
#include "DocumentSerializer.h"
#include "ConcreteFactories.h"
#include "PlainTextDocument.h"
#include "MathTextDocument.h"

auto main() -> int
{
	DocumentSerializer serializer;
	PlainTextDocument::register_for_serialization(serializer);
	MathTextDocument::register_for_serialization(serializer);
	ConsoleDocumentEditor app(std::cout, std::cin, serializer);

	app.register_factory<PlainTextFactory>(IDocument::Type::PLAIN_TEXT);
	app.register_factory<MathTextFactory>(IDocument::Type::MATH_TEXT);

	return app.execute();
}
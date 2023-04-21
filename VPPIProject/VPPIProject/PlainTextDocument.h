#ifndef PLAIN_TEXT_DOCUMENT_
#define PLAIN_TEXT_DOCUMENT_
#include "IDocument.h"
#include "DocumentSerializer.h"

class PlainTextDocument : public IDocument
{
public:
	const text_type& get_text() const noexcept override;
	void append_text(const text_type&) override;
	void clear() noexcept override;
public:
	void serialize(std::ofstream&) const override;
	void deserialize(std::ifstream&) override;
	Type type() const noexcept override;
	static void register_for_serialization(DocumentSerializer&);
private:
	text_type text_;
private:
	static constexpr const Type s_TYPE = Type::PLAIN_TEXT;
};



#endif // !PLAIN_TEXT_DOCUMENT_

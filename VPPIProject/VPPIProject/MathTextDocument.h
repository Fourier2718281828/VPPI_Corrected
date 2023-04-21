#ifndef MATH_TEXT_DOCUMENT_
#define MATH_TEXT_DOCUMENT_
#include "IDocument.h"
#include "DocumentSerializer.h"

class MathTextDocument : public IDocument
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
	bool check_for_correctness(const text_type&) const noexcept;
private:
	text_type text_;
private:
	static constexpr const Type s_TYPE = Type::MATH_TEXT;
};

#endif // !MATH_TEXT_DOCUMENT_

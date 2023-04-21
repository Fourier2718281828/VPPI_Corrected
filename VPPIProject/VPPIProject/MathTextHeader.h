#ifndef MATH_HEADER_
#define MATH_HEADER_
#include "IHeader.h"

class MathTextHeader : public IHeader
{
public:
	MathTextHeader();
	~MathTextHeader() override = default;
public:
	const caption_txt_type get_title() const noexcept override;
	const command_map& get_commands() const noexcept override;
private:
	void insert_formula(IDocument&, const iterable&) const;
	void clear(IDocument&, const iterable&) const;
private:
	command_map commands_;
};

#endif // !MATH_HEADER_

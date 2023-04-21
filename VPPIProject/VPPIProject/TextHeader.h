#ifndef TEXT_HEADER_
#define TEXT_HEADER_
#include "IHeader.h"

class TextHeader : public IHeader
{
public:
	TextHeader();
	~TextHeader() override = default;
public:
	const caption_txt_type get_title() const noexcept override;
	const command_map& get_commands() const noexcept override;
private:
	void insert_text(IDocument&, const iterable&) const;
	void clear(IDocument&, const iterable&) const;
private:
	command_map commands_;
};

#endif // !TEXT_HEADER_

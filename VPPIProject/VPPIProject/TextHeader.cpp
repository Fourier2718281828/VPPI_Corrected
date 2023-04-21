#include "TextHeader.h"
#include "CommandException.h"

#define ATTACH_METHOD(method_name) \
std::bind(&TextHeader::method_name, this, std::placeholders::_1, std::placeholders::_2)

TextHeader::TextHeader() :
	commands_
{
	{"insert_text", ATTACH_METHOD(insert_text)},
	{"clear", ATTACH_METHOD(clear)},
}
{
}

auto TextHeader::get_title() const noexcept -> const caption_txt_type
{
	return "\tText Document Editor:";
}

auto TextHeader::get_commands() const noexcept -> const command_map&
{
	return commands_;
}

auto TextHeader::insert_text
(
	IDocument& document, 
	const iterable& params
) const -> void
{
	if (params.size() == 0)
		throw CommandException("***Invalid number of params");
	for (auto&& word : params)
	{
		document.append_text(word + ' ');
	}
	document.append_text("\n");
}

auto TextHeader::clear
(
	IDocument& document, 
	const iterable& params
) const -> void
{
	if (params.size() != 0)
		throw CommandException("***Invalid number of params");
	document.clear();
}

#ifndef IHEADER_
#define IHEADER_
#include <string>
#include <map>
#include <utility>
#include <functional>
#include <iostream>
#include "IDocument.h"

class IHeader
{
public:
	using text_type = IDocument::text_type;
	using caption_txt_type = std::string;
	using iterable = std::vector<text_type>;
	using istream = std::istream;
	using ostream = std::ostream;
	using command_type = std::function<void(IDocument&, const iterable&)>;
	using command_map = std::map<text_type, command_type>;
public:
	virtual ~IHeader() = default;
public:
	virtual const caption_txt_type get_title() const noexcept = 0;
	virtual const command_map& get_commands() const noexcept = 0;
};

#endif // !IHEADER_


#include "MathTextHeader.h"
#include "CommandException.h"
#include <regex>

#define ATTACH_METHOD(method_name) \
std::bind(&MathTextHeader::method_name, this, std::placeholders::_1, std::placeholders::_2)

MathTextHeader::MathTextHeader() :
    commands_
{
    {"insert_formula", ATTACH_METHOD(insert_formula)},
    {"clear", ATTACH_METHOD(clear)},
}
{
}

auto MathTextHeader::get_title() const noexcept -> const caption_txt_type
{
    return "\tMath Document Editor:";
}

auto MathTextHeader::get_commands() const noexcept -> const command_map&
{
    return commands_;
}

auto MathTextHeader::insert_formula(IDocument& document, const iterable& params) const -> void
{
    if (params.size() != 1)
        throw CommandException("***Invalid number of params");
    using std::regex;
    using std::regex_match;
    regex formula("^[-+]?[0-9]*\.?[0-9]+([-+*/]?([0-9]*\.?[0-9]+))*$");

    if (regex_match(params[0], formula))
        document.append_text(params[0] + ";\n");
    else 
        throw CommandException("***Input must be a formula");
}

auto MathTextHeader::clear(IDocument& document, const iterable& params) const -> void
{
    if (params.size() != 0)
        throw CommandException("***Invalid number of params");
    document.clear();
}

#include "PlainTextDocument.h"

auto PlainTextDocument::get_text() const noexcept -> const text_type&
{
    return text_;
}

auto PlainTextDocument::append_text(const text_type& txt) -> void
{
    text_ += txt;
}

auto PlainTextDocument::clear() noexcept -> void
{
    text_.clear();
}

auto PlainTextDocument::serialize(std::ofstream& os) const -> void
{
    os << static_cast<int>(type()) << '\n' << text_;
}

auto PlainTextDocument::deserialize(std::ifstream& is) -> void
{
    text_type buffer;
    while (!is.eof())
    {
        std::getline(is, buffer);
        append_text(buffer + '\n');
        buffer.clear();
    }
}

auto PlainTextDocument::type() const noexcept -> Type
{
    return s_TYPE;
}

auto create_document(std::ifstream& is) noexcept -> ISerializer::ptr<ISerializable>
{
    auto ptr = std::make_unique<PlainTextDocument>();
    ptr->deserialize(is);
    return ptr;
}

auto PlainTextDocument::register_for_serialization(DocumentSerializer& ser) -> void
{
    ser.register_product(s_TYPE, &create_document);
}

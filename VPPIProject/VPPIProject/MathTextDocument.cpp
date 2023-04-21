#include "MathTextDocument.h"
#include <algorithm>
#include "BadDocumentException.h"

auto MathTextDocument::get_text() const noexcept -> const text_type&
{
    return text_;
}

auto MathTextDocument::append_text(const text_type& txt) -> void
{
    if (!check_for_correctness(txt))
        throw BadDocumentException("Unacceptable text for math document");
    text_.append(txt);
}

auto MathTextDocument::clear() noexcept -> void
{
    text_.clear();
}

auto MathTextDocument::serialize(std::ofstream& os) const -> void
{
    os << static_cast<int>(type()) << '\n' << text_;
}

auto MathTextDocument::deserialize(std::ifstream& is) -> void
{
    text_type buffer;
    while (!is.eof())
    {
        std::getline(is, buffer);
        append_text(buffer + '\n');
        buffer.clear();
    }
}

auto MathTextDocument::type() const noexcept -> Type
{
    return s_TYPE;
}

auto MathTextDocument::check_for_correctness(const text_type& txt) const noexcept -> bool
{
    //some math logic...
    return true;
}

auto create_document_math(std::ifstream& is) noexcept -> ISerializer::ptr<ISerializable>
{
    auto ptr = std::make_unique<MathTextDocument>();
    ptr->deserialize(is);
    return ptr;
}

auto MathTextDocument::register_for_serialization(DocumentSerializer& ser) -> void
{
    ser.register_product(s_TYPE, &create_document_math);
}
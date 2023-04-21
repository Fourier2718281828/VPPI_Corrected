#ifndef CONSOLE_DOC_EDITOR_
#define CONSOLE_DOC_EDITOR_
#include "Application.h"
#include "IHeader.h"
#include "IDocument.h"
#include "ISerializer.h"
#include "IFactories.h"
#include "Singleton.h"
#include <memory>
#include <iostream>
#include <map>
#include <functional>
#include <utility>
#include <concepts>

class ConsoleDocumentEditor : 
	public Application 
	//public Singleton<ConsoleDocumentEditor>
{
private:
	template<typename T>
	using ptr = std::shared_ptr<T>;
	using factory_type = IDocHeaderFactory;
	using text_type = std::string;
	using iterable = IHeader::iterable; //std::vector<text_type>;
	using command_type = std::function<void(const iterable&)>;
	using command_map = std::map<text_type, command_type>;
public:
	static_assert(std::is_same_v<text_type, IHeader::text_type>, 
		"Text types must match.");
public:
	ConsoleDocumentEditor(std::ostream&, std::istream&, ISerializer&);
	~ConsoleDocumentEditor() override = default;
	int execute() const noexcept override;
public:
	template<typename FactoryType>
		requires std::is_default_constructible_v<FactoryType>
	bool register_factory(const IDocument::Type);
public:
	ConsoleDocumentEditor(const ConsoleDocumentEditor&) = delete;
	ConsoleDocumentEditor& operator=(const ConsoleDocumentEditor&) = delete;
public:
	void print_help(const iterable&) const;
	void new_document(const iterable&);
	void open_document(const iterable&);
	void close_document(const iterable&);
	void show_current(const iterable&) const;
	void save(const iterable&) const;
private:
	void main_loop() const noexcept;
	const std::pair<text_type, iterable> parse_user_command(const text_type&) const noexcept;
	ptr<factory_type> get_factory(const text_type&) const;
	void command_params_check(const unsigned short, const unsigned short) const;
	void show_document(const IDocument&, const IHeader&) const noexcept;
	void set_document(ptr<factory_type>) noexcept;
	static text_type doctype_to_string(const IDocument::Type);
private:
	std::map<text_type, ptr<factory_type>> doctypes_to_factories_;
	command_map commands_;
	std::ostream& output_;
	std::istream& input_;
	ISerializer& serializer_;
	ptr<IHeader> current_header_;
	ptr<IDocument> current_document_;
	ptr<factory_type> doc_creator_;
private:
	static const char* const s_APP_BORDER;
	static const char* const s_DOC_TOP_BORDER;
	static const char* const s_DOC_MID_BORDER;
	static const char* const s_DOC_BOT_BORDER;
	static const char* const s_DEFAULT_FILENAME;
	static const char* const s_FILE_DIR;
	static const char* const s_FILE_TYPE;
};

template<typename FactoryType>
	requires std::is_default_constructible_v<FactoryType>
inline bool ConsoleDocumentEditor::register_factory(const IDocument::Type doc_type)
{
	auto param_name = doctype_to_string(doc_type);
	if (doctypes_to_factories_.contains(param_name))
		throw std::runtime_error("***Factory of such a doctype has already been registered");
	auto factory_ptr = std::make_shared<FactoryType>();
	auto [_, result] = doctypes_to_factories_.insert({ param_name , factory_ptr });
	return result;
}

#endif // !CONSOLE_DOC_EDITOR_

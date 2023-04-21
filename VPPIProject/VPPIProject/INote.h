#ifndef INOTE_
#define INOTE_
#include <type_traits>

class INote
{
public:
	using frequency_t = float;
	using octava_shift_t = int;
	static_assert
	(
		std::is_arithmetic_v<frequency_t> &&
		std::is_arithmetic_v<octava_shift_t>,
		"Freaquency type must be arithmetic"
	);
public:
	virtual ~INote() = default;
	virtual frequency_t get_frequency() const noexcept = 0;
};



#define NOTE_DECLARATION(CLASS_NAME, FREQ)						\
class CLASS_NAME : public INote									\
{																\
public:															\
	CLASS_NAME(const octava_shift_t);							\
	~CLASS_NAME() override = default;							\
	frequency_t get_frequency() const noexcept override;		\
private:														\
	const octava_shift_t octava_shift_;							\
private:														\
	static constexpr const INote::frequency_t FREQUENCY = FREQ;	\
};	

#define NOTE_DEFINITION(CLASS_NAME)								\
CLASS_NAME::CLASS_NAME(const octava_shift_t s) :				\
	octava_shift_(s)											\
{}																\
																\
auto CLASS_NAME::get_frequency() const noexcept -> frequency_t	\
{																\
	return FREQUENCY * pow(2, octava_shift_);					\
}				

#endif // !INOTE_				

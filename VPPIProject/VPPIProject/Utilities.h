#ifndef UTILITIES_
#define UTILITIES_
#include <vector>

template<typename Word>
using Iterable = std::vector<Word>;

template<typename Word, typename DelimWord>
Iterable<Word> tokenize(const Word& word, const DelimWord& delims)
{
	using _Itor = typename Word::const_iterator;
	Iterable<Word> res;
	_Itor it1 = word.begin();
	_Itor it2 = word.begin();
	_Itor end = word.end();

	auto is_delim = [&delims](Word::value_type c) -> bool
	{
		return std::find(delims.begin(), delims.end(), c) != delims.end();
	};

	for (; it2 != end; ++it2)
	{
		if (is_delim(*it2))
		{
			res.emplace_back(it1, it2);
			it1 = it2;
			++it1;
		}
	}

	if (it1 != end)
	{
		res.emplace_back(it1, it2);
		it1 = it2;
	}

	return res;
}

template<typename Derived, typename Base>  
	requires std::is_convertible_v<Derived&, Base&>&&
				std::is_polymorphic_v<Base>
inline std::unique_ptr<Derived> cast_to(std::unique_ptr<Base>&& ptr)
{
	Derived* d = dynamic_cast<Derived*>(ptr.get());
	if (d) 
	{
		ptr.release();
		return std::unique_ptr<Derived>(d);
	}
	return nullptr; 
}

#endif // !UTILITIES_

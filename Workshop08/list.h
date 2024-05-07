/*******************************************************************
*                            Workshop 08
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-03-23
* Authentication Declaration:
* I declare that this submission is the result of my own work and I
* only copied the code that my professor provided to complete my
* workshops and assignments. This submitted piece of work has not
* been shared with any other student or 3rd party content provider.
*******************************************************************/
#ifndef SENECA_LIST_H
#define SENECA_LIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace seneca
{
	template <typename T>

	class List
	{
		std::vector<T> list;
	public:

		List() {}

		List(const char* fn)
		{
			std::ifstream file(fn);
			if(!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
			while(file) {
				T e;
				if(e.load(file))
					list.push_back(T(e));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		void operator+=(const std::unique_ptr<T>& src)
		{
			list.push_back(*src);
		}

		void operator+=(const T* src)
		{
			list.push_back(*src);
		}

		void display(std::ostream& os) const
		{
			os << std::fixed << std::setprecision(2);
			for(auto& e : list)
				e.display(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const List<T>& l)
	{
		l.display(os);
		return os;
	}
}
#endif //SENECA_LIST_H!
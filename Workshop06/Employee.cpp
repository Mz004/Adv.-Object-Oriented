/************************************************************************
*                              Workshop 06
* Name       : Manav Alpeshbhai Zadafiya
* Email      : mazadafiya@myseneca.ca
* Student ID : 144095221
* Date       : 2024-03-09
* Authentication Declaration:
* I declare that this submission is the result of my own work and I only
* copied the code that my professor provided to complete my workshops and
* assignments. This submitted piece of work has not been shared with any
* other student or 3rd party content provider.
************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"

namespace seneca
{
    Employee::Employee(std::istream& is)
    {
        std::string str{}, str2{};
        getline(is, str, ',');
        m_name = trim(str, " ");
        getline(is, str, ',');
        m_age = trim(str, " ");
        char ch{};
        is.get(ch);
        do {
            str2 += ch;
            is.get(ch);
        } while(ch != '\n' && ch != ',');
        m_id = trim(str2, " ");
        if(m_id[0] != 'E')
            throw(m_name + "++Invalid record!");
    }

    std::string Employee::status() const
    {
        return std::string("Employee");
    }

    std::string Employee::name() const
    {
        return m_name;
    }

    std::string Employee::id() const
    {
        return m_id;
    }

    std::string Employee::age() const
    {
        return m_age;
    }

    void Employee::display(std::ostream& os) const
    {
        os << "| " << std::left << std::setw(10) << "Employee" << "| "
            << std::setw(10) << m_id << "| " << std::setw(20) << m_name
            << " | " << std::setw(3) << m_age << " |";
    }
}
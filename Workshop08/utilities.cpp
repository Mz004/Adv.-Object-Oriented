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
#include <memory>
#include "list.h"
#include "element.h"
#include "utilities.h"

using namespace std;

namespace seneca
{
    List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        for(unsigned int i = 0; i < desc.size(); i++) {
            for(unsigned int j = 0; j < price.size(); j++) {
                if(desc[i].code == price[j].code) {
                    Product* product = new Product(desc[i].desc, price[j].price);
                    if(!(desc[i].code)) {
                        delete product;
                    }
                    else {
                        try {
                            product->validate();
                        }
                        catch(std::string err) {
                            delete product;
                            throw std::string(err);
                        }
                    }
                    priceList += product;
                    delete product;
                }
            }
        }

        return priceList;
    }

    List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
    {
        List<Product> priceList;
        for(auto i = 0u; i < desc.size(); ++i) {
            for(auto j = 0u; j < price.size(); ++j) {
                if(desc[i].code == price[j].code) {
                    unique_ptr<Product> temp(new Product(desc[i].desc, price[j].price));
                    temp->validate();
                    priceList += temp;
                }
            }
        }
        return priceList;
    }
}
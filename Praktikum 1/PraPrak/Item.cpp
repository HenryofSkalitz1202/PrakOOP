#include "Item.hpp"

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : stock(0), price(0), sold(0), serialNum(++totalItems) {}

Item::Item(int stock, int price) : stock(stock), price(price), sold(0), serialNum(++totalItems) {}

Item::Item(const Item& other) : stock(other.stock), price(other.price), sold(other.sold), serialNum(++totalItems) {}

Item::~Item() {}

int Item::getSerialNum() const {
    return serialNum;
}

int Item::getSold() const {
    return sold;
}

int Item::getPrice() const {
    return price;
}

void Item::addStock(int addedStock) {
    if (addedStock > 0) {
        stock += addedStock;
    }
}

void Item::sell(int soldStock) {
    if (soldStock > stock) {
        sold += stock;
        totalRevenue += stock * price;
        stock = 0;
    } else {
        sold += soldStock;
        totalRevenue += soldStock * price;
        stock -= soldStock;
    }
}

void Item::setPrice(int newPrice) {
    price = newPrice;
}
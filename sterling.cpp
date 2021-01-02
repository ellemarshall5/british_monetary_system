#include <iostream>
#include <array>
#include <string>
#include <cmath>
#include <sstream>
#include "sterling.h"
using namespace std;

/**
 * @brief Constructor that takes three parameters
 * @param pounds long
 * @param shills integer
 * @param pence integer
 */

Sterling::Sterling(long pounds, int shills, int pence) {
    set_pounds(pounds);
    set_shills(shills);
    set_pence(pence);
}

/**
 * @brief constructor setting up the old money system. takes a string of numbers, divides
 * them into substrings and converts those substrings back to ints. updates private data
 * members
 * @param old_system string being received
 */

Sterling::Sterling(const std::string &old_system) {

    old_system_ = old_system;

    if (old_system.find(".") != string::npos) {
        int position = old_system.find(".");
        int position2 = old_system.find(".", position) + 1;
        //get substring that contains the second sentence
        string pounds = old_system.substr(0, position);
        string shills = old_system.substr(position +1);
        string pence = old_system.substr(position2 +3);

        stringstream poundString(pounds);
        stringstream shillsString(shills);
        stringstream penceString(pence);

        int poundsNum;
        int shillsNum;
        int penceNum;

        poundString >> poundsNum;
        shillsString >> shillsNum;
        penceString >> penceNum;

        pounds_ = poundsNum;
        shills_ = shillsNum;
        pence_ = penceNum;
    }
}

/**
 * @brief method that takes one parameter. divides double into three parts, sets private data
 * members
 * @param decimal_pounds
 */
Sterling::Sterling(double decimal_pounds){
    int pounds = floor(decimal_pounds);
    double fractional_part = decimal_pounds - pounds;
    double decimal_shillings = fractional_part * 20;
    int shillings = floor(decimal_shillings);
    int pence = floor((decimal_shillings - shillings) * 12);

    set_pounds(pounds);
    set_shills(shillings);
    set_pence(pence);

}


/**
 * @brief setter that sets pounds.
 * @param pounds
 */
void Sterling::set_pounds(long pounds) {
    pounds_ = pounds;
}

/**
 * @brief setter that sets private data member shillings
 * @param shillings
 */
void Sterling::set_shills(int shillings) {

    while(shillings >= 20){
        pounds_++;
        shillings = shillings - 20;
    }
    shills_ = shillings;
}

/**
 * @brief setter for private data member pence
 * @param pence
 */
void Sterling::set_pence(int pence) {
    while(pence >= 12){
        shills_++;
        pence = pence -12;
    }
    set_shills(shills_);
    pence_ = pence;
}

/**
 * @brief getter for old_system_
 * @return old_system_
 */
const std::string & Sterling::get_old_system() const {

    return old_system_;
}

/**
 * @brief friend method that prints data out in an orderly fashion
 * @param os
 * @param sterling
 * @return os
 */
std::ostream &operator <<(std::ostream &os, const Sterling &sterling){
    os << "pounds: " << sterling.get_pounds() << " shills: " << sterling.get_shills()
        << " pence: " << sterling.get_pence();

    return os;
}

/**
 * @brief compares two objects for equality
 * @param rhs
 * @return true if data is a match
 */
bool Sterling::operator==(const Sterling &rhs) const {

    return (pounds_ == rhs.pounds_ && shills_ == rhs.shills_ && pence_ == rhs.pence_);
}

/**
 * @brief compares two objects for inequality
 * @param rhs
 * @return true if data is not a match
 */
bool Sterling::operator!=(const Sterling &rhs) const {

    return (pounds_ != rhs.pounds_ || shills_ != rhs.shills_ || pence_ != rhs.pence_);
}

/**
 * @brief converts decimal number to pounds, shills and pence
 * @return converted number
 */
float Sterling::decimal_pound() {
    float decimal_pound = pounds_ + shills_/20.0 + pence_/240.0;
    return decimal_pound;
}

/**
 * @brief adds to objects together
 * @param s2
 * @return sum of two objects
 */
Sterling Sterling::operator+(Sterling s2) const {
    double pounds = pounds_ + s2.pounds_;
    double shills = static_cast<double>(shills_) + static_cast<double>(s2.shills_);
    double pence = static_cast<double>(pence_) + static_cast<double>(s2.pence_);

    return Sterling(pounds, shills, pence);
}

/**
 * @brief subtracts an object from the other
 * @param s2
 * @return returns difference of two objects
 */
Sterling Sterling::operator-(Sterling s2) const {
    double pounds = pounds_ - s2.pounds_;
    double shills = static_cast<double>(shills_) - static_cast<double>(s2.shills_);
    double pence = static_cast<double>(pence_) - static_cast<double>(s2.pence_);

    return Sterling(pounds, shills, pence);
}
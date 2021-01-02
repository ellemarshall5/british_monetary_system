#ifndef STERLING_H_
#define STERLING_H_

#include <iostream>

// Global variable for poundsign
const unsigned char kPoundSign = static_cast<unsigned char>(156); // £

class Sterling
{
private:
    long pounds_;
    int shills_;
    int pence_;
    std::string old_system_; // 13.18.1

public:
    //constructors
    Sterling() : pounds_(0), shills_(0), pence_(0) {};
    Sterling(long pounds, int shills, int pence);
    Sterling(const std::string &old_system);
    Sterling(double decimal_pounds);

    //getters
    long get_pounds() const {return pounds_;}
    int get_shills() const {return shills_;}
    int get_pence() const {return pence_;}

    //setters
    void set_pounds(long pounds);
    void set_shills(int shillings);
    void set_pence(int pence);

    //others
    const std::string& get_old_system() const;
    friend  std::ostream& operator <<(std::ostream &os, const Sterling &sterling);
    bool operator == (const Sterling &rhs) const;
    bool operator != (const Sterling &rhs) const;
    float decimal_pound();
    Sterling operator + (Sterling s2) const;
    Sterling operator - (Sterling s2) const;
};

#endif /* !STERLING_H_ */

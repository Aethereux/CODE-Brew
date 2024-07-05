#ifndef VOUCHER_SYSTEM_H
#define VOUCHER_SYSTEM_H
#include <iostream>

using namespace std;

struct Voucher {
    string voucherCode;
    string value;
    string expiryDate;
    string status;

    // Constructor for Admins to use to create a new voucher
    // It makes creating voucher easier than manually accessing the attributes.
    // e.g Voucher voucher("CODEBREW10", "10", "2021-12-31", "active")
    // an instance of the Voucher struct is created with the given attributes.

    Voucher(string voucherCode, string value, string expiryDate, string status) 
    : voucherCode(voucherCode), value(value), expiryDate(expiryDate), status(status) {}
};

class VoucherSystem {
    private:
    // Private Variables
    
    public:
    // Methods
    Voucher createVoucher(string voucherCode, string value, string expiryDate, string status);
    void removeVoucher(Voucher &voucherCode); // Used a Ampersand to pass by reference to modify the voucher status
};



#endif
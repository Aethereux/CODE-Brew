#include "VoucherSystem.h"
#include <iostream>
#include <fstream>

using namespace std;

Voucher VoucherSystem::createVoucher(string voucherCode, string value, string expiryDate, string status) {
    Voucher newVoucher(voucherCode, value, expiryDate, status);
    return newVoucher;
}

void VoucherSystem::removeVoucher(Voucher &voucherCode) {
    // More code to remove voucher from database
    
}
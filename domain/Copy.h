#pragma once

class Copy 
{
public:
    explicit Copy(int inventoryNumber);
    bool isAvailable() const;
    void markAsBorrowed();
    void markAsReturned();
private:
    int inventoryNumber_;
    bool available_ = true;
};
#include "Singleton.h"

struct SingletonImpl {
    SingletonImpl() : value_(0) {}
    int value_;
};

Singleton::Singleton() : impl_(impl()) {}

Singleton::~Singleton() {}

SingletonImpl& Singleton::impl() {
    static SingletonImpl inst;
    return inst;
}

Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}

int& Singleton::get() {
    return impl_.value_;
}







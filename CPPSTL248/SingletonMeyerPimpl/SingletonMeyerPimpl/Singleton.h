#pragma once
#ifndef SINGLETON_H
#define SINGLETON_H

struct SingletonImpl; // declaración anticipada

class Singleton {
public:
    static Singleton& getInstance();
    int& get();

private:
    Singleton();
    Singleton( Singleton&) = delete;
    Singleton& operator=( Singleton&) = delete;
    ~Singleton();

    static SingletonImpl& impl();
    SingletonImpl& impl_; //  Referencia almacenada
};

#endif // SINGLETON_H








#include "boat.h"

#include <stdexcept>
#include <iostream>

namespace water
{
    static double checkLength(double length) {
        if (length > 0.0)
        {
            return length;
        }
        else
        {
            throw std::out_of_range("length must be positive");
        }
    }
     static int checkCapacity(int capacity) {
        if (capacity > 0)
        {
            return capacity;
        }
        else
        {
            throw std::out_of_range("capacity must be more than 0");
        }
    }
    Boat::Boat(const Boat &copy) 
      : m_constructedOn(copy.m_constructedOn), 
        m_length(copy.m_length), 
        m_capacity(copy.m_capacity), 
        m_brand(copy.m_brand)
      {
        std::cout << "Boat@" 
             << (void*) this 
             << " copied from " << (const void*) &copy 
             << std::endl;

      }
    Boat::Boat(int constructedOn, double length, const std::string &brand, int capacity)
        : m_constructedOn(constructedOn), m_length(checkLength(length)), m_brand(brand), m_capacity(capacity)
    {
        std::cout << "Boat at" 
             << (void*) this 
             << " from line " << m_constructedOn << " constructed." 
             << std::endl;
    }

    Boat::~Boat()
    {
        std::cout << "Boat at" 
             << (void*) this 
             << " from line " << m_constructedOn << " destructed." 
             << std::endl;
    }


    double Boat::length() const
    {
        return m_length;
    }

    void Boat::length(double length)
    {
        m_length=checkLength(length);
    }

    int Boat::capacity() const
    {
        return m_capacity;
    }

    void Boat::capacity(int capacity)
    {
        m_capacity=checkCapacity(capacity);
    }
}
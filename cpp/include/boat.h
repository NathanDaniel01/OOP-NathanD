#pragma once

#include <string>
#include <memory>

namespace water {
  class Boat {
//  ====== Private ======
      public: Boat(const Boat &copy);
      public: const int m_constructedOn;
      public: Boat(int constructedOn, double length, const std::string &brand, int capacity);
      public: double length() const;
      public: void length(double value);
      public: int capacity() const;
      public: void capacity(int value);
      public: ~Boat();
//  ====== Private ======
      private: std::string m_brand;
      private: double m_capacity;
      private: double m_length;
  };
  typedef std::shared_ptr < Boat > SPBoat;

}
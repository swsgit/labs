#include <iostream>

class MeterCent {
public:
  MeterCent(int m = 0, int c = 0) : meter(m), cent(c) { simplify(); }

public:
  inline void simplify() {
    meter += cent / 100;
    cent %= 100;
  }
  inline void setData(int m, int c) {
    meter = m;
    cent = c;
    simplify();
  }
  inline int getMeter() const { return meter; }
  inline int getCent() const { return cent; }

private:
  int meter;
  int cent;

public:
  /* Arithmetic */
  MeterCent &operator+=(const MeterCent rhs) {
    setData(getMeter() + rhs.getMeter(), getCent() + rhs.getCent());
    return *this;
  }
  friend MeterCent operator+(MeterCent lhs, const MeterCent &rhs) {
    lhs += rhs;
    return lhs;
  }
  MeterCent &operator-=(const MeterCent rhs) {
    setData(getMeter() - rhs.getMeter(), getCent() - rhs.getCent());
    return *this;
  }
  friend MeterCent operator-(MeterCent lhs, const MeterCent &rhs) {
    lhs -= rhs;
    return lhs;
  }
  MeterCent &operator*=(const MeterCent rhs) {
    setData(getMeter() * rhs.getMeter(), getCent() * rhs.getCent());
    return *this;
  }
  friend MeterCent operator*(MeterCent lhs, const MeterCent &rhs) {
    lhs *= rhs;
    return lhs;
  }
  MeterCent &operator/=(const MeterCent rhs) {
    setData(getMeter() / rhs.getMeter(), getCent() / rhs.getCent());
    return *this;
  }
  friend MeterCent operator/(MeterCent lhs, const MeterCent &rhs) {
    lhs /= rhs;
    return lhs;
  }
  MeterCent operator++() {
    setData(meter, cent++);
    simplify();
    return *this;
  }
  MeterCent operator++(int) {
    setData(meter, ++cent);
    return *this;
  }
  MeterCent operator--() {
    setData(meter, cent--);
    simplify();
    return *this;
  }
  MeterCent operator--(int) {
    setData(meter, --cent);
    return *this;
  }

  /* Compare */
  inline bool operator==(const MeterCent &rhs) {
    return (meter == rhs.getMeter()) && (cent == rhs.getCent());
  }
  inline bool operator!=(const MeterCent &rhs) { return !(*this == rhs); }
  inline bool operator<(const MeterCent &rhs) {
    return (meter < rhs.getMeter()) ||
           (meter == rhs.getMeter() && cent < rhs.getCent());
  }
  inline bool operator<=(const MeterCent &rhs) {
    return (meter < rhs.getMeter()) ||
           (meter == rhs.getMeter() && cent <= rhs.getCent());
  }
  inline bool operator>(MeterCent &rhs) { return rhs < *this; }
  inline bool operator>=(MeterCent &rhs) { return rhs <= *this; }

  /* IO */
  friend std::ostream &operator<<(std::ostream &os, const MeterCent &mc) {
    os << mc.getMeter() << " " << mc.getCent() << "\n";
    return os;
  }
};

int main() {
  MeterCent mc1(10, 230);
  MeterCent mc2(10, 230);
  std::cout << mc1;
  std::cout << (mc1 + mc2);
  std::cout << (mc1 - mc2);
  std::cout << (mc1 * mc2);
  std::cout << (mc1 / mc2);
  std::cout << (mc1 < mc2) << "\n";
  std::cout << (mc1 <= mc2) << "\n";
  std::cout << (mc1 > mc2) << "\n";
  std::cout << (mc1 >= mc2) << "\n";

  return 0;
}
/*
12 30
24 60
0 0
153 0
1 1
0
1
0
1
*/
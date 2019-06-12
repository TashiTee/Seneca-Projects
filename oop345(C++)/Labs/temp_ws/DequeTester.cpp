#include <iostream>
#include <string>
using namespace std;
#include "Deque.h"

class Name {
  string m_data;
public:
  Name(string S = "No Name") {
    m_data = S;
  }
  Name(const Name& N) {
    m_data = N.m_data;
  }
  Name& operator=(const Name& N) {
    m_data = N.m_data;
    return *this;
  }
  ostream& display(ostream& os = cout)const {
    return os << m_data;
  }
};
ostream& operator<<(ostream& os, const Name& N) {
  return N.display(os);
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const Deque<T>& Q) {
  for (size_t i = 0; i < Q.size(); i++) {
    os << Q[i] << " ";
  }
  return os;
}
int main() {
  Deque<double> Q;
  double v;
  Q.push_back(0.0);
  for ( v = 1.2; v < 5.0; v += 1.0) {
    Q.push_back(v);
  }
  for (;v < 10.0; v += 1.0) {
    Q.push_front(v);
  }
  cout << Q << endl;
  cout << Q.front() << endl;
  cout << Q.back() << endl;
  Q.pop_back();
  cout << Q.front() << endl;
  cout << Q.back() << endl;
  Q.pop_front();
  cout << Q.front() << endl;
  cout << Q.back() << endl;
  cout << Q << endl;
  Deque<Name> Qn;
  Qn.push_back(Name("Homer"));
  Qn.push_front(Name("Marge"));
  Qn.push_back(Name("Bart"));
  Qn.push_front(Name("Maggie"));
  Qn.push_back(Name("Lisa"));
  Qn.push_front(Name("Milhouse"));
  Qn.push_back(Name("Waylon"));
  cout << Qn << endl;
  cout << Qn.front() << endl;
  cout << Qn.back() << endl;
  Qn.pop_back();
  cout << Qn.front() << endl;
  cout << Qn.back() << endl;
  Qn.pop_front();
  cout << Qn.front() << endl;
  cout << Qn.back() << endl;
  cout << Qn << endl;
  return 0;
}
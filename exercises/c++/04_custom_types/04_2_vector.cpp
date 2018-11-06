#include <iostream>
#include <string>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

  class iterator {

      private:
          num* _element;
          std::size_t _position;
          std::size_t _size;
      public:
          iterator(num* elem, std::size_t position, std::size_t size) noexcept:
              _element{elem}, _position{position}, _size{size}
          {}
          iterator operator++(){
          
              if (_position < _size){
                _position++;
                _element++;
              }
              if (_position == _size)
                  _element = nullptr;
                
            return *this;
          }
          num& operator*() const {
          
            return *_element;
          }
          bool operator== (const iterator& that) const{
          
              if (_position == that._position)
                  if (_element == that._element)
                      return true;
            return false;
          }
          bool operator!= (const iterator& that) const{
          
              return !operator==(that);
          }
  };

 public:
  Vector(const std::size_t size) : elem{new num[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  std::size_t size() const { return _size; }

  num& operator[](const std::size_t i) { return elem[i]; }

  // try to comment this line and recompile
  const num& operator[](const std::size_t i) const { return elem[i]; }

  iterator begin(){
  
      return iterator{elem, 0U, _size};
  }
  iterator end(){
  
      return iterator{nullptr, _size, _size};
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555;
  rv[9] = -99.999;

  std::cout << rv << std::endl;
  std::cout << "Range besed for loop:" << std::endl;
  for (auto x : rv)
      std::cout << x << std::endl;

  return 0;
}

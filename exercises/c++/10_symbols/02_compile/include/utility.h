#ifndef _UTIL_H_
    #define _UTIL_H_

    #include <string>
    #include <algorithm>
    #include <iostream>

    inline std::string to_upper(const std::string& os){
      //extern int n = 0;
      static int n = 0;
      ++n;
      //const auto s = os;
      auto s = os;
      //std::trasnform(s.begin(), s.end(), s.begin(), ::toupper);
      std::transform(os.begin(), os.end(), s.begin(), ::toupper);
      //std::cout << "function " << __func_ << " has been called " << n << " times\n";
      std::cout << "function " << __func__ << " has been called " << n << " times\n";
      return s;
    }

    inline std::string to_lower(const std::string& os){
      //static auto s = os;
      auto s = os;
      //std::trasnform(s.begin(), s.end(), s.begin(), ::tolower);
      std::transform(s.begin(), s.end(), s.begin(), ::tolower);
      return s;
    }
#endif

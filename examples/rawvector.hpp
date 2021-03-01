// rawvector.h

#ifndef _RAWVECTOR_H_
#define _RAWVECTOR_H_

#include <string>
#include <vector>

class RawVector {
private:
  int               class_variable_{37};
  std::vector<uint16_t>  imgvec_;
  size_t            getFilesize(std::ifstream& ifs);
  bool              fromfile(std::string filename, std::vector<uint16_t>& vec);
  bool              tofile(std::string fiename, std::vector<uint16_t>& vec);

public:
  RawVector(std::string filename, size_t height, size_t width, size_t bitwidth);
  ~RawVector(void);
  uint16_t at(size_t idx);
  uint16_t at(size_t row, size_t col);
  size_t  size();
  bool save();
  bool saveas(std::string filename);

  const std::string     filename;
  const size_t     height;
  const size_t     width;
  const size_t     bitwidth;
};

#endif // _RAWVECTOR_H_


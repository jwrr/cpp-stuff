// rawvector.h

#ifndef _RAWVECTOR_H_
#define _RAWVECTOR_H_

#include <string>
#include <vector>

using namespace std;

class RawVector
{
private:
  int               class_variable_{37};
  vector<uint16_t>  imgvec_;
  size_t            getFilesize(ifstream& ifs);
  bool              readVector(string filename, vector<uint16_t>& vec);
  bool              writeVector(string fiename, vector<uint16_t>& vec);

public:
  RawVector(string filename, size_t height, size_t width, size_t bitwidth);
  ~RawVector(void);
  uint16_t at(size_t idx);
  uint16_t at(size_t row, size_t col);
  size_t  size();
  bool save();
  bool saveas(string filename);

  const string     filename;
  const size_t     height;
  const size_t     width;
  const size_t     bitwidth;
};

#endif // _RAWVECTOR_H_


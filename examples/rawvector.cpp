// ================================================

#include <iostream>
#include <fstream>
#include "rawvector.hpp"

template<typename TT>
RawVector<TT>::RawVector(std::string filename, size_t height, size_t width, size_t bitwidth) :
  filename(filename), height(height), width(width), bitwidth(bitwidth)
{
  bool success = fromfile(filename, imgvec_);
}


template<typename TT>
RawVector<TT>::~RawVector(void)
{
}


template<typename TT>
size_t  RawVector<TT>::getFilesize(std::ifstream& ifs)
{
  ifs.seekg(0, std::ios::end);
  size_t filesize=ifs.tellg();
  ifs.seekg(0, std::ios::beg);
  return filesize;
}


template<typename TT>
bool RawVector<TT>::fromfile(std::string filename, std::vector<TT>& vec)
{
  std::ifstream ifs(filename, std::ios::binary);
  if (!ifs) return false; // error
  size_t filesize = getFilesize(ifs);
  size_t vecsize  = filesize / sizeof(TT);
  vec.resize(vecsize);
  ifs.read((char *)vec.data(), filesize);
  return (vec.size()>0);
}


template<typename TT>
bool RawVector<TT>::tofile(std::string filename, std::vector<TT>& vec)
{
  std::ofstream ofs(filename);
  if (!ofs) return false; // error
  size_t bytesize = sizeof(TT) * vec.size();
  ofs.write((char *)vec.data(), bytesize);
  return true;
}


template<typename TT>
TT RawVector<TT>::at(size_t idx)
{
  return imgvec_.at(idx);
}


template<typename TT>
TT RawVector<TT>::at(size_t row, size_t col)
{
  return imgvec_.at(row*width+col);
}


template<typename TT>
size_t RawVector<TT>::size()
{
  return imgvec_.size();
}


template<typename TT>
bool RawVector<TT>::save()
{
  return tofile(filename, imgvec_);
}


template<typename TT>
bool RawVector<TT>::saveas(std::string filename)
{
  return tofile(filename, imgvec_);
}


// ============================================================================
// ============================================================================


#define print2(a,b) std::cout << a << " " << b << std::endl;
#define print4(a,b,c,d) std::cout << a << " " << b << " " << c << " " << d << std::endl;
#define hex(a) std::cout << std::hex << a << std::dec << " ";


int main()
{
  size_t w = 640;
  size_t h = 480;
  size_t expected_size = h * w;
  RawVector<uint16_t> raw1("bin.raw", 480, 640, 16);
  if (raw1.size()==0) {
    std::cout << "Error opening file '"  << raw1.filename << "'\n";
    return 1;
  } else if (raw1.size() != expected_size) {
    std::cout << "Error. Filesize = " << raw1.size() << " Expected size = " << expected_size << "\n";
    return 2;
  }
  
  std::cout << "Image Size = " << raw1.size() << " should be " << expected_size << std::endl;
  
  raw1.saveas("new.raw");
  
  print2("width =",raw1.width)
  
  for (int r=0; r<raw1.height; r++) {
    for (int c=0; c<raw1.width; c++) {
      hex(raw1.at(r,c))
    }
    std::cout << std::endl << std::endl;
  }
  
  return 0;
}


